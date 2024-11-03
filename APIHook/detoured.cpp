//////////////////////////////////////////////////////////////////////////////
//
//  Presence of this DLL (detoured.dll) marks a process as detoured.
//
//  Microsoft Research Detours Package, Version 2.1.
//
//  Copyright (c) Microsoft Corporation.  All rights reserved.
//


#include <windows.h>
#include "detoured.h"
#include "detours.h"
#include <tlhelp32.h> 
#include <mmsystem.h>
#include <Tchar.h>

#include <iostream>
#include <fstream>
using namespace std;
//#include <Winbase.h>

static HMODULE s_hDll;

DWORD hdsn;
DWORD pid;

MMRESULT (WINAPI *PFN_waveInOpen)(LPHWAVEIN phwi, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD dwCallback, DWORD dwCallbackInstance, DWORD fdwOpen )=waveInOpen;
MMRESULT (WINAPI *PFN_waveInClose)(HWAVEIN hwi )=waveInClose;
MMRESULT (WINAPI *PFN_waveOutOpen)(LPHWAVEOUT phwo, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD dwCallback, DWORD dwCallbackInstance, DWORD fdwOpen )=waveOutOpen;
MMRESULT (WINAPI *PFN_waveOutClose)(HWAVEOUT hwo )=waveOutClose;
MMRESULT (WINAPI *PFN_waveInPrepareHeader)(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh )=waveInPrepareHeader;
MMRESULT (WINAPI *PFN_waveOutWrite)(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh )=waveOutWrite;

MMRESULT WINAPI MyWaveInOpen(LPHWAVEIN phwi, UINT uDeviceID, LPWAVEFORMATEX pwfx, DWORD dwCallback, DWORD dwCallbackInstance, DWORD fdwOpen );
MMRESULT WINAPI MyWaveInClose ( HWAVEIN hwi );
MMRESULT WINAPI MyWaveOutOpen ( LPHWAVEOUT phwo, UINT uDeviceID, LPWAVEFORMATEX pwfx, DWORD dwCallback, DWORD dwCallbackInstance, DWORD fdwOpen );
MMRESULT WINAPI MyWaveOutClose ( HWAVEOUT hwo );
MMRESULT WINAPI MyWaveInPrepareHeader ( HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh );
MMRESULT WINAPI MyWaveOutWrite ( HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh );


BOOL (WINAPI *pGetVolumeInformation)(
LPCTSTR lpRootPathName,
LPTSTR lpVolumeNameBuffer,
DWORD nVolumeNameSize,
LPDWORD lpVolumeSerialNumber,
LPDWORD lpMaximumComponentLength,
LPDWORD lpFileSystemFlags,
LPTSTR lpFileSystemNameBuffer,
 DWORD nFileSystemNameSize
)=GetVolumeInformation;

BOOL WINAPI MyGetVolumeInformation(
LPCTSTR lpRootPathName,
LPTSTR lpVolumeNameBuffer,
DWORD nVolumeNameSize,
LPDWORD lpVolumeSerialNumber,
LPDWORD lpMaximumComponentLength,
LPDWORD lpFileSystemFlags,
LPTSTR lpFileSystemNameBuffer,
 DWORD nFileSystemNameSize
);



HMODULE WINAPI Detoured()
{
    return s_hDll;
}



BOOL WINAPI DllMain(HINSTANCE hinst, DWORD dwReason, LPVOID reserved)
{
    (void)reserved;

    if (dwReason == DLL_PROCESS_ATTACH) {
        s_hDll = hinst;
        DisableThreadLibraryCalls(hinst);
		DisableThreadLibraryCalls(hinst);
		OutputDebugString(_T("DllMain************\n"));
		DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)pGetVolumeInformation, MyGetVolumeInformation);
        if(DetourTransactionCommit() == NO_ERROR)
             OutputDebugString(_T("GetVolumeInformation detoured successfully"));
    }
    return TRUE;
}



BOOL WINAPI MyGetVolumeInformation(
LPCTSTR lpRootPathName,
LPTSTR lpVolumeNameBuffer,
DWORD nVolumeNameSize,
LPDWORD lpVolumeSerialNumber,
LPDWORD lpMaximumComponentLength,
LPDWORD lpFileSystemFlags,
LPTSTR lpFileSystemNameBuffer,
DWORD nFileSystemNameSize
)
{
	ifstream infile;
	infile.open(_T("hdsn.txt"),ios::in);
	if(!infile)
	{
		return GetVolumeInformation(
					lpRootPathName,
					lpVolumeNameBuffer,
					nVolumeNameSize,
					lpVolumeSerialNumber,
					lpMaximumComponentLength,
					lpFileSystemFlags,
					lpFileSystemNameBuffer,
					nFileSystemNameSize);
	}
	infile.seekg(0,ios::end);
	int len=infile.tellg();
	infile.seekg(0,ios::beg);
	char *text=new char[len+1];
	memset(text,0,len);
	if(infile.is_open())
	{
		infile.getline(text,len+1);
	}
	DWORD sn;
	sn=atol(text);


	//GetVolumeInformation(
	//				lpRootPathName,
	//				lpVolumeNameBuffer,
	//				nVolumeNameSize,
	//				lpVolumeSerialNumber,
	//				lpMaximumComponentLength,
	//				lpFileSystemFlags,
	//				lpFileSystemNameBuffer,
	//				nFileSystemNameSize);

	//LPDWORD lpw=NULL;
	//*lpw=sn;

	if(lpVolumeSerialNumber==NULL)
		lpVolumeSerialNumber=&sn;
	else
		*lpVolumeSerialNumber=sn;

	return TRUE;
}


void WINAPI SetSerialNumber(DWORD sn)
{
	hdsn=sn;
}


void WINAPI InjectToThread(HANDLE hThread)
{
	 DetourUpdateThread(hThread);
}

void WINAPI FunctionAttach()
{
	DetourAttach(&(PVOID&)pGetVolumeInformation,MyGetVolumeInformation);
	if(DetourTransactionCommit() == NO_ERROR)
             OutputDebugString(_T("GetVolumeInformation detoured successfully"));
}



/*
void WINAPI InitDll()
{
	HINSTANCE hinst=GetModuleHandle("APIHook");
	s_hDll = hinst;
    DisableThreadLibraryCalls(hinst);
	DisableThreadLibraryCalls(hinst);
	DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
}
*/


DWORD WINAPI GetProcessIdByName(LPCTSTR lpFilename)
{
    DWORD dwProcessId = 0;
	HANDLE hProcessSnap;
	PROCESSENTRY32 pe32;
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    if(hProcessSnap == INVALID_HANDLE_VALUE) return 0;
    if(!Process32First(hProcessSnap,&pe32)){CloseHandle(hProcessSnap);return 0;}
    do
    {
        _tcsupr(pe32.szExeFile);
        if(_tcsstr(pe32.szExeFile,lpFilename))
        {
            dwProcessId = pe32.th32ProcessID;
            break;
        }
    }
    while(Process32Next(hProcessSnap,&pe32));
    
    CloseHandle(hProcessSnap);
    
    return dwProcessId;
}

int GetProcessThreadList(DWORD th32ProcessID) //进程的ID
{ 
	HANDLE hThreadSnap; 
	THREADENTRY32 th32; 
	hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, th32ProcessID); 
	if (hThreadSnap == INVALID_HANDLE_VALUE) 
	{ 
		return 1; 
	} 
	th32.dwSize = sizeof(THREADENTRY32); 
	if (!Thread32First(hThreadSnap, &th32)) 
	{ 
		CloseHandle(hThreadSnap); 
		return 1; 
	} 

	do 
	{ 
		if (th32.th32OwnerProcessID == th32ProcessID) 
		{ 
			//printf("ThreadID: %ld\n", th32.th32ThreadID); //显示找到的线程的ID 
			HANDLE hThread=OpenThread(THREAD_QUERY_INFORMATION ,FALSE,th32.th32ThreadID);
			if(hThread==NULL)
			{
				DWORD error=GetLastError();
				//OutputDebugString("Thread=NULL\n");
			}
			else
			{
				DetourUpdateThread(hThread);
				//OutputDebugString("DetourUpdateThread\n");
			}
		} 
	}while(Thread32Next(hThreadSnap, &th32)); 
	CloseHandle(hThreadSnap); 
	return 0; 
} 


void WINAPI InjectToProcess(LPCTSTR lpFilename)
{
	//OutputDebugString("Bgein Inject\n");
	HINSTANCE hinst=GetModuleHandle(_T("APIHook"));
	s_hDll = hinst;
    DisableThreadLibraryCalls(hinst);
	DisableThreadLibraryCalls(hinst);
	DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
	DWORD pid=GetProcessIdByName(lpFilename);
	if(pid!=0)
		GetProcessThreadList(pid);

	DetourAttach(&(PVOID&)pGetVolumeInformation, MyGetVolumeInformation);
    if(DetourTransactionCommit() == NO_ERROR)
        OutputDebugString(_T("GetVolumeInformation detoured successfully\n"));
}
//
///////////////////////////////////////////////////////////////// End of File.

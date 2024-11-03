#include<windows.h>
#include "detoured.h"
#include "detours.h"




BOOL APIENTRY DllMain(HMODULE hDLL, DWORD Reason, LPVOID Reserved)
{
    switch(Reason)
    {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hDLL);
            DetourTransactionBegin();
            DetourUpdateThread(GetCurrentThread());

            //DetourAttach(&(PVOID&)pSend, MySend);
            ///if(DetourTransactionCommit() == NO_ERROR)
            //    OutputDebugString("send() detoured successfully");
            DetourTransactionBegin();
            DetourUpdateThread(GetCurrentThread());

 //           DetourAttach(&(PVOID&)pRecv, MyRecv);
//            if(DetourTransactionCommit() == NO_ERROR)
 //               OutputDebugString("recv() detoured successfully");
            break;
	}
	return TRUE;
}

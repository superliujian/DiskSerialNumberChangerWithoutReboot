# This is a simple Utility tool to inject any disk serial number
Generally there are a lot of tools which can change your disk serial number(eg ChangeDiskId.exe) but all of them need reboot. Under some scenario we don't we to reboot everythime, in this case, this tool is your choice.

## How to use
1. Download the compailed executable file
2. Copy all the files to the app path of the target software
3. Edit exefile.txt,  put the exe file name of the target software in that file
4. Edit hdsn.txt, put the deservied serial nubmer here
5. Double clikc to run "CreateWithDll.exe", this shell application will run your target application automatically and inject the serial number you put in hdsn.txt, so when the target application try to read your seiral number, if will read your value.

## How it works
It works by API Hook

## Benifits
1. Inject any disk serial number to target applicaiton
2. No reboot required, take affect immediately
3. Affect only target application, it's not impact others

# 这个一个简单的工具软件帮助您注入任何硬盘序列号到目标应用里

## 如何使用
1. 将本目录下的所有文件复制到你的包含可执行exe程序的目标文件夹
2. 编辑exefile.txt,   将里面的内容修改为你的可执行程序的文件 名
3. 修改hdsn.txt,里面的内容修改为你要的硬盘序列号。
4. 双击CreateWithDll.exe执行，程序会自动执行你的程序，并且所读取到的硬盘序列号为hdsn.txt里你自己设置的序列号

## 原理
API钩子

# 好处
1. 使目标软件读到指定硬盘序列号
2. 不用重启立即生效
3. 精准注入不影响其它软件（非全局修改）

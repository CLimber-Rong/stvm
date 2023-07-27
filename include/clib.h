#ifndef CLIB_H
#define CLIB_H

//需要实现的函数 
void VM_Exit();				//退出虚拟机程序 
void VM_Debug(char* msg);	//输出虚拟机的调试信息

//以下是方便开发虚拟机所定义的宏
//实现兼容的开发者无需理会
#define EXIT VM_Exit()
#define DEBUG(msg) VM_Debug(msg) 

#endif

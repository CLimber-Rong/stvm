#ifndef EXCEPTION
#define EXCEPTION

#include"String.hpp"
//异常处理的实现

String ExceptionMessage;

/*
	CATCH的使用方法：
	CATCH {
		//在这里写上捕捉异常的代码
	}
	THROW(message)用于抛出异常，异常信息为message
	ERROR是异常信息
*/ 

#define THROW(message) ExceptionMessage = message;	//THROW当中的message是char*
#define CATCH if(!ExceptionMessage.equals(String("")))
#define ERROR ExceptionMessage

#endif

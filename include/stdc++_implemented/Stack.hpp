/*
	Name: Stack.cpp
	Copyright: Apache 2.0
	Author: 瞿相荣 
	Date: 17/01/23 18:06
	Description: 栈库，基于stack.h
*/
#ifndef STACK_CPP
#define STACK_CPP

#include"stack.h"

template <typename ValueType>
class Stack {
	STACK* stack;
	public:
		Stack();								//构造函数 
		int clear();							//清空
		int destroy();							//销毁
		int empty();							//是否为空
		int size();								//元素个数
		ValueType* peek();							//获取栈顶元素
		int push(ValueType* data); 					//入栈
		ValueType* pop();							//出栈
		int traverse(STACK_VISIT visit); 		//从栈底到栈顶依次遍历，具体操作见stack.h 
};

Stack::Stack()
{
	stack = InitStack();
}

int Stack::clear()
{
	return ClearStack(stack);
}

int Stack::destroy()
{
	return DestroyStack(stack);
}

int Stack::empty()
{
	return StackEmpty(stack);
}

int Stack::size()
{
	return StackLength(stack);
}

ValueType* Stack::peek()
{
	return (ValueType*)GetTop(stack);
}

int Stack::push(ValueType* data)
{
	return PushStack(stack,(void*)data);
}

ValueType* Stack::pop()
{
	return (ValueType*)PopStack(stack,data);
}

int Stack::traverse(STACK_VISIT visit)
{
	return StackTraverse(stack,visit);
}

#endif

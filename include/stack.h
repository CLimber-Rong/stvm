/*
	Name: stack.h
	Copyright: Apache License 2.0
	Author: ������
	Date: 23/10/22 21:44
	Description: C����ջ�⣬�汾1.0.0.0
*/


#ifndef STACK_H
#define STACK_H

#include"lib.h"

typedef int (*STACK_VISIT)(void*);					//�����ĺ���ָ��ӿ�

typedef struct _STACK_ELEMENT_TYPE {					//ջ��Ԫ�أ�����˫������ʽ�ṹ
	void* data;									//������
	struct _STACK_ELEMENT_TYPE* next;			//��һ��
	struct _STACK_ELEMENT_TYPE* prev;			//��һ��
} stack_node;

typedef struct {
	stack_node* top;								//ջ��
	stack_node* base;								//ջ��
	int length;										//����
} STACK;

STACK* InitStack();									//��ʼ��һ��ջ���ɹ�����ջָ�룬���򷵻�NULL
int ClearStack(STACK* stack);						//���һ��ջ���ɹ�����1�����򷵻�0
int DestroyStack(STACK* stack);						//����һ��ջ���ɹ�����1�����򷵻�0
int StackEmpty(STACK* stack);						//�ж�ջ�Ƿ�Ϊ�գ����򷵻�1�����򷵻�0��������-1
int StackLength(STACK* stack);						//����ջ�ĳ��ȣ�������-1
void* GetTop(STACK* stack);							//����ջ��Ԫ�����ݣ�������NULL
int PushStack(STACK* stack,void* data);				//��ջ ���ɹ�����1�����򷵻�0
void* PopStack(STACK* stack);						//��ջ�����س�ջ�����ݣ����󷵻�NULL
int StackTraverse(STACK* stack,STACK_VISIT visit);	//��ջ�׵�ջ�����ε���visit����
//Ҫ��visit��������Ϊ���ݣ�visit����1������ɹ�������ʼ������һ��Ԫ��
//����0������ʧ�ܣ�StackTraverse����ֹ�����˳�
//���سɹ������Ԫ�ظ���

STACK* InitStack() {
	STACK* stack = (STACK*)calloc(1,sizeof(STACK));
	stack->base = (stack_node*)calloc(1,sizeof(stack_node));
	if(stack->base==NULL) {
		return NULL;
	}
	stack->top = stack->base;
	stack->length = 0;
	return stack;
}

int ClearStack(STACK* stack) {
	if(stack==NULL) {
		return 0;
	}
	stack_node* tmp = stack->top->prev;
	while(stack->length!=0) {
		free(tmp->next);
		tmp = tmp->prev;
		stack->length--;
	}
	stack->top = stack->base;
	return 1;
}

int DestroyStack(STACK* stack) {
	if(ClearStack(stack)==0) {
		return 0;
	}
	free(stack);
	return 1;
}

int StackEmpty(STACK* stack) {
	if(stack==NULL) {
		return -1;
	}
	if(stack->length==0) {
		return 1;
	} else {
		return 0;
	}
}

int StackLength(STACK* stack) {
	if(stack==NULL) {
		return -1;
	}
	return stack->length;
}

void* GetTop(STACK* stack) {
	if(stack==NULL) {
		return NULL;
	}
	return stack->top->data;
}

int PushStack(STACK* stack,void* data) {
	if(stack==NULL) {
		return 0;
	}
	stack_node* tmp = (stack_node*)calloc(1,sizeof(stack_node));
	if(tmp==NULL) {
		return 0;
	}
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = stack->top;
	stack->top->next = tmp;
	stack->top = tmp;
	stack->length++;
	return 1;
}

void* PopStack(STACK* stack) {
	if(stack==NULL) {
		return NULL;
	}
	if(stack->length==0) {
		return NULL;
	}
	void* data = stack->top->data;
	stack_node* tmp = stack->top->prev;
	free(stack->top);
	stack->top = tmp;
	stack->length--;
	return data;
}

int StackTraverse(STACK* stack,STACK_VISIT visit) {
	if(stack==NULL) {
		return 0;
	}
	stack_node* tmp = stack->base->next;
	int i;
	for(i=0; i<(stack->length); i++) {
		if(visit(tmp->data)==0) {
			break;
		}
		tmp = tmp->next;
	}
	return i;
}

#endif


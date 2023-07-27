/*
	Name: strie.h
	Copyright: Apache 2.0 License
	Author: ������
	Date: 25/10/22 08:22
	Description: C�����ֵ����⣨��֧����ͨASCII��洢�����汾1.0.0.0
*/


#ifndef STRIE_H
#define STRIE_H

#include"lib.h"

typedef int (*TRIE_VISIT)(void*);							//�����ĺ���ָ��ӿ�

typedef struct _STRIE_NODE_TYPE {
	void* data;				//������
	int isexist;			//�Ƿ���ڣ�����Ϊ1��������Ϊ0
	struct _STRIE_NODE_TYPE* child[128];
} STRIE;

STRIE* InitTrie();											//��ʼ�������ɹ����ص�ַ��ʧ�ܷ���NULL
int SetTrieKeyVal(STRIE* trie,char* key,void* val);			//���ü�-ֵ���ɹ�����1��ʧ�ܷ���0�������ô˽ӿڴ�����-ֵ�͸������м�-ֵ
int DelTrieKeyVal(STRIE* trie,char* key);					//ɾ����-ֵ���ɹ�����1��ʧ�ܷ���0
void* GetTrieKeyVal(STRIE* trie,char* key);					//���ݼ���û��ֵ���ɹ�����ֵ��ʧ�ܷ���NULL��
//����NULLʱ���ų��������ָ�뱾���͵���NULL��
//�����TrieExistKeyVal()�ӿ��ж�
int TrieExistKeyVal(STRIE* trie,char* key);					//��-ֵ�Ƿ���ڣ������򷵻�1���������򷵻�0
int ClearTrie(STRIE* trie);									//������м�-ֵ���ɹ�����1��ʧ�ܷ���0
int DestroyTrie(STRIE* trie);								//���������ɹ�����1��ʧ�ܷ���0
int TrieEmpty(STRIE* trie);									//���Ƿ�Ϊ�գ����򷵻�1�����򷵻�0�����󷵻�-1
int TrieTraverse(STRIE* trie,TRIE_VISIT visit);				//����������Ԫ�����ε���visit����
//Ҫ��visit��������Ϊ���ݣ�visit����1������ɹ�������ʼ������һ��Ԫ��
//����0������ʧ�ܣ�StackTraverse����ֹ�����˳�
//���سɹ������Ԫ�ظ���
STRIE* InitTrie()
{
	STRIE* result = (STRIE*)calloc(1,sizeof(STRIE));
//	if(result==NULL){
//		return NULL;										//����ע�͸��㿴����ϸ���һ��Ϊʲô
//	}
	return result;											//�����������Ҳ�÷���NULL���ɴ�ֱ�ӷ���
}

int SetTrieKeyVal(STRIE* trie,char* key,void* val)
{
	if(trie==NULL) {
		return 0;
	}
	int i;
	for(i=0; i<strlen(key); i++) {
		if(trie->child[key[i]]==NULL) {
			trie->child[key[i]] = InitTrie();
			if(trie->child[key[i]]==NULL) {
				//����ڴ���仹��������
				return 0;
			}
		}
		trie = trie->child[key[i]];
	}
	trie->isexist = 1;
	trie->data = val;
	return 1;
}

int DelTrieKeyVal(STRIE* trie,char* key)
{
	int i,j;
	if(trie==NULL) {
		return 0;
	}
	STACK* stack = InitStack();
	if(stack==NULL) {
		return 0;
	}
	for(i=0; i<strlen(key); i++) {
		if(trie->child[key[i]]==NULL) {
			return 0;
		}
		if(PushStack(stack,trie)==0) {
			return 0;
		}
		trie = trie->child[key[i]];
	}
	if(trie->isexist==0) {
		return 0;
	}

	trie->isexist = 0;

	while(StackEmpty(stack)==0) {
		STRIE* tmp = (STRIE*)GetTop(stack);
		int flag = 0;
		for(i=0; i<128; i++) {
			if((tmp->child[i]!=NULL)||(tmp->isexist==1)) {
				//����ӽڵ��м�-ֵ�򱾽ڵ��Ѿ��д����ݵĻ�
				flag = 1;
			}
		}
		if(flag==1) {
			break;
		} else {
			free(tmp);
			PopStack(stack);
		}
	}
	if(DestroyStack(stack)==0) {
		return 0;
	}
	return 1;
}

void* GetTrieKeyVal(STRIE* trie,char* key)
{
	int i;
	if(trie==NULL) {
		return 0;
	}
	for(i=0; i<strlen(key); i++) {
		if(trie->child[key[i]]==NULL) {
			return NULL;
		}
		trie = trie->child[key[i]];
	}
	if(trie->isexist==0) {
		return NULL;
	}
	return trie->data;
}

int TrieExistKeyVal(STRIE* trie,char* key)
{
	if(trie==NULL) {
		return 0;
	}
	int i;
	for(i=0; i<strlen(key); i++) {
		if(trie->child[key[i]]==NULL) {
			return 0;
		}
		trie = trie->child[key[i]];
	}
	return trie->isexist;
}

int ClearTrie(STRIE* trie)
{
	STACK* stack = InitStack();
	if(trie==NULL||stack==NULL) {
		return 0;
	}
	PushStack(stack,trie);
	while(StackEmpty(stack)==0) {
		STRIE* tmp = (STRIE*)PopStack(stack);
		STRIE** tmp2 = tmp->child;
		if(tmp!=NULL) {
			if(tmp!=trie)	free(tmp);
			for(int i=0; i<128; i++) {
				PushStack(stack,tmp2[i]);
			}
		}
	}
	DestroyStack(stack);
	return 1;
}

int DestroyTrie(STRIE* trie)
{
	if(trie==NULL) {
		return 0;
	}
	ClearTrie(trie);
	free(trie);
	return 1;
}

int TrieEmpty(STRIE* trie)
{
	int i;
	if(trie==NULL) {
		return -1;
	}
	for(i=0; i<128; i++) {
		if(trie->child[i]!=NULL) {
			break;
		}
	}
	if(i!=128) {
		return 0;
	}
	return 1;
}

int TrieTraverse(STRIE* trie,TRIE_VISIT visit)
{
	STACK* stack = InitStack();
	if(stack==NULL||trie==NULL) {
		return 0;
	}

	PushStack(stack,trie);
	int i=0;
	while(StackEmpty(stack)==0) {
		trie = (STRIE*)PopStack(stack);
		if(trie!=NULL) {
			int j;
			for(j=0; j<128; j++) {
				PushStack(stack,trie->child[j]);
			}
			if(trie->isexist==1) {
				if(visit(trie->data)==0) {
					break;
				}
			}
		}
		i++;
	}
	DestroyStack(stack);
	return i;
}



#endif

/*
	Name: StringMap.cpp
	Copyright: Apache 2.0
	Author: 瞿相荣
	Date: 18/01/23 19:14
	Description: 字符串map
*/

#ifndef STRINGMAP_CPP
#define STRINGMAP_CPP

#include"strie.h"
#include"String.hpp"

template <typename T>
class StringMap {
		STRIE* map;
	public:
		StringMap();							//构造方法
		int put(String s, T* data); 			//设置键值
		int del(String s, T* data);			//删除键值
		T* get(String s);					//获取值
		bool containsKey(String s);				//是否存在该键
		int clear();							//清空
		int destroy();							//销毁
		bool empty();							//是否为空
		int traverse(TRIE_VISIT visit);			//遍历
};

template <typename T>
StringMap<T>::StringMap() {
	map = InitTrie();
}

template <typename T>
int StringMap<T>::put(String s, T* data) {
	char* tmp = (char*)calloc(s.length(), sizeof(char));
	s.c_arr(tmp);
	return SetTrieKeyVal(map, (unsigned char*)tmp, s.length(), (void*)data);
}

template <typename T>
int StringMap<T>::del(String s, T* data) {
	char* tmp = (char*)calloc(s.length(), sizeof(char));
	s.c_arr(tmp);
	return DelTrieKeyVal(map, (unsigned char*)tmp, s.length());
}

template <typename T>
T* StringMap<T>::get(String s) {
	char* tmp = (char*)calloc(s.length(), sizeof(char));
	s.c_arr(tmp);
	return (T*)GetTrieKeyVal(map, (unsigned char*)tmp, s.length());
}

template <typename T>
bool StringMap<T>::containsKey(String s) {
	char* tmp = (char*)calloc(s.length(), sizeof(char));
	s.c_arr(tmp);
	return TrieExistKeyVal(map, (unsigned char*)tmp, s.length());
}

template <typename T>
int StringMap<T>::clear() {
	return ClearTrie(map);
}

template <typename T>
int StringMap<T>::destroy() {
	return DestroyTrie(map);
}

template <typename T>
bool StringMap<T>::empty() {
	return TrieEmpty(map);
}

template <typename T>
int StringMap<T>::traverse(TRIE_VISIT visit) {
	return TrieTraverse(map, visit);
}

#endif

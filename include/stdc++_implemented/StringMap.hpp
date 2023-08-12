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

template <typename ValueType>
class StringMap
{
		STRIE* map;
	public:
		StringMap();							//构造方法
		int put(String s, ValueType* data); 			//设置键值
		int del(String s, ValueType* data);			//删除键值
		ValueType* get(String s);					//获取值
		bool containsKey(String s);				//是否存在该键
		int clear();							//清空
		int destroy();							//销毁
		bool empty();							//是否为空
		int traverse(TRIE_VISIT visit);			//遍历
};

template <typename ValueType>
StringMap<ValueType>::StringMap()
{
	map = InitTrie();
}

template <typename ValueType>
int StringMap<ValueType>::put(String s, ValueType* data)
{
	return SetTrieKeyVal(map, s.c_arr(), (void*)data);
}

template <typename ValueType>
int StringMap<ValueType>::del(String s, ValueType* data)
{
	return DelTrieKeyVal(map, s.c_arr(), (void*)data);
}

template <typename ValueType>
ValueType* StringMap<ValueType>::get(String s)
{
	return (ValueType*)GetTrieKeyVal(map, s.c_arr());
}

template <typename ValueType>
bool StringMap<ValueType>::containsKey(String s)
{
	return TrieExistKeyVal(s.c_arr());
}

template <typename ValueType>
int StringMap<ValueType>::clear()
{
	return ClearTrie(map);
}

template <typename ValueType>
int StringMap<ValueType>::destroy()
{
	return DestroyTrie(map);
}

template <typename ValueType>
bool empty()
{
	return TrieEmpty(map);
}

template <typename ValueType>
int StringMap<ValueType>::traverse(TRIE_VISIT visit)
{
	return TrieTraverse(map, visit);
}

#endif

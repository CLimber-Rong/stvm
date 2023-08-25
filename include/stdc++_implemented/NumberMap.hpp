/*
	Name: NumberMap.hpp
	Copyright: Apache 2.0
	Author: CLimber-Rong
	Date: 23/08/23 14:20
	Description: 整数map
*/

#ifndef NUMBERMAP_HPP
#define NUMBERMAP_HPP

#include"strie.h"
/*
 * 简单讲一下原理
 * NumberMap基于StringMap实现
 * 将整数转为四个字节的char数组，再转成字符串
 * 最后交给StringMap存储
 */

//这个库基于StringMap，不需要开发者实现

template<typename T>
class NumberMap {
		STRIE* map;
	public:
		NumberMap() {
			map = InitTrie();
		}
		int put(int s, T* data) { 			//设置键值
			return SetTrieKeyVal(map, (unsigned char*)&s, sizeof(int), (void*)data);
		}
		int del(int s, T* data) {			//删除键值
			return DelTrieKeyVal(map, (unsigned char*)&s, sizeof(int), (void*)data);
		}
		T* get(int s) {					//获取值
			return (T*)GetTrieKeyVal(map, (unsigned char*)&s, sizeof(int));
		}
		bool containsKey(int s) {				//是否存在该键
			return TrieExistKeyVal((unsigned char*)&s, sizeof(int));
		}
		int clear() {							//清空
			return ClearTrie(map);
		}
		int destroy() {							//销毁
			return DestroyTrie(map);
		}
		bool empty() {							//是否为空
			return TrieEmpty(map);
		}
		int traverse(TRIE_VISIT visit) {			//遍历
			return TrieTraverse(map, visit);
		}
};

#endif
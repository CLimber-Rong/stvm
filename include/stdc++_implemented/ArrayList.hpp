/*
	Name: ArrayList
	Copyright: Apache 2.0
	Author: CLimber-Rong
	Date: 28/07/23 17:10
	Description: 使用vector实现
*/

#ifndef ARRAYLIST
#define ARRAYLIST

#include"vector"

using namespace std;

template <typename T>
class ArrayList {
		vector<T>* list;
	public:
		ArrayList();			//创建一个空列表
		ArrayList(int size);	//创建size个元素的列表
		void add(T value);		//末尾添加值
		void insert(int index, T value);	//将value插入到[index]
		void erase(int index);	//删除[index]
		T at(int index);		//获取[index]
		bool empty();	//判断是否为空
		void clear();	//清楚列表
		int size();	//获得元素个数
};

template <typename T>
ArrayList<T>::ArrayList() {
	list = new vector<T>();
}

template <typename T>
ArrayList<T>::ArrayList(int size) {
	list = new vector<T>(size);
}

template <typename T>
void ArrayList<T>::add(T value) {
	list->push_back(value);
}

template <typename T>
void ArrayList<T>::insert(int index, T value) {
	list->insert(list->begin()+index, value);
}

template <typename T>
void ArrayList<T>::erase(int index) {
	list->erase(index);
}

template <typename T>
T ArrayList<T>::at(int index) {
	return list->at(index);
}

template <typename T>
bool ArrayList<T>::empty() {
	return list->empty();
}

template <typename T>
void ArrayList<T>::clear() {
	list->clear();
}

template <typename T>
int ArrayList<T>::size() {
	return list->size();
}

#endif

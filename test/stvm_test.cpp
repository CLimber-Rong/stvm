/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/09/23 13:54
	Description: 
*/

#include<iostream>

#include"ArrayList.hpp"
#include"NumberMap.hpp"
#include"Stack.hpp"
#include"String.hpp"
#include"StringMap.hpp"
#include"DataType.hpp"

#include"Ast.hpp"

using namespace stamon::ast;
using namespace stamon::datatype;

int main() {
	cout << "LIB TEST" << endl;
	cout << "--ARRAYLIST--" << endl;
	ArrayList<int> list;
	list.add(114);
	list.add(514);
	list.insert(1, 1919810);
	for(int i=0; i<3; i++) {
		cout<< list.at(i) << endl;
	}
	cout<<"--MAP--"<<endl;
	StringMap<int> map1;
	NumberMap<int> map2;
	int a=666,b=888;
	map1.put(String((char*)"Hello world!"), &a);
	map1.put(String((char*)"Hello STVM!"), &b);
	cout << *map1.get((char*)"Hello world!") << endl;
	int c=514, d=810;
	map2.put(114, &c);
	map2.put(1919, &d);
	cout << *map2.get(1919) << endl;

	cout<<endl<<endl;

    cout << "AST TEST" << endl;
    AstAnonClass* cls = new AstAnonClass(new ArrayList<AstNode*>());
    ArrayList<AstNode*>* list2 = new ArrayList<AstNode*>();
    list2->add((AstNode*)cls);
    AstProgram program(list2);

	cout<<endl<<endl;

	cout << "DATATYPE TEST" << endl;

	DataType* dt = (DataType*)new FloatType(114.514);
	cout << cast_class(FloatType, *dt).getVal() << endl;

}
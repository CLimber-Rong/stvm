/*
	Name: MethodType.cpp
	Copyright: Apache 2.0
	Author: CLimber-Rong
	Date: 14/08/23 11:57
	Description:
    * 在STVM中，方法本身也是一个值，它对应的数据类型就是MethodType
    * 这里就写上了MethodType的定义
*/

#ifndef METHODTYPE_CPP
#define METHODTYPE_CPP

#include"DataType.hpp"
#include"Ast.hpp"

namespace stamon {
	namespace datatype {
		class MethodType : public DataType {
				ast::AstAnonMethod* val;
			public:
				MethodType(ast::AstAnonMethod* value) : DataType(MethodTypeID) {
					val = value;
				}
				virtual ast::AstAnonMethod* getVal() {
					return val;
				}
		};
	}
}

#endif
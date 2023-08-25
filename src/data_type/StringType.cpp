/*
	Name: StringType.cpp
	Copyright: Apache 2.0
	Author: CLimber-Rong
	Date: 14/08/23 10:10
	Description: 字符串类型的定义
*/

#ifndef STRINGTYPE_CPP
#define STRINGTYPE_CPP

#include"DataType.hpp"
#include"String.hpp"

namespace stamon {
	namespace datatype {
		class StringType : public DataType {
				String val;
			public:
				StringType(String value) : DataType(StringTypeID) {
					val = value;
				}
				virtual String getVal() {
					return val;
				}
		};
	}
}

#endif
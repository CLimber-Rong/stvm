/*
	Name: clib.h
	Copyright: Apache 2.0
	Author: CLimber-Rong
	Date: 12/08/23 23:24
	Description: 一些杂糅的库定义
*/

#ifndef CLIB_H
#define CLIB_H

/*由于代码经常涉及到基类转派生类，所以我编写了这个可以直接转换的宏*/
/*
 * 这个宏的用法是：
 * dst = cast_class(转换后的类型,需要转换的值)
 */
#define cast_class(T, value) (*(T*) (& (value) ))

#endif

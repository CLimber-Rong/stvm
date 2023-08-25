<!--
 * @Name: 
 * @Copyright: 
 * @Author: 
 * @Date: 12/08/23 23:24
 * @Description: 
-->
# Stamon2虚拟机语法树概述

* 版本1.0.0.0

### 前言
Stamon2的虚拟机为Stamon2乃至其他语言诞生。

### 基本定义
1. Stamon2的虚拟机名为StamonVM
2. StamonVM是弱类型虚拟机，字节码为语法树，支持面对对象
3. 一个语法树节点的子节点有**无子节点**，**单子节点**，**双子节点**，**多子节点**三个类型（判断依据是这个语法树节点的子节点最多时的数量）
4. 一个语法树节点的定义应为：【节点描述】，【无/单/双/多子节点】【子节点名】（其中子节点名会列出所有可能的子节点）

### StamonVM的语法树定义

#####  AstNode
语法树的节点基类，以下所有节点皆继承该类

#####  Program
语法树根节点，多子节点DefClass

#####  DefClass
定义类的节点，双子节点IDENTIFIER，AnonClass

#####  AnonClass
匿名类的节点，每个对象都是表达式，多子节点Expression

#####  AnonMethod
匿名方法的节点，单子节点Block

#####  Block
代码块，多子节点IfStatement，WhileStatement，ForStatement，ReturnStatement，SFN，Expression

#####  CompoundBlock
循环语句的代码块，多子节点IfStatement，WhileStatement，ForStatement，ReturnStatement，SFN，Expression，Break

#####  Break
循环中的退出语句，无子节点

#####  IfStatement
if语句，多子节点Expression，CompoundBlock

#####  WhileStatement
while语句，多子节点Expression，CompoundBlock

#####  ForStatement
for语句，多子节点IDENTIFIER，Expression，CompoundBlock

#####  ReturnStatement
返回语句，单子节点Expression

#####  SFN
~~So F**k NVIDIA!~~ Stamon For Native，即虚拟机调用外部库的语句，双子节点IDENTIFIER

#####  Expression
表达式语句，多子节点ClassMember，Expression，Binary

#####  LeftValue
类成员节点，多子节点IDENTIFIER，LeftPostfix

#####  LeftPostfix
取下标节点，单子节点IDENTIFIER，Expression

#####  Binary
双目运算符节点，双子节点Binary，Unary

#####  Unary:
单目运算符，多子节点Unary，IDENTIFIER，NUMBER，STRING，NULL，Postfix

#####  Postfix:
后缀运算符，单子结点Expression，IDENTIFIER

#####  IDENTIFIER
标识符，无子节点

#####  NUMBER
数字字面量，无子节点

#####  STRING
字符串字面量，无子节点

####   NULL
null字面量，无子结点

#####  ArrayLiteral
数组字面量，单子节点Expression

#####  ListLiteral
列表字面量，多子节点Expression
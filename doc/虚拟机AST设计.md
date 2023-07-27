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

##### AstNode
语法树的节点基类，以下所有节点皆继承该类

##### 1. Program
语法树根节点，多子节点DefClass

##### 2.DefObj
定义对象的节点，多子节点IDENTIFIER，DefClass，DefVar，DefMethod

##### 3. DefClass
定义类的节点，多子节点DefObjss

##### 4. DefMethod
定义方法的节点，单子节点Block

##### 5. Block
代码块，多子节点IfStatement，WhileStatement，ForStatement，ReturnStatement，SFN，DefObj，Expression

##### 6. CompoundBlock
循环语句的代码块，多子节点IfStatement，WhileStatement，ForStatement，ReturnStatement，SFN，DefObj，Expression，Break

##### 7. Break
循环中的退出语句，无子节点

##### 8. IfStatement
if语句，多子节点Expression，CompoundBlock

##### 9. WhileStatement
while语句，多子节点Expression，CompoundBlock

##### 10. ForStatement
for语句，多子节点IDENTIFER，Expression，CompoundBlock

##### 11. ReturnStatement
返回语句，单子节点Expression

##### 12. SFN
~~So F**k NVIDIA!~~ Stamon For Native，即虚拟机调用外部库的语句，双子节点IDENTIFIER

##### 13. Expression
表达式语句，多子节点ClassMember，Element，Expression，LogicOR

##### 14. ClassMember
类成员节点，多子节点ClassMember，Element

##### 15. Element
取下标节点，双子节点IDENTIFIER，Expression

#####

**接下来是运算符节点的定义，定义方式为：**

<br>

**节点名+可能的子节点名**

> 运算符节点的定义不加以描述，请结合节点名和bnf.txt理解

##### 16. LogicOR:
LogicAND，LogicOR

##### 17. LogicAND:
BitOR，LogicAND

##### 18. BitOR:
BitXOR，BitOR

##### 19. BitXOR:
BitAND，BitXOR

##### 20. BitAND:
EqualCompare，BitAND

##### 21. Equality:
Relational，Equality

##### 22, Relational:
Shift，Relational

##### 23. Shift:
Additive，Shift

##### 24. Additive:
Mult，Additive

##### 25. Mult:
Unary，Mult

##### 26. Unary:
Unary，Quark，Postfix

##### 27. Postfix:
Postfix，Expression，IDENTIFIER
//这个节点的定义比较复杂，将会在更详细的文档中叙述

##### 28. Quark
Expression，IDENTIFIER，NUMBER，STRING，ArrayLiteral，ListLiteral

##### 29. IDENTIFIER
标识符，无子节点

##### 30. NUMBER
数字字面量，无子节点

##### 31. STRING
字符串字面量，无子节点

##### 32. ArrayLiteral
数组字面量，多子节点Expression

##### 33. ListLiteral
列表字面量，单子节点Expression
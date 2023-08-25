/*
    Name: CodeLogicAst.cpp
    Copyright: Apache 2.0
    Author: CLimber-Rong
    Date: 28/07/23 15:45
    Description: 在这里写代码逻辑（如函数、流程控制等）节点的定义
*/

#ifndef CODELOGICAST_CPP
#define CODELOGICAST_CPP

#include "Ast.hpp"

namespace stamon {
	namespace ast {
		class AstProgram : public AstNode {

			public:

				AstProgram(ArrayList<AstNode*>* defClass) : AstNode() {
					children = defClass;
				}
				virtual int getType() {
					return AstProgramType;
				}
		};
		class AstDefClass : public AstNode {

			public:

				AstDefClass(AstIdentifier* iden, AstAnonClass* object_class) : AstNode() {
					children->add(iden);
					children->add(object_class);
				}
				virtual int getType() {
					return AstDefClassType;
				}
		};
		class AstAnonClass : public AstNode {

			public:

				AstAnonClass(ArrayList<AstNode*>* expr) : AstNode() {
					children = expr;
				}
				virtual int getType() {
					return AstAnonClassType;
				}
		};
		class AstAnonMethod : public AstNode {

			public:

				AstAnonMethod(AstBlock* block) : AstNode() {
					children->add(block);
				}
				virtual int getType() {
					return AstAnonMethodType;
				}
		};
		class AstBlock : public AstNode {

			public:

				AstBlock(ArrayList<AstNode*>* statements) : AstNode() {
					children = statements;
				}
				virtual int getType() {
					return AstBlockType;
				}
		};
		class AstCompoundBlock : public AstNode {

			public:

				AstCompoundBlock(ArrayList<AstNode*>* statements) : AstNode() {
					children = statements;
				}
				virtual int getType() {
					return AstCompoundBlockType;
				}
		};
		class AstIfStatement : public AstNode {

			public:

				AstIfStatement(AstExpression* expr, AstCompoundBlock* block_if) : AstNode() {
					children->add(expr);
					children->add(block_if);
				}
				AstIfStatement(AstExpression* expr, AstCompoundBlock* block_if, AstCompoundBlock* block_else) : AstNode() {
					children->add(expr);
					children->add(block_if);
					children->add(block_else);
				}
				virtual int getType() {
					return AstIfStatementType;
				}
		};
		class AstWhileStatement : public AstNode {

			public:

				AstWhileStatement(AstExpression* expr, AstCompoundBlock* block_while) : AstNode() {
					children->add(expr);
					children->add(block_while);
				}
				virtual int getType() {
					return AstWhileStatementType;
				}
		};
		class AstForStatement : public AstNode {

			public:

				AstForStatement(AstIdentifier* iden, AstExpression* expr, AstCompoundBlock* block_for) : AstNode() {
					children->add(iden);
					children->add(expr);
					children->add(block_for);
				}
				virtual int getType() {
					return AstForStatementType;
				}
		};
		class AstReturnStatement : public AstNode {

			public:

				AstReturnStatement(AstExpression* expr) : AstNode() {
					children->add(expr);
				}
				virtual int getType() {
					return AstReturnStatementType;
				}
		};
	}
}

#endif
class AstProgram : public AstNode {

public:

AstProgram(ArrayList<AstNode>* defClass) : AstNode()
{ children = defClass; }
virtual int getType() {
return AstProgramType;
}};

class AstDefClass : public AstNode {

public:

AstDefClass(AstIdentifier iden, AstAnonClass object_class) : AstNode()
{ children->add(iden);children->add(object_class); }
virtual int getType() {
return AstDefClassType;
}};

class AstAnonClass : public AstNode {

public:

AstAnonClass(ArrayList<AstNode>* expr) : AstNode()
{ children = expr; }
AstAnonClass(AstIdentifier father, ArrayList<AstNode>* expr) : AstNode()
{ children = expr;children->insert(0,father); }
virtual int getType() {
return AstAnonClassType;
}};

class AstAnonMethod : public AstNode {

public:

AstAnonMethod(AstBlock block) : AstNode()
{ children->add(block); }
virtual int getType() {
return AstAnonMethodType;
}};

class AstBlock : public AstNode {

public:

AstBlock(ArrayList<AstNode>* statements) : AstNode()
{ children = statements; }
virtual int getType() {
return AstBlockType;
}};

class AstCompoundBlock : public AstNode {

public:

AstCompoundBlock(ArrayList<AstNode>* statements) : AstNode()
{ children = statements; }
virtual int getType() {
return AstCompoundBlockType;
}};

class AstIfStatement : public AstNode {

public:

AstIfStatement(AstExpression expr, AstCompoundBlock block_if) : AstNode()
{ children->add(expr);children->add(block_if); }
AstIfStatement(AstExpression expr, AstCompoundBlock block_if, AstCompoundBlock block_else) : AstNode()
{ children->add(expr);children->add(block_if);children->add(block_else); }
virtual int getType() {
return AstIfStatementType;
}};

class AstWhileStatement : public AstNode {

public:

AstWhileStatement(AstExpression expr, AstCompoundBlock block_while) : AstNode()
{ children->add(expr);children->add(block_while); }
virtual int getType() {
return AstWhileStatementType;
}};

class AstForStatement : public AstNode {

public:

AstForStatement(AstIdentifier iden, AstExpression expr, AstCompoundBlock block_for) : AstNode()
{ children->add(iden);children->add(expr);children->add(block_for); }
virtual int getType() {
return AstForStatementType;
}};

class AstReturnStatement : public AstNode {

public:

AstReturnStatement(AstExpression expr) : AstNode()
{ children->add(expr); }
virtual int getType() {
return AstReturnStatementType;
}};

class AstExpression : public AstNode {

public:

AstExpression(AstLeftValue LeftValue, AstExpression expr) : AstNode()
{ children->add(LeftValue);children->add(expr); }
AstExpression(AstBinary value) : AstNode()
{ children->add(value); }
virtual int getType() {
return AstExpressionType;
}};

class AstLeftValue : public AstNode {

public:

AstLeftValue(AstIdentifier iden, ArrayList<AstNode>* postfix) : AstNode()
{ children = postfix;children->insert(0,iden); }
virtual int getType() {
return AstLeftValueType;
}};

class AstLeftPostfix : public AstNode {
int postfix_type;
public:
int postfix_type;
AstLeftPostfix(int PostfixType, AstNode value) : AstNode()
{ children->add(value); }
virtual int getType() {
return AstLeftPostfixType;
}};

class AstBinary : public AstNode {
int operator_type;
public:
int operator_type;
AstBinary(int OperatorType, AstNode left, AstNode right) : AstNode()
{ operator_type = OperatorType;children->add(left);children->add(right); }
virtual int getType() {
return AstBinaryType;
}};

class AstUnary : public AstNode {
int operator_type;
public:
int operator_type;
AstUnary(int OperatorType, AstNode value) : AstNode()
{ operator_type = OperatorType;children->add(value); }
AstUnary(AstNode value, ArrayList<AstNode>* postfix) : AstNode()
{ children = postfix;children->insert(0, value); }
virtual int getType() {
return AstUnaryType;
}};

class AstPostfix : public AstNode {
int postfix_type;
public:
int postfix_type;
AstPostfix(int PostfixType, AstNode value) : AstNode()
{ postfix_type = PostfixType;children->add(value); }
virtual int getType() {
return AstPostfixType;
}};

class AstArrayLiteral : public AstNode {

public:

AstArrayLiteral(AstExpression expr) : AstNode()
{ children->add(expr); }
virtual int getType() {
return AstArrayLiteralType;
}};

class AstListLiteral : public AstNode {

public:

AstListLiteral(ArrayList<AstNode>* exprs) : AstNode()
{ children = exprs; }
virtual int getType() {
return AstListLiteralType;
}};


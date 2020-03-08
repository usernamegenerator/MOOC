/*
 * 6.088 IAP 2010
 * Assignment #5: Inheritance and Polymorphism
 *
 * Expression.h
 * Header file for the abstract base class Expression
 */
#ifndef EXPRESSION
#define EXPRESSION
#include <string>
#include <queue>
#include <stack>
#include <cctype>
#include <vector>
#include <cstring>


typedef enum char_type{
	OPERAND,
	OPERATOR,
	LPARENTHESIS,
	RPARENTHESIS,
}char_type;


typedef enum op{
    ADD,
    SUB,
    MUL,
    DIV,
    NEG
}op;

/* number of operands for each operator type */
const unsigned int op_operands[] = {2, 2, 2, 2, 1};

/* order-of-operations (precedence) (0 = evaluated last) */
const unsigned int op_precedences[] = {0, 0, 1, 1, 2};

/* direction of evaluation (associativity) */
enum assoc {
	LEFT, /* left-to-right (+, binary -, *, /) */
	RIGHT /* right-to-left (unary -) */
};

/* evaluation direction (associativity) for each precedence level */
const enum assoc op_associativity[] = {LEFT, LEFT, RIGHT};

typedef union token_value{
	double number;
	op op_type;
}token_value;

typedef struct node{
	token_value t_value;
	char_type t_type;
}node;




/*
 * Expression
 */
class Expression {

 public:
  virtual ~Expression() {}

  // Returns the result of evaluating this expression.
  virtual float eval()  = 0;

  // Prints the expression. DO NOT evaluate before printing.
  virtual void print()  = 0;
};

class ArithmeticExpression: public Expression{
private:
	std::string str_exp;
public:
	ArithmeticExpression(std::string);
	~ArithmeticExpression();
	float eval() ;
	void print() ;
	std::queue <node*> string_to_infix();
	std::queue <node*> infix_to_postfix(std::queue <node*>);
	float postfix_to_results(std::queue <node*>);
};

void print_node_queue(std::queue<node*>);
#endif  // EXPRESSION

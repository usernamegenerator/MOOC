#include "Expression.h"
#include <iostream>

using namespace std;
int main(){
	//string str_expr = "( 3.0 + 4 ) * - ( 5.0 )";
	string str_expr = "( 3.0 + 4 ) * ( 5.001 - 5 )";
  // ADD YOUR TESTS HERE
	ArithmeticExpression* exp = new ArithmeticExpression(str_expr);
	//exp->print();
	exp->eval();


  return 0;
}


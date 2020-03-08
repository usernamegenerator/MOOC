#include <iostream>
#include "Expression.h"

using namespace std;

std::vector<std::string> op_for_print = {"ADD","SUB","MUL","DIV","NEG"};

void print_node_queue(std::queue<node*> q)
{
	while(!q.empty())
	{
	    if(q.front()->t_type == OPERATOR)
            cout << op_for_print[(int)q.front()->t_value.op_type];// << endl;
        else if(q.front()->t_type == OPERAND)
            cout << q.front()->t_value.number;// << endl;
        else if(q.front()->t_type == LPARENTHESIS)
            cout << '(';// << endl;
        else if(q.front()->t_type == RPARENTHESIS)
            cout << ')';// << endl;
        else
            cout << "unknown type" << endl;
		q.pop();
	}
}

void print_single_node(node* n)
{

    if(n->t_type == OPERATOR)
        cout << op_for_print[(int)n->t_value.op_type];// << endl;
    else if(n->t_type == OPERAND)
        cout << n->t_value.number;// << endl;
    else if(n->t_type == LPARENTHESIS)
        cout << '(';// << endl;
    else if(n->t_type == RPARENTHESIS)
        cout << ')';// << endl;
    else
        cout << "unknown type" << endl;

}

ArithmeticExpression::ArithmeticExpression(string S)
{
	str_exp = S;
}

ArithmeticExpression::~ArithmeticExpression()
{
	return;
}


void ArithmeticExpression::print()
{
	cout << str_exp << endl;
}

std::queue <node*> ArithmeticExpression::string_to_infix()
{
	queue <node*> infix_queue;
	string::iterator it;
    //to record previous char type to distinguish between NEG and SUB
    //if previous is a OPERATOR or LPARENTHESIS, then it's a NEG
    //if previous is a OPERAND or right RPARENTHESIS, then it's a SUB
	char_type type = OPERATOR;

    char * str = new char [str_exp.length()+1];
    strcpy (str, str_exp.c_str());

#define DELIMS_STR " \n\r\t"
	for (str = strtok(str, DELIMS_STR); str; str = strtok(NULL, DELIMS_STR))
	{
	    node* new_node = new node();
	    if(strlen(str) == 1)
        {
            //switch(str)   //error: switch quantity not an integer|
            switch(str[0])
            {
                case '+':
                    type = OPERATOR;
                    new_node->t_type = OPERATOR;
                    new_node->t_value.op_type = ADD;
                    break;
                case '-':
                    if(type == OPERATOR)
                    {
                        type = OPERATOR;
                        new_node->t_type = OPERATOR;
                        new_node->t_value.op_type = NEG;
                    }
                    else if(type == LPARENTHESIS)
                    {
                        type = OPERATOR;
                        new_node->t_type = OPERATOR;
                        new_node->t_value.op_type = NEG;
                    }
                    else
                    {
                        type = OPERATOR;
                        new_node->t_type = OPERATOR;
                        new_node->t_value.op_type = SUB;
                    }
                    break;
                case '*':
                    type = OPERATOR;
                    new_node->t_type = OPERATOR;
                    new_node->t_value.op_type = MUL;
                    break;
                case '/':
                    type = OPERATOR;
                    new_node->t_type = OPERATOR;
                    new_node->t_value.op_type = DIV;
                    break;
                case '(':
                    type = LPARENTHESIS;
                    new_node->t_type = LPARENTHESIS;
                    break;
                case ')':
                    type = RPARENTHESIS;
                    new_node->t_type = RPARENTHESIS;
                    break;
                default:
                    type = OPERAND;
                    new_node->t_type = OPERAND;
                    new_node->t_value.number = stod(str);
            }
        }
        else
        {
            type = OPERAND;
            new_node->t_type = OPERAND;
            new_node->t_value.number = stod(str);
        }
		infix_queue.push(new_node);
	}
	return infix_queue;
}

std::queue <node*> ArithmeticExpression::infix_to_postfix(std::queue<node*> infix_queue)
{
/*
1. dequeue token from input
    //#if PARSE_PARENS
        ***if (, push to stack
        ***if ), pop stack and add to output queue until (, then pop ( and discard.
    //#endif
2. if operand (number), add to output queue
3. if operator, if stack empty, then push to stack. if not empty, then pop operator off stack and add to output queue as long as (while)
    > top operator on stack has higher precedence, or
    > top operator on stack has same precedence and its left-associative
  and push new operator onto stack
4. return to step 1 as long as tokens remain in input
5. pop remaining operator from stack and add to output queue
*/
    stack<node*> node_stack;
    queue <node*> postfix_queue;
    node* q_front;

    while(q_front = infix_queue.front())
    {
        print_single_node(q_front);
        if(q_front->t_type == LPARENTHESIS)
        {
            cout << "LPARENTHESIS" << endl;
            node_stack.push(q_front);
        }
        else if(q_front->t_type == RPARENTHESIS)
        {
            cout << "RPARENTHESIS" << endl;
            while(node_stack.top()->t_type != LPARENTHESIS)
            {
                postfix_queue.push(node_stack.top());
                node_stack.pop();
            }
            node_stack.pop();
        }
        else if(q_front->t_type == OPERAND)
        {
            cout << "OPERAND" << endl;
            postfix_queue.push(q_front);
        }
        else// if(q_front->t_type == OPERATOR)
        {
            cout << "OPERATOR" << endl;
            if(node_stack.empty())
            {
                node_stack.push(q_front);
            }
            else
            {
                while(!node_stack.empty())
                {
                    if(node_stack.top()->t_type == LPARENTHESIS)
                    {
                        break;
                    }

                    int stack_precedences = op_precedences[(int)node_stack.top()->t_value.op_type];
                    int queue_precedences = op_precedences[(int)q_front->t_value.op_type];
                    int s_associativity = (int)op_associativity[stack_precedences];

                    if(stack_precedences > queue_precedences || (stack_precedences == queue_precedences && s_associativity == (int)LEFT))
                    {
                        postfix_queue.push(node_stack.top());
                        node_stack.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                node_stack.push(q_front);
            }
        }
        infix_queue.pop();
    }

    while(!node_stack.empty())
    {
        postfix_queue.push(node_stack.top());
        node_stack.pop();
    }

    return postfix_queue;
}

float ArithmeticExpression::postfix_to_results(queue <node*> postfix_queue)
{
/*
1. dequeue a token from the postfix queue
2. if token is an operand, push onto stack
3. if token if an operator, pop operands off stack (2 for binary operator);
    push result onto stack
4. repeat until queue is empty
5. item remaining in stack is final result
*/
    stack<node*> node_stack;
    while(!postfix_queue.empty())
    {
        node* q_front = postfix_queue.front();
        if(q_front->t_type == OPERAND)
        {
            node_stack.push(q_front);
        }
        else if(q_front->t_type == OPERATOR)
        {
            double temp_res;

            node* s_node_1 = node_stack.top();
            node_stack.pop();
            node* s_node_2 = node_stack.top();

            if(q_front->t_value.op_type == ADD)
            {
                node_stack.pop();
                temp_res = s_node_2->t_value.number + s_node_1->t_value.number;
            }
            else if(q_front->t_value.op_type == SUB)
            {
                node_stack.pop();
                temp_res = s_node_2->t_value.number - s_node_1->t_value.number;
            }
            else if(q_front->t_value.op_type == MUL)
            {
                node_stack.pop();
                temp_res = s_node_2->t_value.number * s_node_1->t_value.number;
            }
            else if(q_front->t_value.op_type == DIV)
            {
                node_stack.pop();
                temp_res = s_node_2->t_value.number / s_node_1->t_value.number;
            }
            else if(q_front->t_value.op_type == NEG)
            {
                temp_res = 0 - s_node_1->t_value.number;
            }

            node * new_node = new node;
            new_node->t_type == OPERAND;
            new_node->t_value.number = temp_res;
            node_stack.push(new_node);
        }
        postfix_queue.pop();
    }

    return node_stack.top()->t_value.number;
}

float ArithmeticExpression::eval()
{
	queue <node*> infix_queue;
	queue <node*> postfix_queue;
	infix_queue = string_to_infix();
    //print_node_queue(infix_queue);
	postfix_queue = infix_to_postfix(infix_queue);
    cout << endl;
    cout << endl;
    cout << endl;
	print_node_queue(postfix_queue);
	cout << endl;
    cout << endl;
    cout << endl;
	float res = postfix_to_results(postfix_queue);
	cout << res << endl;

}



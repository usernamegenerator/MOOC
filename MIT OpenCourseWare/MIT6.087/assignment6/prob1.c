/*
 * prob1.c
 *
 *  Created on:
 *      Author:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* maximum length of input string (including newline character) */
#define INPUT_MAX 2048

/* enable (1) or disable (0) parentheses checking in parsing strings */
/* leave disabled for part (a); enable for part (b) */
#define PARSE_PARENS 1

/* type of token */
enum token_type {
	OPERAND, /* number */
	OPERATOR, /* operator: +, -, *, / */
#if PARSE_PARENS
	LPARENS, /* left parentheses ( */
	RPARENS /* right parentheses ) */
#endif
};
char* enum_token_type_list[] = {"OPERAND","OPERATOR"};

/* operator identifiers (opcodes) */
enum op {
	ADD, /* a+b */
	SUBTRACT, /* a-b (binary) */
	MULTIPLY, /* a*b */
	DIVIDE, /* a/b */
	NEGATE /* -a (unary) */
};

char* enum_op_list[] = {"ADD","SUBTRACT","MULTIPLY","DIVIDE","NEGATE"};

/* direction of evaluation (associativity) */
enum assoc {
	LEFT, /* left-to-right (+, binary -, *, /) */
	RIGHT /* right-to-left (unary -) */
};

/* number of operands for each operator type */
const unsigned int op_operands[] = {2, 2, 2, 2, 1};

/* order-of-operations (precedence) (0 = evaluated last) */
const unsigned int op_precedences[] = {0, 0, 1, 1, 2};

/* evaluation direction (associativity) for each precedence level */
const enum assoc op_associativity[] = {LEFT, LEFT, RIGHT};

/* contains value of token */
union token_value {
	double operand; /* numeric value for operand */
	enum op op_code; /* opcode for operators */
};

/* data structure for token */
typedef struct s_expr_token {
	union token_value value; /* numeric value or opcode */
	enum token_type type; /* type of token */

	struct s_expr_token * linked_token; /* linked token in stack/queue */
} * p_expr_token; /* p_expr_token is shorthand for "struct s_expr_token *" */

/* data structure for queue */
struct token_queue {
	p_expr_token front; /* front of queue, where tokens are dequeued */
	p_expr_token back; /* back of queue, where tokens are added */
};

/* queue functions - enqueue and dequeue */
void enqueue(struct token_queue * pqueue, const p_expr_token ptoken);
p_expr_token dequeue(struct token_queue * pqueue);

/* stack functions - push and pop */
void push(p_expr_token * ptop, const p_expr_token ptoken);
p_expr_token pop(p_expr_token * ptop);

/* creates a new token in dynamic memory (using malloc()) */
p_expr_token new_token(const enum token_type type, const union token_value value);

/* constructs a queue of tokens in infix order from a space-delimited string */
struct token_queue expr_to_infix(char * str);

/* creates a queue of tokens in postfix order from a queue of tokens in infix order */
/* postcondition: returned queue contains all the tokens, and pqueue_infix should be
   empty */
struct token_queue infix_to_postfix(struct token_queue * pqueue_infix);

/* evalutes the postfix expression stored in the queue */
/* postcondition: returned value is final answer, and pqueue_postfix should be empty */
double evaluate_postfix(struct token_queue * pqueue_postfix);

/* handles evaluation process (calls above functions) for expression string str */
double evaluate(const char * str);
void print_token(p_expr_token ptoken)
{
    if(ptoken->type == OPERAND)//operand
        printf("%lf \n",ptoken->value.operand);
#if PARSE_PARENS
    else if (ptoken->type == LPARENS)
    {
        printf("( \n");
    }
    else if (ptoken->type == RPARENS)
    {
        printf(") \n");
    }
#endif
    else//operator
        printf("%s \n",enum_op_list[(int)ptoken->value.op_code]);
}
void display_queue(struct token_queue * pqueue)
{
    p_expr_token ptoken = pqueue->front;
    if(ptoken==NULL)
    {
        printf("empty queue\n");
        return;
    }
    printf("\n");
    while(ptoken)
    {
        print_token(ptoken);
        ptoken = ptoken->linked_token;
        if(ptoken==NULL)
            break;
    }
    printf("\n");
    return;
}

int main(void) {
	char input[INPUT_MAX];
	double ans;
	unsigned int len;

	do {
		printf("Enter an expression to evaluate: ");
		fflush(stdout);
		if (!fgets(input, INPUT_MAX, stdin))
			abort(); /* failed to read stdin */

		len = strlen(input);
		/* remove trailing newline character */
		if (len > 0 && input[len-1] == '\n') {
			input[len-1] = '\0';
			--len;
		}
		if (len == 0) /* empty expression signals exit */
			break;

        //printf("input len = %d\n",len);
		/* call evaluation functions */
		ans = evaluate(input);

		/* write result to stdout */
		printf("%s => %g\n", input, ans);
	} while (1);

	return 0;
}

/* enqueue (add) token to end of queue
   input: pqueue - pointer to queue
          ptoken - token pointer to add
   postcondition: token added to end of queue */
void enqueue(struct token_queue * pqueue, const p_expr_token ptoken) {
	ptoken->linked_token = NULL;
	if (pqueue->back)
		pqueue->back->linked_token = ptoken;
	else /* empty */
		pqueue->front = ptoken;
	pqueue->back = ptoken;
}

/* dequeue (remove) token from front of queue
   input: pointer to queue
   output: front token pointer (or NULL, if queue was empty)
   postcondition: token removed from queue */
p_expr_token dequeue(struct token_queue * pqueue) {
	p_expr_token ptoken = pqueue->front;
	if (pqueue->front) {
		pqueue->front = ptoken->linked_token;
		if (ptoken == pqueue->back) /* at end */
			pqueue->back = NULL;
		ptoken->linked_token = NULL;
	}
	return ptoken;
}

/* push (add) token to top of stack
   input: ptop - pointer to top token pointer of stack
          ptoken - token pointer to add
   postcondition: ptop points to the added token */
void push(p_expr_token * ptop, const p_expr_token ptoken) {
	ptoken->linked_token = *ptop;
	*ptop = ptoken;
}

/* pop (remove) token from top of stack
   input: pointer to top token pointer of stack
   output: top token pointer (or NULL, if stack was empty)
   postcondition: ptop points to next token in stack */
p_expr_token pop(p_expr_token * ptop) {
	p_expr_token ptoken;
	if ( (ptoken = *ptop) ) {
		*ptop = ptoken->linked_token;
		ptoken->linked_token = NULL;
	}
	return ptoken;
}

/* allocate new token on heap, with specified type and value; the token is initially
   un-linked (field "linked_token" == NULL)
   note: token must be freed using free() after use */
p_expr_token new_token(const enum token_type type, const union token_value value) {
	p_expr_token ptoken = (p_expr_token)malloc(sizeof(struct s_expr_token));
	ptoken->type = type;
	ptoken->value = value;
	ptoken->linked_token = NULL;
	return ptoken;
}

/* handles evaluation process (calls above functions) for expression string str */
/* returns the final answer */
double evaluate(const char * str) {
	char * strbuffer; /* mutable buffer for string (modified in calls to strtok()) */
	double ans; /* answer to return */
	struct token_queue queue_infix, queue_postfix;

	/* copy str into mutable buffer */
	strbuffer = strcpy((char *)malloc(strlen(str)+1),str);

	/* get queue of tokens in infix order from string buffer */
	queue_infix = expr_to_infix(strbuffer);

    display_queue(&queue_infix);

	/* get queue of tokens in postfix order from infix-ordered queue */
	queue_postfix = infix_to_postfix(&queue_infix);

    display_queue(&queue_postfix);

	/* get answer from postfix-ordered queue */
	ans = evaluate_postfix(&queue_postfix);

	free(strbuffer); /* free memory from heap */
	return ans;
}

/* constructs a queue of tokens in infix order from a space-delimited string */
struct token_queue expr_to_infix(char * str) {
	struct token_queue queue_infix; /* queue with infix ordering */
	enum token_type type = OPERATOR;
	union token_value value;

	/* initialize the queue to empty */
	queue_infix.front = NULL;
	queue_infix.back = NULL;

	/* delimiter string for strtok() -- contains whitespace characters */
#define DELIMS_STR " \n\r\t"
	for (str = strtok(str, DELIMS_STR); str; str = strtok(NULL, DELIMS_STR)) {
		/* parse token */
		if (strlen(str) == 1) { /* operators are all 1 character */
			switch (str[0]) {
			case '+':
			    //printf("+\n");
				type = OPERATOR;
				value.op_code = ADD;
				break;
			case '-':
				/* check previous token to distinguish between
				   negate (unary) and subtract (binary) */
				if (type == OPERATOR)
					value.op_code = NEGATE; /* unary */
#if PARSE_PARENS
				else if (type == LPARENS)
					value.op_code = NEGATE; /* unary */
#endif
				else
					value.op_code = SUBTRACT; /* binary */
				type = OPERATOR;
				break;
			case '*':
				type = OPERATOR;
				value.op_code = MULTIPLY;
				break;
			case '/':
				type = OPERATOR;
				value.op_code = DIVIDE;
				break;
#if PARSE_PARENS
			case '(':
				type = LPARENS;
				break;
			case ')':
				type = RPARENS;
				break;
#endif
			default:
				/* not an operator */
				type = OPERAND;
				value.operand = strtod(str, NULL);
			}
		} else {
			type = OPERAND;
			value.operand = strtod(str, NULL);
		}
		/* add token with parsed type and value to end of queue */
		enqueue(&queue_infix, new_token(type, value));
	}
	return queue_infix;
}

/* creates a queue of tokens in postfix order from a queue of tokens in infix order */
/* postcondition: returned queue contains all the tokens, and pqueue_infix should be
   empty */
struct token_queue infix_to_postfix(struct token_queue * pqueue_infix) {
	/* TODO: construct postfix-ordered queue from infix-ordered queue;
	   all tokens from infix queue should be added to postfix queue or freed */

    /*
    1. dequeue token from input
        //#if PARSE_PARENS
            ***if (, push to stack
            ***if ), pop stack and add to output queue until (, then pop ( and discard.
        //#endif
    2. if operand (number), add to output queue
    3. if operator, then pop operator off stack and add to output queue as long as
        > top operator on stack has higher precedence, or
        > top operator on stack has same precedence and its left-associative
      and push new operator onto stack
    4. return to step 1 as long as tokens remain in input
    5. pop remaining operator from stack and add to output queue
    */

    struct token_queue queue_postfix;
    queue_postfix.front = NULL;
	queue_postfix.back = NULL;

    p_expr_token ptoken = NULL;
    p_expr_token ptop = NULL;
    p_expr_token stoken = NULL;


    while((ptoken = dequeue(pqueue_infix)))
    {
       //print_token(ptoken);
       if(ptoken->type == OPERAND)
       {
           enqueue(&queue_postfix,ptoken);
       }
#if PARSE_PARENS
       else if(ptoken->type == LPARENS)
       {
           printf("dequeued (\n");
           push(&ptop,ptoken);
       }
       else if(ptoken->type == RPARENS)
       {
           printf("dequeued )\n");
           p_expr_token temp_token = NULL;
           while((temp_token = pop(&ptop)))
           {
               if(temp_token->type == LPARENS)
               {
                   break;
               }
               enqueue(&queue_postfix,temp_token);
           }
       }
#endif // PARSE_PARENS
       else  //OPEARATOR
       {
           //the very first one in infix queue is operator,
           //only one possibility that this is a NEG operator
           //push in
            if(ptop==NULL)
            {
                push(&ptop,ptoken);
            }
            else
            {
                while((stoken = pop(&ptop)))
                {
#if PARSE_PARENS
                    if(stoken->type == LPARENS)
                    {
                        //don't pop, push it back
                        push(&ptop,stoken);
                        break;
                    }
#endif // PARSE_PARENS
                    int s_precedences = op_precedences[(int)stoken->value.op_code];
                    int p_precedences = op_precedences[(int)ptoken->value.op_code];
                    int s_associativity = (int)op_associativity[s_precedences];
                    if(s_precedences>p_precedences || (s_precedences==p_precedences && s_associativity == (int)LEFT))
                    {
                        //pop the stack, and add to output queue
                        enqueue(&queue_postfix,stoken);
                        //as long as this if condition meets, we pop the stack
                    }
                    else
                    {
                        //don't pop, push it back
                        push(&ptop,stoken);
                        break;
                    }
                }
                //push new to stack
                push(&ptop,ptoken);
            }
       }
    }

    while((stoken=pop(&ptop)))
    {
        enqueue(&queue_postfix,stoken);
    }

    display_queue(&queue_postfix);

    return queue_postfix;
}

/* evalutes the postfix expression stored in the queue */
/* postcondition: returned value is final answer, and pqueue_postfix should be empty */
double evaluate_postfix(struct token_queue * pqueue_postfix) {
	/* TODO: process postfix-ordered queue and return final answer;
	   all tokens from postfix-ordered queue is freed */
    /*
    1. dequeue a token from the postfix queue
    2. if token is an operand, push onto stack
    3. if token if an operator, pop operands off stack (2 for binary operator);
        push result onto stack
    4. repeat until queue is empty
    5. item remaining in stack is final result
    */

    //STACK elements
    p_expr_token ptop = NULL;
    p_expr_token stoken_1 = NULL;
    p_expr_token stoken_2 = NULL;
    //QUEUE elements
    p_expr_token ptoken = NULL;

    p_expr_token res_token = NULL;

    double temp_result;
    double final_result;

/*
//test
    display_queue(pqueue_postfix);

    while((ptoken = dequeue(pqueue_postfix)))
    {
        print_token(ptoken);
        //test
    }
    return 0;
//test end
*/
    while((ptoken = dequeue(pqueue_postfix)))
    {
        if(ptoken->type == OPERAND)
        {
            push(&ptop,ptoken);
            //continue;
        }
        else// (ptoken->type == OPERATOR)
        {

            stoken_1 = pop(&ptop);

            if(stoken_1 == NULL)
                printf("empty token from stack line: %d\n",__LINE__);


            if(ptoken->value.op_code != NEGATE)
            {
                stoken_2 = pop(&ptop);

                if(stoken_2 == NULL)
                    printf("empty token from stack line: %d\n",__LINE__);

            }


            if(ptoken->value.op_code == ADD)
            {
                temp_result = stoken_2->value.operand + stoken_1->value.operand;
            }
            else if(ptoken->value.op_code == SUBTRACT)
            {
                temp_result = stoken_2->value.operand - stoken_1->value.operand;
            }
            else if(ptoken->value.op_code == MULTIPLY)
            {
                temp_result = stoken_2->value.operand * stoken_1->value.operand;
            }
            else if(ptoken->value.op_code == DIVIDE)
            {
                temp_result = stoken_2->value.operand / stoken_1->value.operand;
            }
            else if(ptoken->value.op_code == NEGATE)
            {
                temp_result = 0 - stoken_1->value.operand;
            }
            else
            {
                printf("no valid op_code\n");
            }
            //test
            printf("1 value %f\n",stoken_1->value.operand);
            printf("2 value %f\n",stoken_2->value.operand);
            printf("operator %d\n",(int)ptoken->value.op_code);
            //test end

            union token_value tv;
            tv.operand = temp_result;
            res_token = new_token(OPERAND,tv);
            print_token(res_token);
            push(&ptop,res_token);
        }

    }

    res_token = pop(&ptop);
    final_result = res_token->value.operand;
    free(res_token);
    printf("final result = %f\n",final_result);

    return final_result;

}

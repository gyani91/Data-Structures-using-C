/*  Conversion of Infix to Postfix
    Algorithm
    Token	Operation

    Operand	ADD to the expression

    (		PUSH to the stack

    Operator	POP the operator from the stack
		IF precedence P(popped) >= P(scanned)
			ADD popped operator to the expression
			PUSH scanned operator to the stack
		ELSE P(popped) < P(scanned) OR it not an operator i.e ( )
			PUSH the popped operator back to stack
			PUSH the scanned operator to stack
    )		POP till (
			ADD the operators to expression
			DELETE the (

    After the expression is completely scanned the stack may have some
    operators left. POP & ADD them to the expression.
    Example:
	Infix:    A$B*C-D+E/F/(G+H)
	Postfix:   AB$C*D-EF/GH+/+
*/

#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define MAX 30
#define NULL 0

struct stack
{
	char arr[MAX];
	int top;
};

void push(struct stack *p,char no);
char pop(struct stack *p);
void convert_ip(char *infix,char *postfix);


int count;
void main()
{
	char infix[20],postfix[20]={'\0'};
	clrscr();
	printf("Enter An Infix expression:\n");
	gets(infix);
	for(count=0;infix[count]!='\0';count++);
	convert_ip(&infix[0],&postfix[0]);
	printf("\nThe Corresponding Postfix Expression is: ");
	puts(postfix);
	getch();
}

void convert_ip(char *infix,char *postfix)
{
	int i=0,r,op;
	struct stack s;
	s.top=-1;
	push(&s,'#');
	while(i<count)
	{
		if(isop(*infix))
		{
			op=pop(&s);
			if(*infix=='(')
			{
				push(&s,op);
				push(&s,*infix);
			}
			else if(*infix==')')
				while(op!='(')
				{
					*postfix=op;
					postfix++;
					op=pop(&s);
				}
			else if(*infix==' ')
				push(&s,op);
			else if(prcd(op)>=prcd(*infix))
			{
				*postfix=op;
				postfix++;
				push(&s,*infix);
			}
			else
			{
				push(&s,op);
				push(&s,*infix);
			}
		}
		else
		{
			*postfix=*infix;
			postfix++;
		}
		infix++;
		i++;
	}
	while(s.top)
	{
		*postfix=pop(&s);
		postfix++;
	}
}

int isop(char sym)
{
	switch(sym)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '$':
		case '(':
		case ')':
		case ' ':
			return 1;
		default:
			return 0;
	}
}

int prcd(char sym)
{
	switch(sym)
	{
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 4;
		case '^':
		case '$':
			return 6;
		case '(':
		case ')':
		case '#':
			return 1;
		default:
			return 0;
	}
}

void push(struct stack *p,char no)
{
	if(p->top==MAX-1)
		printf("\nStack Overflow");
	else
	{
		p->top++;
		p->arr[p->top]=no;
	}
}

char pop(struct stack *p)
{
	char item;
	if(p->top==-1)
		return NULL;
	else
	{
		item=p->arr[p->top];
		p->top--;
		return item;
	}
}

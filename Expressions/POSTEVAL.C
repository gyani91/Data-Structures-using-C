/*	Evaluation  of PostFix Expression
	Algorithm

	Token	   Operation
	Operand	   PUSH in the stack
	Operator   POP to n1
		   POP to n2
		   n3 = n2 operator n1
		   PUSH n3

	POP the result.

	Example:
		Postfix: 42$3*3-84/11+/+
		Result:   46
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
	int arr[MAX];
	int top;
};

void push(struct stack *p,int no);
char pop(struct stack *p);
int evaluate(char *postfix);


int count;
void main()
{
	char postfix[20]={'\0'};
	int result;
	clrscr();
	printf("Enter a Valid Postfix Expression: \n");
	gets(postfix);
	for(count=0;postfix[count]!='\0';count++);
	result=evaluate(&postfix[0]);
	printf("\nResult = %d",result);
	getch();
}

int evaluate(char *postfix)
{
	int i=0,n1=0,n2=0;
	struct stack s;
	s.top=-1;
	while(i<count)
	{
		if(48<=(*postfix) && (*postfix)<=57)
			push(&s,*postfix-48);
		else if(isop(*postfix))
		{
			n1=pop(&s);
			n2=pop(&s);
			push(&s,opera(n2,*postfix,n1));
		}
		else if(*postfix==' ');
		else
			printf("Please Enter a valid Postfix Expression");

		postfix++;
		i++;
	}
	return(pop(&s));
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
		case '%':
		case '$':
			return 1;
		default:
			return 0;
	}
}

int opera(int x,char sym,int y)
{
	int i,r=1;
	switch(sym)
	{
		case '+':
			return(x+y);
		case '-':
			return(x-y);
		case '*':
			return(x*y);
		case '/':
			return(x/y);
		case '^':
			return(x^y);
		case '%':
			return(x%y);
		case '$':
			for(i=0;i<y;i++)
				r*=x;
			return(r);
		default:
			return 0;
	}
}

void push(struct stack *p,int no)
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
	int item;
	if(p->top==-1)
		return NULL;
	else
	{
		item=p->arr[p->top];
		p->top--;
		return item;
	}
}

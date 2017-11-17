#include<conio.h>
#include<stdio.h>
#include<process.h>

#define MAX 30
#define NULL 0

struct stack
{
	int arr[MAX],top;

};

void push(struct stack *p,int no);
int pop(struct stack *p);
void display(struct stack *p);

main()
{
	int ch,item;
	struct stack s;
	s.top=-1;
	while(1)
	{
	clrscr();
	printf("\n\t\t\t1: Push");
	printf("\n\t\t\t2: Pop");
	printf("\n\t\t\t3: Display");
	printf("\n\t\t\t4: Exit");
	printf("\n\n\t\tEnter your choice ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nEnter the element to be pushed\n");
			scanf("%d",&item);
			push(&s,item);
			display(&s);
			break;
		case 2:
			item=pop(&s);
			printf("Element popped is %d",item);
			display(&s);
			break;
		case 3:
			display(&s);
			break;
		case 4:
			exit(0);
		default:
			printf("\nPlease enter a valid choice");
			getch();
	}
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
		printf("\nElement Pushed is %d",no);
	}
}

int pop(struct stack *p)
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

void display(struct stack *p)
{
	int i;
	if(p->top==-1)
		printf("\nStack is Empty\n");
	else
		for(i=p->top;i>=0;i--)
			printf("\n%d",p->arr[i]);
	getch();
}
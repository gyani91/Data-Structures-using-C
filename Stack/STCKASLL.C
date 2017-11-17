#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<alloc.h>


#define MAX 30
#define NULL 0

struct node
{
	int data;
	struct node *link;
};

void push(struct node **p,int no);
int pop(struct node **p);
void display(struct node *p);

main()
{
	int ch,item;
	struct node *top;
	top=NULL;
	while(1)
	{
	clrscr();
	printf("\n\t\t\t1: Push");
	printf("\n\t\t\t2: Pop");
	printf("\n\t\t\t3: Count");
	printf("\n\t\t\t4: Display");
	printf("\n\t\t\t5: Exit");
	printf("\n\n\t\tEnter your choice ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nEnter the element to be pushed: ");
			scanf("%d",&item);
			push(&top,item);
			display(top);
			break;
		case 2:
			item=pop(&top);
			printf("\nElement popped is %d\n",item);
			display(top);
			break;
		case 3:
			item=count(top);
			printf("\nTotal number of elments in the stack is %d",item);
			getch();
			break;
		case 4:
			display(top);
			break;
		case 5:
			exit(0);
		default:
			printf("\nPlease enter a valid choice");
			getch();
	}
	}
}

void push(struct node **p,int no)
{
	struct node *q;
	q=(struct node *) malloc(sizeof(struct node));
	q->data=no;
	q->link=*p;
	*p=q;
	printf("\nElement Pushed is %d\n",q->data);
}

int pop(struct node **p)
{
	struct node *q;
	int item;
	if(*p==NULL)
		return NULL;
	q=*p;
	item=q->data;
	*p=q->link;
	free(q);
	return item;
}

void display(struct node *p)
{
	if(p==NULL)
		printf("\nStack is Empty\n");
	else
	while(p!=NULL)
	{
		printf("%2d\t",p->data);
		p=p->link;
	}
	getch();
}

int count(struct node *p)
{
	int c=0;
	while(p!=NULL)
	{
		p=p->link;
		c++;
	}
	return c;
}
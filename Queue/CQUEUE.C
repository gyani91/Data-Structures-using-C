#include<conio.h>
#include<stdio.h>
#define MAX 5

void insert(void);
void del(void);
void display(void);

int q[MAX],front=-1,rear=-1;

main()
{
	int ch;
	while(1)
	{
		clrscr();
		printf("\n\t\t\t1: Insert");
		printf("\n\t\t\t2: Delete");
		printf("\n\t\t\t3: Display");
		printf("\n\t\t\t4: Quit");
		printf("\n\t\tEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				display();
				break;
			case 2:
				del();
				display();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Please enter correct choice");
		}
	}
}

void insert(void)
{
	if((front==0 && rear==MAX-1) || (front==rear+1))
	{
		printf("\nQueue Overflow\n");
		return;
	}
	if(front==-1)
		front=rear=0;
	else if(rear==MAX-1)
		rear=0;
	else
		rear++;
	printf("\nInput the element for insertion in queue:");
	scanf("%d",&q[rear]);
	printf("\nInserted element is %d",q[rear]);
}

void del(void)
{
	if(front==-1)
		return;
	printf("\nElement deleted from queue is: %d",q[front]);
	if(front==rear)
		front=rear=-1;
	else if(front==MAX-1)
		front=0;
	else if(front==-1)
		return;
	else
		front++;
}

void display(void)
{
	int front_pos=front,rear_pos=rear;
	if(front==-1)
	{
		printf("\nQueue is empty\n");
		getch();
		return;
	}
	printf("\nQueue elements: ");
	if(front_pos<=rear_pos)
		while(front_pos<=rear_pos)
			printf(" %d",q[front_pos++]);
	else
	{
		while(front_pos<=MAX-1)
			printf(" %d",q[front_pos++]);
		front_pos=0;
		while(front_pos<=rear_pos)
			printf(" %d",q[front_pos++]);
	}
	printf("\n");
	getch();
}

#include<conio.h>
#include<stdio.h>
#include<process.h>

int queue[30],item,rear,front;
void enqueuing(void);
void dequeuing(void);
void display(void);

main()
{
	int ch,i;
	rear=-1,front=0;
	while(1)
	{
		clrscr();
		printf("\n\t\t\t1: Enqueuing");
		printf("\n\t\t\t2: Dequeuing");
		printf("\n\t\t\t3: Display");
		printf("\n\t\t\t4: Exit");
		printf("\n\t\tEnter your choice:  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueuing();
				display();
				break;
			case 2:
				dequeuing();
				display();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
}

void enqueuing(void)
{
	printf("\nEnter the element to be entered: ");
	scanf("%d",&item);
	if(rear==30)
		printf("\nQueue is Full");
	else
	{
		queue[++rear]=item;
		printf("\nElement inserted is %d\n\n",item);
	}
}

void dequeuing(void)
{
	if(front<=rear)
	{
		item=queue[front++];
		printf("Element deleted is %d\n\n",item);
	}
}

void display(void)
{
	int i;
	if(front>rear)
		printf("\nQueue is empty");
	else
		for(i=front;i<=rear;i++)
			printf("%d\t",queue[i]);
	getch();
}
#include<conio.h>
#include<stdio.h>
#include<alloc.h>

struct node
{
	int data;
	struct node *link;
};
struct node **start;
int no;
struct node *temp,*old,*r;
void add_beg(void);
void add_end(void);
void add_bet(void);
void del_ele(void);
void del_loc(void);
void display(void);
void main()
{
	int ch;
	while(1)
	{
		clrscr();
		printf("\n\t\t\t1: Add a Node in the beginning");
		printf("\n\t\t\t2: Add a Node in the ending");
		printf("\n\t\t\t3: Add a Node in between");
		printf("\n\t\t\t4: Delete a Node by Location");
		printf("\n\t\t\t5: Delete a Node by element");
		printf("\n\t\t\t6: Display");
		printf("\n\t\t\t7: Exit");
		printf("\n\t\tEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add_beg();
				display();
				break;
			case 2:
				add_end();
				display();
				break;
			case 3:
				add_bet();
				display();
				break;
			case 4:
				del_loc();
				display();
				break;
			case 5:
				del_ele();
				display();
				break;
			case 6:
				display();
				break;
			case 7:
				exit(0);
			default:
				printf("\nPlease enter a correct choice");
				getch();
		}
	}
}

void add_beg(void)
{
	printf("\nEnter number to be inserted");
	scanf("%d",&no);
	if(*start==NULL)
	{
		temp=malloc(sizeof(struct node));
		temp->data=no;
		temp->link=NULL;
		*start=temp;
	}
	else
	{
		temp=*start;
		temp=malloc(sizeof(struct node));
		temp->data=no;
		temp->link=*start;
		*start=temp;
       }
}
void add_end(void)
{
	printf("\nEnter number to be inserted");
	scanf("%d",&no);
	if(*start==NULL)
	{
		temp=malloc(sizeof(struct node));
		temp->data=no;
		temp->link=NULL;
		*start=temp;
	}
	else
	{
		temp=*start;
		while(temp->link!=NULL)
			temp=temp->link;
		r=malloc(sizeof(struct node));
		r->data=no;
		r->link=NULL;
		temp->link=r;
	}
}

void add_bet(void)
{
	int loc,i;
	printf("\nEnter number to be inserted");
	scanf("%d",&no);
	printf("\nEnter the location");
	scanf("%d",&loc);
	temp=*start;
	/*Skip to desired position*/
	for(i=0;i<loc-2;i++)
	{
		temp=temp->link;
		/*if end of link list is encountered*/
		if(temp==NULL)
		{
			printf("\nThere are less node than %d in the list",loc);
			return;
		}
	}
	/*Inserting new node*/
	r=malloc(sizeof(struct node));
	r->data=no;
	r->link=temp->link;
	temp->link=r;
}

void del_ele(void)
{
	temp=*start;
	printf("Enter the element to be deleted: ");
	scanf("%d",&no);
	while(temp!=NULL)
	{
		if(temp->data==no)
		{
			/*if node to be deleted is the 1st node*/
			if(temp==*start)
				*start=temp->link;
			else
				old->link=temp->link;
			/*free memory occupied by the node*/
			free(temp);
			return;
		}
		/*Traverse list till last node is reached*/
		else
		{
			old=temp;
			/*old points to previous nod*/
			temp=temp->link;
		}
	}
	printf("\nElement %d not found",no);
}

void del_loc(void)
{
	int i;
	temp=*start;
	printf("Enter the location of the node to be deleted: ");
	scanf("%d",&no);
	/*Traverse list till desired node is reached*/
	for(i=0;i<(no-2);i++)
	{
		old=temp;
		temp=temp->link;
		/*if end of link list is encountered*/
		if(temp==NULL)
		{
			printf("\nThere are less node than %d in the list",no);
			return;
		}
	}
	/*if node to be deleted is the 1st node*/
	if(temp==*start)
		*start=temp->link;
	else
		old->link=temp->link;
	/*free memory occupied by the node*/
		free(temp);
}
void display(void)
{
	temp=*start;
	printf("\nLINK LIST:");
	while(temp!=NULL)
	{
		printf("\t%d",temp->data);
		temp=temp->link;
	}
	getch();
}



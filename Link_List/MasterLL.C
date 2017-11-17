#include<conio.h>
#include<stdio.h>
#include<alloc.h>

struct node
{
	int data;
	struct node *link;
};

void add_beg(struct node **start,int no);
void add_end(struct node **start,int no);
void add_bet(struct node *start,int loc,int no);
void del_ele(struct node **start,int no);
void del_loc(struct node **start,int no);
void del_last(struct node **start);
void deleteall(struct node **q);
int count(struct node *q);
void display(struct node *start);
int fetch(struct node *start,int loc);
void modify(struct node *start,int loc,int no);


void main()
{
	int ch,no,loc;
	struct node *p;

	p=NULL;
	while(1)
	{
		clrscr();
		printf("\t\t\t1: Add a Node in the beginning");
		printf("\n\t\t\t2: Add a Node in the ending");
		printf("\n\t\t\t3: Add a Node in between");
		printf("\n\t\t\t4: Delete a Node by Location");
		printf("\n\t\t\t5: Delete a Node by Element");
		printf("\n\t\t\t6: Delete the Last Node");
		printf("\n\t\t\t7: Delete all Nodes");
		printf("\n\t\t\t8: Count all Nodes");
		printf("\n\t\t\t9: Fetch by Loc");
		printf("\n\t\t\t10: Modify by Loc");
		printf("\n\t\t\t11: Display");
		printf("\n\t\t\t12: Exit");
		printf("\n\t\tEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter number to be inserted");
				scanf("%d",&no);
				add_beg(&p,no);
				display(p);
				break;
			case 2:
				printf("\nEnter number to be inserted");
				scanf("%d",&no);
				add_end(&p,no);
				display(p);
				break;
			case 3:
				printf("\nEnter number to be inserted");
				scanf("%d",&no);
				printf("\nEnter the location");
				scanf("%d",&loc);
				add_bet(p,loc,no);
				display(p);
				break;
			case 4:
				printf("Enter the location of the node to be deleted: ");
				scanf("%d",&no);
				del_loc(&p,no);
				display(p);
				break;
			case 5:
				printf("\nEnter the element to be deleted: ");
				scanf("%d",&no);
				del_ele(&p,no);
				display(p);
				break;
			case 6:
				del_last(&p);
				display(p);
				break;
			case 7:
				deleteall(&p);
				display(p);
				break;
			case 8:
				printf("\nThere are %d nodes in the Link-List",count(p));
				getch();
				break;
			case 9:
				printf("\nEnter the location to be Fetched ");
				scanf("%d",&no);
				printf("\n%d",fetch(p,no));
				display(p);
				break;
			case 10:
				printf("\nEnter the location to be Modified ");
				scanf("%d",&loc);
				printf("\nEnter the element which replaces it ");
				scanf("%d",&no);
				modify(p,loc,no);
				display(p);
				break;
			case 11:
				display(p);
				break;
			case 12:
				deleteall(&p);
				exit(0);
			default:
				printf("\nPlease enter a correct choice");
				getch();
		}
	}
}

void add_beg(struct node **start,int no)
{
	struct node *temp;

	temp=(struct node *) malloc(sizeof(struct node));
	temp->data=no;
	temp->link=*start;
	*start=temp;
}

void add_end(struct node **start,int no)
{
	struct node *temp,*r;

	r=(struct node*) malloc(sizeof(struct node));
	r->data=no;
	r->link=NULL;

	if(*start==NULL)
		*start=r;
	else
	{
		temp=*start;
		while(temp->link!=NULL)
			temp=temp->link;

		temp->link=r;
	}
}

void add_bet(struct node *start,int loc,int no)
{
	struct node *temp,*r;

	int i;

	temp=start;

	/*Skip to desired position*/
	for(i=0;i<loc-2;i++)
	{
		/*if end of link list is encountered*/
		if(temp->link==NULL)
		{
			printf("\nThere are less node than %d in the list",loc);
			break;
		}
		temp=temp->link;
	}

	/*Inserting new node*/
	r=(struct node *) malloc(sizeof(struct node));
	r->data=no;
	r->link=temp->link;
	temp->link=r;
}

void modify(struct node *start,int loc,int no)
{
	struct node *temp,*r;

	int i;

	temp=start;

	/*Skip to desired position*/
	for(i=0;i<loc-1;i++)
	{
		/*if end of link list is encountered*/
		if(temp->link==NULL)
		{
			printf("\nThere are less node than %d in the list",loc);
			break;
		}
		temp=temp->link;
	}

	temp->data=no;
}

int fetch(struct node *start,int loc)
{
	struct node *temp,*r;

	int i,no;

	temp=start;

	/*Skip to desired position*/
	for(i=0;i<loc-1;i++)
	{
		/*if end of link list is encountered*/
		if(temp->link==NULL)
		{
			printf("\nThere are less node than %d in the list",loc);
			break;
		}
		temp=temp->link;
	}

	no=temp->data;
	return(no);
}



void del_ele(struct node **start,int no)
{
	struct node *temp,*old;

	temp=*start;
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
		old=temp;
		temp=temp->link;
	}
	printf("\nElement %d not found",no);
}

void del_loc(struct node **start,int no)
{
	struct node *temp,*old;

	int i;

	temp=*start;
	/*Traverse list till desired node is reached*/

	for(i=0;i<(no-1);i++)
	{
		old=temp;
		temp=temp->link;
		/*if end of link list is encountered*/
		if(temp->link==NULL)
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

void del_last(struct node **start)
{
	struct node *temp,*old;

	temp=*start;
	/*Traverse list till desired node is reached*/

	while(temp->link!=NULL)
	{
		old=temp;
		temp=temp->link;
		/*if end of link list is encountered*/
	}
	old->link=NULL;
	/*free memory occupied by the node*/
	free(temp);
}

int count (struct node *q)
{
	int c=0;
	while(q!=NULL)
	{
		q=q->link;
		c++;
	}
	return c;
}

void deleteall(struct node **q)
{
	struct node *t;
	while(*q!=NULL)
	{
		t=*q;
		*q=(*q)->link;
		free(t);
	}
}

void display(struct node *start)
{
	printf("\nLINK LIST:");

	while(start!=NULL)
	{
		printf("\t%d",start->data);
		start=start->link;
	}
	getch();
}
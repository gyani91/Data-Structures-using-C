#include<alloc.h>
#include<stdio.h>
#include<conio.h>

#define F 0
#define T 1

struct btnode
{
	struct btnode *lc;
	int data;
	struct btnode *rc;
};
int ch,n,i;

void main()
{
	struct btnode *bt1,*bt2;
	bt1=NULL;
	bt2=NULL;

	while(1)
	{
		clrscr();
		printf("\n\t\t\t1:Insert a node in Tree-1");
		printf("\n\t\t\t2:Insert a node in Tree-2");
		printf("\n\t\t\t3:Compare");
		printf("\n\t\t\t4:Exit");
		printf("\n\t\t\tPlease enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element: ");
				scanf("%d",&n);
				insert(&bt1,n);
				break;
			case 2:
				printf("\nEnter the element: ");
				scanf("%d",&n);
				insert(&bt2,n);
				break;
			case 3:
				compare(bt1,bt2,&i);
				if(i==T)
					printf("Both the trees are equal");
				else
					printf("Both the trees ain't equal");
				getch();
				break;
			case 4:
				deleteall(bt1);
				deleteall(bt2);
				exit(0);
				break;
			default:
				printf("Enter a correct choice!");
				getch();
		}
	}
}

insert(struct btnode **p,int num)
{
	if(*p==NULL)
	{
		*p=(struct btnode *) malloc(sizeof(struct btnode));
		(*p)->lc=NULL;
		(*p)->rc=NULL;
		(*p)->data=num;
	}
	else
	{
		if(num<(*p)->data)
			insert(&((*p)->lc),num);
		else
			insert(&((*p)->rc),num);
	}
}

deleteall(struct btnode *p)
{
	if(p!=NULL)
	{
		deleteall(p->lc);
		deleteall(p->rc);
		free(p);
	}
}

compare(struct btnode *p,struct btnode *q,int *flag)
{
	*flag=F;
	if(p==NULL && q==NULL)
		*flag=T;
	if(p!=NULL && q!=NULL)
	{
		if(p->data!=q->data)
			*flag=F;
		else
		{
			compare(p->lc,q->lc,flag);
			if(*flag!=F)
				compare(p->rc,q->rc,flag);
		}
	}
}
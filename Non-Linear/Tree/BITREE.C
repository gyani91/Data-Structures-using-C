/* Binary Search Tree and Tree Traversals
   Example:
	BST: 10,6,8,15,20,7,13,5
   Result:
	Inorder  : 5,6,7,8,10,13,15,20
	Preorder : 10,6,5,8,7,15,13,20
	Postorder: 5,7,8,6,13,20,15,10
*/
#include<alloc.h>
#include<stdio.h>
#include<conio.h>

#define NULL 0

struct btnode
{
	struct btnode *lc;
	int data;
	struct btnode *rc;
};
int ch,n;

void main()
{
	struct btnode *bt;
	bt=NULL;
	while(1)
	{
		clrscr();
		printf("\n\t\t\t1:Insert a node");
		printf("\n\t\t\t2:Print Traversals");
		printf("\n\t\t\t3:Exit");
		printf("\n\t\t\tPlease enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element: ");
				scanf("%d",&n);
				insert(&bt,n);
				break;
			case 2:
				printf("\nInorder : ");
				inorder(bt);
				printf("\nPreorder : ");
				preorder(bt);
				printf("\nPostorder : ");
				postorder(bt);
				getch();
				break;
			case 3:
				deleteall(bt);
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

inorder(struct btnode *p)
{
	if(p!=NULL)
	{
		inorder(p->lc);
		printf("\t%d,",p->data);
		inorder(p->rc);
	}
}

preorder(struct btnode *p)
{
	if(p!=NULL)
	{
		printf("\t%d,",p->data);
		preorder(p->lc);
		preorder(p->rc);
	}
}

postorder(struct btnode *p)
{
	if(p!=NULL)
	{
		postorder(p->lc);
		postorder(p->rc);
		printf("\t%d,",p->data);
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
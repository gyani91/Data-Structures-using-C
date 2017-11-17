/* Depth First Search and Bredth First Search

  Example:
	V1: -> 2 -> 8
	V2: -> 1 -> 3 -> 8
	V3: -> 2 -> 4 -> 8
	V4: -> 3 -> 7
	V5: -> 6 -> 7
	V6: -> 5
	V7: -> 4 -> 5 -> 8
	V8: -> 1 -> 2 -> 3 -> 7
  Result:
	Depth   First Search: 1,2,3,4,7,5,6,8
	Breadth First Search: 1,2,8,3,7,4,5,6
*/
#include<conio.h>
#include<stdio.h>
#include<alloc.h>

#define MAX 8

struct node
{
	int data;
	struct node *next;
};
struct queue
{
       int q[MAX];
       int f,r;
};

struct node *add(int);
void dfs(int v,struct node **p,int *pv);
void del(struct node *n);
void adjlist(struct node *n);
void addqueue(struct queue *a,int b);
void bfs(int v,struct node **p,int *pv);

int i,j,k;
void main()
{
	struct node *arr[MAX],*v[MAX],*v1;
	int ch,n,visit[MAX]={0};
	while(1)
	{
		clrscr();
		printf("Please enter the Graph in Adjacency List Representation\n");
		printf("\n\t\t\t1:Add a Node");
		printf("\n\t\t\t2:Next Vertex");
		printf("\n\t\t\t3:Print Adjacency List");
		printf("\n\t\t\t4:Depth First Search");
		printf("\n\t\t\t5:Breadth First Search");
		printf("\n\t\t\t6:Exit");
		printf("\n\t\tEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the Vertex: ");
				scanf("%d",&n);
				v[j]=add(n);
				if(j==0)
					arr[i]=v[j];
				else
					v[j-1]->next=v[j];
				j++;
				break;
			case 2:
				i++;
				j=0;
				printf("\nEnter for vertex %d",i+1);
				getch();
				break;
			case 3:
				for(k=0;k<=i;k++)
				{
					printf("\n V%d: ",k+1);
					adjlist(arr[k]);
				}
				getch();
				break;
			case 4:
				dfs(1,arr,visit);
				for(k=0;k<MAX;k++)
					visit[k]=0;
				getch();
				break;
			case 5:
				bfs(1,arr,visit);
				for(k=0;k<MAX;k++)
					visit[k]=0;
				getch();
				break;
			case 6:
				for(k=0;k<=i;k++)
					del(arr[k]);
				exit(0);
			default:
				printf("\nPlease enter a correct choice");
				getch();
		}
	}
}

struct node* add(int val)
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	n->data=val;
	n->next=NULL;
	return n;
}

void dfs(int v,struct node **p,int *pv)
{
	struct node *q;
	pv[v-1]=1;
	printf("%d\t",v);
	q=*(p+v-1);
	while(q!=NULL)
	{
		if(pv[q->data-1]==NULL)
			dfs(q->data,p,pv);
		else
			q=q->next;
	}
}

void adjlist(struct node *n)
{
	struct node *t;
	while(n!=NULL)
	{
		t=n->next;
		printf("%d\t",n->data);
		n=t;
	}
}
void del(struct node *n)
{
	struct node *t;
	while(n!=NULL)
	{
		t=n->next;
		free(n);
		n=t;
	}
}

void bfs(int v,struct node **p,int *pv)
{
	struct node *u;
	struct queue q;
	q.f=q.r=-1;
	pv[v-1]=1;
	addqueue(&q,v);
	printf("%d\t",v);
	while(isempty(&q)==0)
	{
		v=delqueue(&q);
		u=*(p+v-1);
		while(u!=NULL)
		{
			if(pv[u->data-1]==0)
			{
				addqueue(&q,u->data);
				pv[u->data-1]=1;
				printf("%d\t",u->data);
			}
			u=u->next;
		}
	}
}

void addqueue(struct queue *a,int b)
{
	if(a->r==MAX-1)
	{
		printf("\nQueue is Full");
		getch();
		exit(0);
	}
	a->r++;
	a->q[a->r]=b;
	if(a->f==-1);
		a->f=0;
}
int delqueue(struct queue *a)
{
	int data;
	if(a->f==-1)
	{
		printf("Queue is Empty");
		getch();
		return 0;
	}
	data=a->q[a->f];
	if(a->r == a->f)
		a->r=a->f=-1;
	else
		a->f++;
	return data;
}
int isempty(struct queue *a)
{
	if(a->f==-1)
		return 1;
	return 0;
}
#include<conio.h>
#include<stdio.h>
void main()
{
	int a[100],n,i,b;
	clrscr();
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter elements without repeatations");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter element to be searched:");
	scanf("%d",&b);
	for(i=0;i<n;i++)
	{
		if(a[i]==b)
		{
			printf("element %d found at position %d",b,i+1);
			getch();
			exit(0);
		}
	}
	printf("Element not found");
	getch();
}
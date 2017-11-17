#include<conio.h>
#include<stdio.h>

main()
{
	int i,flag=0,start=0,end=4,mid;
	int a[5],s;
	printf("\nEnter 5 elements is sorted order\n");
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	printf("\nEnter the element to be searched\n");
	scanf("%d",&s);

	while(start<=end)
	{
		mid=(start+end)/2;
		if(a[mid]==s)
		{
			printf("Element located at %d\t\n",mid+1);
			flag=1;
			break;
		}
		else
		{
			if(a[mid]>s)
				end=mid-1;
			else
				start=mid+1;
		}
	}
	if(flag==0)
	printf("\n Not Found\n");
}

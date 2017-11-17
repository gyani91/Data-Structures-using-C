#include<stdio.h>
main()
{
	int i,j,temp=0,a[10];
	printf("Enter 10 elements\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(j=0;j<9;j++)
		for(i=j+1;i<10;i++)
			if(a[j]>a[i])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	printf("\nSorted list:\n");
	for(i=0;i<10;i++)
		printf("%d\t",a[i]);
}

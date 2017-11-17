#include<conio.h>
#include<stdio.h>
void main()
{
	int s[100][100],ttf[100][3],trans[3][100],k=0,n,i,j;
	clrscr();
	printf("Enter the value of n");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&s[i][j]);
	printf("\n\nThe entered matrix is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",s[i][j]);
		printf("\n");
	}
	printf("\nThe three tuple form of the matrix is\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(s[i][j])
			{
				ttf[k][0]=i;
				ttf[k][1]=j;
				ttf[k][2]=s[i][j];
				printf("%d\t%d\t%d\n",ttf[k][0],ttf[k][1],ttf[k][2]);
				k++;
			}
	printf("\nAnd the transpose of the above triple tuple form\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<k;j++)
		{
			trans[i][j]=ttf[j][i];
			printf("%d\t",trans[i][j]);
		}
		printf("\n\n");
	}
	getch();
}
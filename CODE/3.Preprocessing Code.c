#include<stdio.h>
int a[512][512],m[512][512],c[512][512];
FILE *fp1,*fp2;
int rs=13,cs=64,t=3;
void mask();
void op();
void main()
{
	int i,j,k;
	fp1=fopen("ED(Eye)+30.txt","r");
	fp2=fopen("op30(3).pgm","w");
	for(i=0;i<rs;i++)
	{
		for(j=0;j<cs;j++)
		{
			fscanf(fp1,"%d",&k);
			a[i][j]=k;
			c[i][j]=0;
			if(a[i][j]==255)
			{
				c[i][j]=200;
			}
		}
	}
	mask();
}
void mask()
{
	int i,j;
	for(i=0;i<rs;i++)
	{
		for(j=0;j<cs;j++)
		{
			if(a[i][j]==255)
	         {
	         	c[i-1][j-1]++;
	         	c[i-1][j]++;
	         	c[i-1][j+1]++;
	         	c[i][j+1]++;
	         	c[i+1][j+1]++;
	         	c[i+1][j]++;
	         	c[i+1][j-1]++;
	         	c[i][j-1]++;
	         }
	     }
	 }
	op();
}
void op()
{
	int i,j;
	for(i=0;i<rs;i++)
	{
		for(j=0;j<cs;j++)
		{
			if(c[i][j]>=t)
				m[i][j]=255;
			else
				m[i][j]=0;	
		}
	}
	fprintf(fp2,"P2\n# Created by Irfanview\n%d %d\n255\n",cs,rs);
	for(i=0;i<rs;i++)
	{
		for(j=0;j<cs;j++)
		{
			fprintf(fp2," %d ",m[i][j]);
		}
		fprintf(fp2," \n ");
	}
	for(i=0;i<rs;i++)
	{
		printf("\n");
		for(j=0;j<cs;j++)
		{
			printf("%d   ",c[i][j]);
		}
	}
}

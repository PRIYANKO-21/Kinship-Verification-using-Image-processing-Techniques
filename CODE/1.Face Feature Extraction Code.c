#include<stdio.h>
#include<conio.h>
#include<math.h>
int a[512][512],b[512][512],e[512][512],n[512][512],m[512][512];
FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7;
int rs=64,cs=64;
//rs=rowsize/height
//cs=columnsize/width
int h[4]={14,28,47,61};
int v=31;
//h[] is for horizontal line
//v is for vertical line between eye
int main()
{
	fp1 = fopen("M1.txt","r");
	fp2 = fopen("Eye.pgm","w");
	fp3 = fopen("Nose.pgm","w");
	fp4 = fopen("Mouth.pgm","w");
	fp5 = fopen("Size And Axis Info.txt","w");
	fp6 = fopen("FD.pgm","w");
	input();
	return 0;
}
int input()
{
	int x,y,k;
	for(y=0;y<rs;y++)
	{
	  for(x=0;x<cs;x++)
	     {
			fscanf(fp1,"%d",&k);
			a[y][x]=k;
		}
	}
	FD();
	return 0;
}
int FD()
{
	int x,y;
	//Horizontal Line
	for(y=0;y<rs;y++)
	{
	  for(x=0;x<cs;x++)
	  {
	  	//according Image choose y axis
	  	if(y==h[0] || y==h[1] || y==h[2] || y==h[3])
	  	{
	  		b[y][x]=0;
		}
		else
		{
			b[y][x]=a[y][x];
		}
	  }
	}
	//Vertical Line
	for(y=0;y<rs;y++)
	{
	  for(x=0;x<cs;x++)
	  {
	  	if(y>h[0] && y<h[1])
	  	{
	  		b[y][v]=0;
		}
	  }
	}
	info();
	return 0;
}
int info()
{       
	int x,y,i;
	fprintf(fp5,"\n For Horizontal line y axis co-ordinates are:\n");
	for(i=0;i<4;i++)
	{
		fprintf(fp5," %d ",h[i]);
	}
	fprintf(fp5,"\n For Vertical line x axis co-ordinates is %d:\n",v);
	fprintf(fp5,"\n Left Eye Size: %dh(y) * %dw(x) ",(h[1]-h[0]-1),((v-1)-0));
	fprintf(fp5,"\n Left Eye Region start from (%dy,%dx) co-ordinate",(h[0]+1),0);
	fprintf(fp5,"\n Right Eye Size: %dh(y) * %dw(x) ",(h[1]-h[0]-1),(cs-(v+1)));
	fprintf(fp5,"\n Right Eye Region start from (%dy,%dx) co-ordinate",(h[0]+1),(v+1));
	fprintf(fp5,"\n Eye Size: %dh(y) * %dw(y)",(h[1]-h[0]-1),cs); 
	fprintf(fp5,"\n Eye Region start from (%dy,%dx) co-ordinate",(h[0]+1),0);
	fprintf(fp5,"\n Nose Size: %dh(y) * %dw(x) ",(h[2]-h[1]-1),cs);
	fprintf(fp5,"\n Nose Region start from (%dy,%dx) co-ordinate",(h[1]+1),0); 
	fprintf(fp5,"\n Mouth Size: %dh(y) * %dw(x) ",(h[3]-h[2]-1),cs);
	fprintf(fp5,"\n Mouth Region start from (%dy,%dx) co-ordinate",(h[2]+1),0);     
	fprintf(fp6,"P2\n# Created by IrfanView\n%d %d\n255\n",cs,rs);
	for(y=0;y<rs;y++)
	{
	  for(x=0;x<cs;x++)
	  {
		fprintf(fp6," %d ",b[y][x]);
      }
	}
	eye();
	return 0;
}
int eye()
{
	int y,x;
	for(y=(h[0]+1);y<h[1];y++)
	{
	  for(x=0;x<cs;x++)
	  {
		e[(y-(h[0]+1))][x]=b[y][x];
	  }
	}
	fprintf(fp2,"P2\n# Created by IrfanView\n%d %d\n255\n",cs,(h[1]-h[0]-1));
	for(y=0;y<(h[1]-h[0]-1);y++)
	{
		for(x=0;x<cs;x++)
		{
			fprintf(fp2," %d ",e[y][x]);
		}
	}
	nose();
	return 0;
}
int nose()
{
	int y,x;
	for(y=(h[1]+1);y<h[2];y++)
	{
	  for(x=0;x<cs;x++)
	  {
		n[(y-(h[1]+1))][x]=b[y][x];
	  }
	}
	fprintf(fp3,"P2\n# Created by IrfanView\n%d %d\n255\n",cs,(h[2]-h[1]-1));
	for(y=0;y<(h[2]-h[1]-1);y++)
	{
		for(x=0;x<cs;x++)
		{
			fprintf(fp3," %d ",n[y][x]);
		}
	}
	mouth();
	return 0;
}
int mouth()
{
	int y,x;
	for(y=(h[2]+1);y<h[3];y++)
	{
	  for(x=0;x<cs;x++)
	  {
		m[(y-(h[2]+1))][x]=b[y][x];
	  }
	}
	fprintf(fp4,"P2\n# Created by IrfanView\n%d %d\n255\n",cs,(h[3]-h[2]-1));
	for(y=0;y<(h[3]-h[2]-1);y++)
	{
		for(x=0;x<cs;x++)
		{
			fprintf(fp4," %d ",m[y][x]);
		}
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
	fclose(fp6);
	return 0; 
}

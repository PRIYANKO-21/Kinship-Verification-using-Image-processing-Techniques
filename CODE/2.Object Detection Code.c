#include<stdio.h>
#include<conio.h>
#include<math.h>
int n[512][512],m[512][512],e[512][512];
int rn[512][512],rm[512][512],re[512][512];
int marke[512][512],markn[512][512],markm[512][512];
FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
int me[10],mn[10],mm[10];
int meane,meann,meanm;
int T=25;
int rse=13,cse=64;
int rsn=18,csn=64;
int rsm=13,csm=64;
int mrse,mcse,mrsn,mcsn,mrsm,mcsm;
int main()
{
	fp1 = fopen("Eye.txt","r");
	fp2 = fopen("Nose.txt","r");
	fp3 = fopen("Mouth.txt","r");
	fp4 = fopen("ED(Eye)+25.pgm","w");
	fp5 = fopen("ED(Nose)+25.pgm","w");
	fp6 = fopen("ED(Mouth)+25.pgm","w");
	resize();
	return 0;
}
int resize()
{
	int y,x,k;
	for(y=0;y<rse;y++)
	{
	  for(x=0;x<cse;x++)
	     {
			fscanf(fp1,"%d",&k);
			e[y][x]=k;
		}
	}
	for(y=0;y<rsn;y++)
	{
	  for(x=0;x<csn;x++)
	     {
			fscanf(fp2,"%d",&k);
			n[y][x]=k;
		}
	}
	for(y=0;y<rsm;y++)
	{
	  for(x=0;x<csm;x++)
	     {
			fscanf(fp3,"%d",&k);
			m[y][x]=k;
		}
	}
	for(y=0;y<(rse+2);y++)
	{
	
	  for(x=0;x<(cse + 2);x++)
	     {
		if (x==0 || x==(cse+1)|| y==0 || y==(rse+1) )
		{
			re[y][x]=0;
		}
		else
			re[y][x]=e[y-1][x-1];	
	    }
	}
	for(y=0;y<(rsn+2);y++)
	{
	
	  for(x=0;x<(csn + 2);x++)
	     {
		if (x==0 || x==(csn+1)|| y==0 || y==(rsn+1) )
		{
			rn[y][x]=0;
		}
		else
			rn[y][x]=n[y-1][x-1];	
	    }
	}
	for(y=0;y<(rsm+2);y++)
	{
	
	  for(x=0;x<(csm + 2);x++)
	     {
		if (x==0 || x==(csm+1)|| y==0 || y==(rsm+1) )
		{
			rm[y][x]=0;
		}
		else
			rm[y][x]=m[y-1][x-1];	
	    }
	}
	mask(); 		
	return 0;   
}
int mask()
{
	int y,x;
	for(y=1;y<(rse + 1);y++)
	{
	  for(x=1;x<(cse + 1);x++)
        {
	         meane=re[y][x];
	         me[0]=re[y-1][x-1];
	         me[1]=re[y-1][x];
	         me[2]=re[y-1][x+1];
	         me[3]=re[y][x+1];
	         me[4]=re[y+1][x+1];
	         me[5]=re[y+1][x];
	         me[6]=re[y+1][x-1];
	         me[7]=re[y][x-1];
	         mrse=y;
	         mcse=x;
	         lbpe();
	    }
	}
	ope();
	for(y=1;y<(rsn + 1);y++)
	{
	  for(x=1;x<(csn + 1);x++)
        {
	         meann=rn[y][x];
	         mn[0]=rn[y-1][x-1];
	         mn[1]=rn[y-1][x];
	         mn[2]=rn[y-1][x+1];
	         mn[3]=rn[y][x+1];
	         mn[4]=rn[y+1][x+1];
	         mn[5]=rn[y+1][x];
	         mn[6]=rn[y+1][x-1];
	         mn[7]=rn[y][x-1];
	         mrsn=y;
	         mcsn=x;
	         lbpn();
	    }
	}
	opn();
	for(y=1;y<(rsm + 1);y++)
	{
	  for(x=1;x<(csm + 1);x++)
        {
	         meanm=rm[y][x];
	         mm[0]=rm[y-1][x-1];
	         mm[1]=rm[y-1][x];
	         mm[2]=rm[y-1][x+1];
	         mm[3]=rm[y][x+1];
	         mm[4]=rm[y+1][x+1];
	         mm[5]=rm[y+1][x];
	         mm[6]=rm[y+1][x-1];
	         mm[7]=rm[y][x-1];
	         mrsm=y;
	         mcsm=x;
	         lbpm();
	    }
	}
	opm();
	return 0;
}
int lbpe()
{
	int i;
	for(i=0;i<8;i++)
	{
		//If Threshold needed To be added add it with Mean
		if(me[i] >= (meane + T))
		  me[i]=1;
		else
		  me[i]=0;
	}
	validatee();
	return 0;
}
int lbpn()
{
	int i;
	for(i=0;i<8;i++)
	{
		//If Threshold needed To be added add it with Mean
		if(mn[i] >= (meann + T))
		  mn[i]=1;
		else
		  mn[i]=0;
	}
	validaten();
	return 0;
}
int lbpm()
{
	int i;
	for(i=0;i<8;i++)
	{
		//If Threshold needed To be added add it with Mean
		if(mm[i] >= (meanm + T))
		  mm[i]=1;
		else
		  mm[i]=0;
	}
	validatem();
	return 0;
}
int validatee()
{
	int k=me[0];
	int i=0,ch=3;
	if(me[0]==0 && me[1]==0 && me[2]==0 && me[3]==0 && me[4]==0 && me[5]==0 && me[6]==0 && me[7]==0)
	{
		ch=-2;
	}
	else
	{
		while(ch && (i<8))
		{
  			if(me[i]!=k)
  			{
    			k=me[i];
    			ch--;
  			}
			i++;
		}
	}
	if(ch>0)
	{
		marke[mrse-1][mcse-1]=255;
	}
	else
	{
		marke[mrse-1][mcse-1]=0;
	}
	return 0;
}
int ope()
{
	int y,x;
	fprintf(fp4,"P2\n# Created by Irfanview\n%d %d\n255",cse,rse);
	for(y=0;y<rse;y++)
	{
	  for(x=0;x<cse;x++)
	  {
		fprintf(fp4," %d ",marke[y][x]);
	  }
	}
	return 0; 
}
int validaten()
{
	int k=mn[0];
	int i=0,ch=3;
	if(mn[0]==0 && mn[1]==0 && mn[2]==0 && mn[3]==0 && mn[4]==0 && mn[5]==0 && mn[6]==0 && mn[7]==0)
	{
		ch=-2;
	}
	else
	{
		while(ch && (i<8))
		{
  			if(mn[i]!=k)
  			{
    			k=mn[i];
    			ch--;
  			}
			i++;
		}
	}
	if(ch>0)
	{
		markn[mrsn-1][mcsn-1]=255;
	}
	else
	{
		markn[mrsn-1][mcsn-1]=0;
	}
	return 0;
}
int opn()
{
	int y,x;
	fprintf(fp5,"P2\n# Created by Irfanview\n%d %d\n255",csn,rsn);
	for(y=0;y<rsn;y++)
	{
	  for(x=0;x<csn;x++)
	  {
		fprintf(fp5," %d ",markn[y][x]);
	  }
	}
	return 0; 
}
int validatem()
{
	int k=mm[0];
	int i=0,ch=3;
	if(mm[0]==0 && mm[1]==0 && mm[2]==0 && mm[3]==0 && mm[4]==0 && mm[5]==0 && mm[6]==0 && mm[7]==0)
	{
		ch=-2;
	}
	else
	{
		while(ch && (i<8))
		{
  			if(mm[i]!=k)
  			{
    			k=mm[i];
    			ch--;
  			}
			i++;
		}
	}
	if(ch>0)
	{
		markm[mrsm-1][mcsm-1]=255;
	}
	else
	{
		markm[mrsm-1][mcsm-1]=0;
	}
	return 0;
}
int opm()
{
	int y,x;
	fprintf(fp6,"P2\n# Created by Irfanview\n%d %d\n255",csm,rsm);
	for(y=0;y<rsm;y++)
	{
	  for(x=0;x<csm;x++)
	  {
		fprintf(fp6," %d ",markm[y][x]);
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

#include<stdio.h>
#include<conio.h>
#include<math.h>
int s[512][512],t[512][512],seq1[600],seq2[600],mat1[600],mat2[600];
int tby[100],tbx[100];
void values();
FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
int GP,MMS,MS;
int gp[10]={-10,-10,-10,-10,-10,-10,-5,-5,-5,-1};
int mms[10]={-1,-2,5,7,9,-5,-1,-2,0,0};
int ms[10]={10,10,10,10,10,10,5,5,5,1};
int score[10]={0,0,0,0,0,0,0,0,0,0};
float per[10]={0,0,0,0,0,0,0,0,0,0};
int M,N,y,x,v=1,in=0;
int main()
{
	int i;
	if(v==1)
	{
	fp1 = fopen("L1.txt","r");
	fp2 = fopen("L2.txt","r");
	fp3 = fopen("LN1.txt","r");
	fp4 = fopen("LN2.txt","r");
	fp5 = fopen("Score(L).txt","w");
	fprintf(fp5,"\tMatch\tMisMatch  Gap      Score        Percentage ");
	fprintf(fp5,"\n ------------------------------------------------------------------------------------------------------------------------ ");
	input();
	v++;
	in=0;
}
	if(v==2)
	{
	fp1 = fopen("R1.txt","r");
	fp2 = fopen("R2.txt","r");
	fp3 = fopen("RN1.txt","r");
	fp4 = fopen("RN2.txt","r");
	fp5 = fopen("Score(R).txt","w");
	fprintf(fp5,"\tMatch\tMisMatch  Gap      Score        Percentage ");
	fprintf(fp5,"\n ------------------------------------------------------------------------------------------------------------------------ ");
	input();
	v++;
	in=0;
}
	if(v==3)
	{
	fp1 = fopen("N1.txt","r");
	fp2 = fopen("N2.txt","r");
	fp3 = fopen("NN1.txt","r");
	fp4 = fopen("NN2.txt","r");
	fp5 = fopen("Score(N).txt","w");
	fprintf(fp5,"\tMatch\tMisMatch  Gap      Score        Percentage ");
	fprintf(fp5,"\n ------------------------------------------------------------------------------------------------------------------------ ");
	input();
	v++;
	in=0;
}
	if(v==4)
	{
	fp1 = fopen("M1.txt","r");
	fp2 = fopen("M2.txt","r");
	fp3 = fopen("MN1.txt","r");
	fp4 = fopen("MN2.txt","r");
	fp5 = fopen("Score(M).txt","w");
	fprintf(fp5,"\tMatch\tMisMatch  Gap      Score        Percentage ");
	fprintf(fp5,"\n ------------------------------------------------------------------------------------------------------------------------ ");
	input();
	v++;
}
fp6=fopen("score(total).txt","w");
	fprintf(fp6,"\tMatch\tMisMatch  Gap      Score        Percentage ");
for(i=0;i<10;i++)
	{

	fprintf(fp6,"\n \t %d \t %d \t %d \t %d \t %f",ms[i],mms[i],gp[i],score[i],per[i]/4);
  }
	return 0;
}
int input()
{
	int i,k,l;
	fscanf(fp3,"%d",&k);
	M=k;
	fscanf(fp4,"%d",&l);
	N=l;
	for(i=0;i<M;i++)
	{
			fscanf(fp1,"%d",&k);
			seq1[i]=k;
	}
	for(i=0;i<N;i++)
	{
			fscanf(fp2,"%d",&k);
			seq2[i]=k;
	}
	values();
	return 0;
}int sm()
{
	int D,U,L,i,j,y=M+1,x=N+1;
	s[0][0]=0;
	t[0][0]=0;
	//UP=-2,Left=-1,Diagonal=1,UP+Left=-3,
	//UP+Diagonal=-4,Left+Diagonal=-5;UP+Left+Diagonal=-6.
	for(i=1;i<y;i++)
	{
		s[i][0]=(s[i-1][0])+GP;
		t[i][0]=-2;
	}
	for(j=1;j<x;j++)
	{
		s[0][j]=(s[0][j-1])+GP;
		t[0][j]=-1;
	}
	for(i=1;i<y;i++)
		{
			for(j=1;j<x;j++)
			{
				if(seq1[i-1]==seq2[j-1])
					D=s[i-1][j-1]+MS;
				else
					D=s[i-1][j-1]+MMS;
				U=s[i-1][j]+GP;
				L=s[i][j-1]+GP;
				if(D>U && D>L)
				{
					s[i][j]=D;
					t[i][j]=1;
				}
				else if(D<U && U>L)
				{
					s[i][j]=U;
					t[i][j]=-2;
				}
				else if(L>U && L>D)
				{
					s[i][j]=L;
					t[i][j]=-1;
				}
				else if(D==U && U>L)
				{
					s[i][j]=D;
					t[i][j]=-4;
				}
				else if(U==L && L>D)
				{
					s[i][j]=L;
					t[i][j]=-3;
				}
				else if(L==D && L>U)
				{
					s[i][j]=D;
					t[i][j]=-5;
				}
				else if(L==D && L==U)
				{
					s[i][j]=D;
					t[i][j]=-6;
				}
			}
		}
/*	printf("\nScore Matrix:");
	for(i=0;i<y;i++)
	{
		printf("\n");
		for(j=0;j<x;j++)
		{
			printf("   %d   ",s[i][j]);
		}
	}
	
	printf("\nArrow Matrix:");
	for(i=0;i<y;i++)
	{
		printf("\n");
		for(j=0;j<x;j++)
		{
			printf("   %d   ",t[i][j]);
		}
	}
	*/	
	tb();		
	return 0;
}
int tb()
{
	int i,j,max=s[0][0],Nx,Ny,k=1,y=M+1,x=N+1;
	Ny=M;
	Nx=N;
	tby[0]=Ny;
	tbx[0]=Nx;
//	printf("\nTraceback Flow: ");
//	printf("(%d,%d)",tby[0],tbx[0]);
	while(t[Ny][Nx]!=0)
	{
	//	printf("-->");
			if(t[Ny][Nx]==1 || t[Ny][Nx]==-5 || t[Ny][Nx]==-6 || t[Ny][Nx]==-4 )
			{
				Ny--;
				tby[k]=Ny;
				Nx--;
				tbx[k]=Nx;
			}
			else if(t[Ny][Nx]==-1)
			{
				Nx--;
				tby[k]=Ny;
				tbx[k]=Nx;	
			}
			else if(t[Ny][Nx]==-2)
			{
				Ny--;
				tby[k]=Ny;
				tbx[k]=Nx;
			}
			else if(t[Ny][Nx]==-3)
			{
				if(Ny>Nx)
				{
					Ny--;
					tby[k]=Ny;
					tbx[k]=Nx;
				}
				else if(Nx>Ny)
				{
					Nx--;
					tby[k]=Ny;
					tbx[k]=Nx;
				}
				else
					Nx--;
					tby[k]=Ny;
					tbx[k]=Nx;
					
			}
		//	printf("(%d,%d)",tby[k],tbx[k]);
			k++;
			//I don't know actually what to do when t[Ny][Nx]==-3
	}	
	ali(k);
	return 0;
}
int ali(int k)
{
	int i=0,j=0,p,q,f,v,l,chk;
	if(tby[0]==M && tbx[0]==N)
	{
		p=0;
		q=0;
		for(f=0;f<(k-1);f++)
		{
			if(t[tby[f]][tbx[f]]==1 || t[tby[f]][tbx[f]]==-4 || t[tby[f]][tbx[f]]==-5 || t[tby[f]][tbx[f]]==-6)
			{
				mat1[i]=seq1[M-1-p];
				i++;
				p++;
				mat2[j]=seq2[N-1-q];
				j++;
				q++;
			}
			else if(t[tby[f]][tbx[f]]==-1)
			{
				mat1[i]=-10;
				i++;
				mat2[j]=seq2[N-1-q];
				j++;
				q++;
			}
			else if(t[tby[f]][tbx[f]]==-2)
			{
				mat1[i]=seq1[M-1-p];
				i++;
				p++;
				mat2[j]=-10;
				j++;
			}
			else if(t[tby[f]][tbx[f]]==-3)
			{
				if((M-f)>(N-f))
				{
					mat1[i]=-10;
					i++;
					mat2[j]=seq2[N-1-q];
					j++;
					q++;
				}
				else if((M-f)<(N-f))
				{
					mat1[i]=seq1[M-1-p];
					i++;
					p++;
					mat2[j]=-10;
					j++;
				}
				else 
				{
					mat1[i]=-10;
					i++;
					mat2[j]=seq2[N-1-q];
					j++;
					q++;
				}
			}
		}
/*		printf("\nmat1[]=");
		for(l=0;l<(k-1);l++)
		{
			printf("  %d  ",mat1[l]);
		}
		printf("\nmat2[]=");
		for(l=0;l<(k-1);l++)
		{
			printf("  %d  ",mat2[l]);
		}
*/		
		chk=0;
		sco(k);
	}
	return 0;
}
int sco(int k)
{
	int tot,j,m=0,mm=0,g=0,sum=0;
		for(j=0;j<(k-1);j++)
		{
			if(mat1[j]==-10 || mat2[j]==-10)
			{
				sum+=GP;
				g++;
			}
			else
			{
				if(mat1[j]==mat2[j])
				{
					sum+=MS;
					m++;
				}
				else
				{
					sum+=MMS;
					mm++;
				}
			}
		}
	if(M<N)
		tot=MS*N;
	else if(N<M)
		tot=MS*M;
	else
		tot=MS*N;
	printf("\n(%d * %d)+(%d * %d)+(%d * %d)=%d\nPercentage is=(%d/%d)*100=%f",m,MS,mm,MMS,g,GP,sum,sum,tot,((sum * 100)/tot));
	score[in]=score[in]+sum;
	per[in]=per[in]+((sum * 100)/tot);
	in++;
	fprintf(fp5,"\n \t %d \t %d \t %d \t %d \t (%d/%d)*100=%f",MS,MMS,GP,sum,sum,tot,((sum * 100)/tot));
	return 0;
}
int op()
{
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
	fclose(fp6);
	return 0;
}
void values()
{
	int i;
/*	for(GP=-5;GP<=1;GP++)
	{
		for(MMS=0;MMS<=5;MMS++)
		{
			for(MS=1;MS<=5;MS++)
			{
			sm();	
			}
		}
	}
	*/
	for(i=0;i<10;i++)
	{
		GP=gp[i];
		MMS=mms[i];
		MS=ms[i];
		sm();
	}
	op();
}

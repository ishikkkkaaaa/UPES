/*
tat=wt+bt
tat=ct+at
*/


#include<stdio.h>
int main()
{
int i,n,min,k=1,btime=0;
int bt[10],temp,j,at[10],wt[10],tt[10],ct[10],p[10]={1,2,3,4,5,6,7,8,9,10},ta=0,sum=0;
printf("\nEnter the No. of processes :");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("\tEnter the burst time of %d process :",i+1);
scanf(" %d",&bt[i]);
printf("\tEnter the arrival time of %d process :",i+1);
scanf(" %d",&at[i]);
}

/*Sorting According to Arrival Time*/

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(at[i]<at[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=at[j];
at[j]=at[i];
at[i]=temp;
temp=bt[j];
bt[j]=bt[i];
bt[i]=temp;
}
}
}
/*arranging of table*/

for(j=0;j<n;j++)
{
btime=btime+bt[j];
min=bt[k];
for(i=k;i<n;i++)
{
if (btime>=at[i] && bt[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=at[k];
at[k]=at[i];
at[i]=temp;
temp=bt[k];
bt[k]=bt[i];
bt[i]=temp;
}
}
k++;
}
wt[0]=0;

for(i=0;i<n;i++)
{
ta=ta+bt[i];
tt[i]=ta-at[i];
ct[i]=tt[i]-at[i];
}
printf("\n RESULT:");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Completion" );
for(i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],ct[i]);
}
return 0;
}

#include<stdio.h>
int main()
{
 int p,ts,travel=0,index=0,sum=0,i,j;
 printf("Enter the no. of processes: ");
 scanf("%d",&p);
 int bt[p];
 printf("\nEnter the burst times: ");
 for(i=0;i<p;i++)
 scanf("%d",&bt[i]);
 printf("\nenter the time slice: ");
 scanf("%d",&ts);
 for(i=0;i<p;i++)
 {
  if(bt[i]%ts==0)
  sum+=bt[i]/ts;
  else
  sum+=((bt[i])/ts)+1;
 }
 int ar[sum+1],arp[sum+1];
 ar[0]=0;
 arp[0]=0;
 for(i=1;i<(sum+1);i++)
 {
  while(bt[index]==0)
  {
   index++;
   if(index==5)
   index=0;
  }
  if(bt[index]>=ts)
  {
   travel+=ts;
   bt[index]-=ts;
  }
  else if(bt[index]<ts)
  {
   travel+=bt[index];
   bt[index]-=bt[index];
  }
  ar[i]=travel;
  arp[i]=index+1;
  index++;
  if(index==5)
  index=0;
 }
 printf("\nGANTT CHART\n-----------\n");
 for(i=1;i<(sum+1);i++)
 printf("P%d ",arp[i]);
 printf("\n");
 for(i=0;i<(sum+1);i++)
 printf("%d ",ar[i]);

 int tat[p],pno=1,wt[p];
 for(i=0;i<p;i++)
 wt[i]=0;

 for(i=0;i<(sum+1);i++)
 {
  for(j=1;j<=p;j++)
  {
   if(arp[i]==j)
   tat[j-1]=ar[i];
  }
 }
 int stat=0,swt=0;

 int temp=0;
 for(j=1;j<=p;j++)
 {
  temp=0;
  for(i=0;i<(sum+1);i++)
  {
   if(arp[i]==j)
   { wt[j-1]+=ar[i-1]-temp;
    temp=ar[i];
   }
  }
 }

 for(i=0;i<p;i++)
 {
  stat+=tat[i];
  swt+=wt[i];
 }

 printf("\n\nTATs are : ");
 for(i=0;i<p;i++)
 printf("%d ",tat[i]);
 printf("\n\nWTs are : ");
 for(i=0;i<p;i++)
 printf("%d ",wt[i]);
 printf("\n\nAvg TAT is: %f & Avg WT is: %f \n",(float)stat/(float)p,(float)swt/(float)p);
}

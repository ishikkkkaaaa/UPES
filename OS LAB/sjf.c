#include<stdio.h>
#define max 30
int main(void)
{
  int i,j,n,t,p[max],bt[max],wt[max],tat[max];

  printf("Enter the number of process:");
  scanf("%d",&n);

printf("Enter the Process number:");
for(i=0;i<n;i++)
{
  scanf("%d",&p[i]);
}
printf("Enter the burst time of the process:");
for(i=0;i<n;i++)
{
  scanf("%d",&bt[i]);
}
//applies bubble sort technique, to sort acc to their burst time
for(i=0;i<n;i++)
{
  for(j=0;j<n-i-1;j++)
  {
    if(bt[j]>bt[j+1])
    {
      //for burst time
      t=bt[j];
      bt[j]=bt[j+1];
      bt[j+1]=t;

      //for process number
      t=p[j];
      p[j]=p[j+1];
      p[j+1]=t;
    }
  }
}
printf("process\tburst time\twaiting time\tturn around time\n");
for(i=0;i<n;i++)
{
  wt[i]=0;
  tat[i]=0;
  for(j=0;j<i;j++)
  {
    wt[i]=wt[i]+bt[j];
  }
tat[i]=wt[i]+bt[i];

printf("%d\t %d\t\t %d\t\t %d\n",p[i],bt[i],wt[i],tat[i]);
}
return 0;
}

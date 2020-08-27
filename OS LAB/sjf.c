#include<stdio.h>
# define max 30
int main()
{
  int i,j,n,temp1,temp2,p[max],bt[max],wt=0;
  printf("Enter the number of prcoess:");
  scanf("%d",&n);
  printf("process number \n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
  }
  printf("Enter the burst time of the process:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&bt[i]);
  }
  //bubble sortingg
  for(i=1;i<n;i++)
  {
    for(j=0;j<n-i;j++)
    {
      if(bt[j]>bt[j+1])
      {
        //burst time sorting
        temp1=bt[j];
        bt[j]=bt[j+1];
        bt[j+1]=temp1;
        //process no.
        temp2=p[j];
        p[j]=p[j+1];
        p[j+1]=temp2;
      }
    }
  }
	for(int j=0;j<n;j++){
		if(j==0)
    //first process, then waiting time is zero
    {
			printf("The waiting time of process %d is: %d",p[j],wt);
			printf("\n");
	    }
		else{
      //fcfs
			wt=wt+bt[j-1];
			printf("The waiting time of process %d is: %d",p[j],wt);
			printf("\n");
			}
	}
  return(0);
}

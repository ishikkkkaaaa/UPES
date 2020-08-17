#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>


struct Process
{
	char pname[10];
	int arr_time;
	int burst_time;
	int priority;
	int wt,tat;
};

void Input_Process(struct Process* P ,int n,bool priority);

void FCFS(struct Process* P ,int n);

void Output_Process(struct Process* P ,int n);

int main()
{
	bool flag=false;
	int n,choice;
	printf("Enter number of processes:");
	scanf("%d",&n);
	struct Process* P = (struct Process*)malloc(n*sizeof(struct Process));

	FCFS(P,n);

	Output_Process(P,n);
}

void Input_Process(struct Process* P ,int n,bool priority)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\nEnter %d process name:",i+1);
		scanf("%s",P[i].pname);
		printf("Enter %d arrival time:",i+1);
		scanf("%d",&P[i].arr_time);
		printf("Enter %d burst time:",i+1);
		scanf("%d",&P[i].burst_time);
		if(priority)
		{
			printf("Enter %d priority:",i+1);
			scanf("%d",&P[i].priority);
		}
		else
			P[i].priority = 1;
	}
	//to sort by arrival time
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(P[j].arr_time > P[j+1].arr_time)
			{
				struct Process temp = P[j];
				P[j] = P[j+1];
				P[j+1]=temp;
			}
		}
	}
}

void FCFS(struct Process* P ,int n)
{
	Input_Process(P,n,false);

	int t = 0,i;
	for(i=0;i<n;i++)
	{
		if(t < P[i].arr_time)
			t = P[i].arr_time;
		P[i].wt = t-P[i].arr_time;
		P[i].tat = P[i].burst_time+P[i].wt;
		t = t+P[i].burst_time;
	}
}
void Output_Process(struct Process* P ,int n)
{
	int i;
	printf("\nNAME\t\tARRIVAL_TIME\t\tBURST_TIME\t\tPRIORITY\tWAITING_TIME\tTURN_AROUND_TIME\n");
	for(i=0;i<n;i++)
		printf("%s\t\t%d\t\t\t%d\t\t\t%d\t\t%d\t\t%d\n",P[i].pname,P[i].arr_time,P[i].burst_time,P[i].priority,P[i].wt,P[i].tat);
	double wt=0,tat=0;
	for(i=0;i<n;i++)
	{
		wt += P[i].wt;
		tat += P[i].tat;
	}
	wt /= n;
	tat /= n;

	printf("\nAverage:\nWaiting Time = %f\nTurn Around Time = %f",wt,tat);
}

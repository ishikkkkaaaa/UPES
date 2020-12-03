#include<stdio.h>

int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];
int main()
{

  printf("\n Enter the number of nodes:");
  scanf("%d",&n);
  printf("\n Enter the adjacency matrix:\n");
       for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
{
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
      cost[i][j]=999;
}
   visited[1]=1;                      
   printf("\n");
   while(ne<n)
{
   for(i=1,min=999;i<=n;i++)
   for(j=1;j<=n;j++)
   if(cost[i][j]<min)
   if(visited[i]!=0)
{
   min=cost[i][j];
   a=u=i;
   b=v=j;
}
    if(visited[u]==0 || visited[v]==0)
{
     printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
     mincost+=min;
     visited[b]=1;
}
      cost[a][b]=cost[b][a]=999;
}
     printf("\n Minimun cost=%d",mincost);

}


// lib fuctions, operations used->find and view
//u and v are the two vertcies of an edge
//find operation, tells which set it belongs to
//u=v , cycle detected, thus we dont take it
//u=!v, we take union and make a new set
//repeat, until done for all the edges
//
//graph vertices, disjoint set
//operations

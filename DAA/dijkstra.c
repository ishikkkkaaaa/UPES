
//create cost matrix c[][] from adjancy matrix adj[][]. c[i][j] is the cost from vertex i to j.
//if there is no edge btw i and j then c[i][j] is infinity
//array visited is to be initialize 0
//if the vertex 0 is the source vertex then visited[0]is marked as 1
#include<stdio.h>
#define MAX 10
#define INF 99999
int main()
{
  int G[MAX][MAX],n,start;
  int i,j;

  printf("Enter the number of vertices:\n");
  scanf("%d",&n);

  printf("Enter the graph:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&G[i][j]);
    }
  }

printf("Enter the starting node: \n");
scanf("%d", &start);

//function call
//G is the adjacent matrix
dijk(G,n,start);

return 0;
}
void dijk(int G[][],n,start)

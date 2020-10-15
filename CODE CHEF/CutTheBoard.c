/*https://www.codechef.com/problems/CUTBOARD*/

#include<stdio.h>
int main(void)
{
  int m,n,i;
  scanf("%d",&i);
  while(i--)
  {
    scanf("%d %d",&m,&n);
    printf("%d",(m-1)*(n-1));
  }
  return 0;
}

/* https://www.codechef.com/problems/DIFFSUM */
#include<stdio.h>
int main(void)
{
  int n1,n2,diff=0,sum=0;
  scanf("%d %d",&n1,&n2);
  if(n1>n2)
  {
    diff= n1 - n2 ;
    printf("%d",diff);
  }

  else
  {
    sum= n1 + n2 ;
    printf("%d",sum);
  }
  return 0;
}

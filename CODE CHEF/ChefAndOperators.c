/*https://www.codechef.com/problems/CHOPRT*/
#include<stdio.h>
int main(void)
{
  int i,m,n;
  printf("Enter the number of problems");
  scanf("%d",&i);
  while(i--)
  {
    printf("Enter two digits:");
    scanf("%d %d",&m,&n);
    if(m>n)
    {
      printf("> \t");
    }
    if(m<n)
    {
      printf("< \t");
    }
    if(m==n)
    {
      printf("= \t");
    }
    }
  return 0;
  }

#include<stdio.h>
int fib(int);

int main()
{
  int n,i;

  printf("Enter the terms:");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    printf("%d",fib(i));
    printf("\n");
  }
  return 0;
}
int fib(int a)
{
  if(a==0 || a==1)
  {
    return a;
  }
  else
  {
    return fib(a-1)+ fib(a-2);
  }
}

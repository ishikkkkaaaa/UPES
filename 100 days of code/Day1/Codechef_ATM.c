#include <stdio.h>
int main()
{
    int n;
    double x;
    scanf("%d %lf",&n,&x);

    if((n%5==0) &&(n+0.50<x))
    {
       x=x-n-0.50;
     }
       printf("%0.2lf",x);
       return 0;

}

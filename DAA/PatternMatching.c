#include<stdio.h>
int main()
{
  int ls,lp,max=0,n,i,a,j,flag;
  printf("Enter the number of elements ");
  scanf("%d", &ls);
  int array[n];
  printf("Enter the elements one by one \n");
  for (i = 0; i < n; i++)
  {
      scanf("%d", &array[i]);
  }
  printf("Enter the number of elements to be matched ");
  scanf("%d", &lp);
  int array[a];
  printf("Enter the elements one by one \n");
  for (j = 0; j < a; j++)
  {
      scanf("%d", &array[j]);
  }

max= (ls - lp + 1);

for(i=1;i<=max;i++)
{flag=true;
 for(j=1;j<= lp && flag true ; j++)
 { if(array[j]!=array[j+i-1])
    { flag=false
         }
    }
  if(flag=true)
      {return i;
            }
          }
            return(0);
}

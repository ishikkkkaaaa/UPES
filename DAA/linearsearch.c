#include <stdio.h>

int main()
{
    int i,num,n,data;

    printf("Enter the number of elements ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements one by one \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the element to be searched ");
    scanf("%d", &data);
    /*  Linear search begins */
    for (i = 0; i < n ; i++)
    {
        if (data == array[i] )
        {
            printf("Element is present in the array at position %d",i+1);
            break;
        }
    else
        {
          if(i==n)
          printf("Element is not present in the array\n");
      }
    }
      return(0);
}

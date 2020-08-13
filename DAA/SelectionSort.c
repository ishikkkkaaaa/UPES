#include <stdio.h>
int main()
 {
    int *data,i,j,n,steps,temp;

    printf("Enter the value of n\n");
    scanf("%d", &n);

    data = (int*)malloc(n*sizeof(int));

    printf("Enter element:\n");
    for(i=0;i<=n-1;i++)
      {
       scanf("%d",&data[i]);
    }

    for(i=0; i<n; i++)
	{
    	for(j=i+1; j<n; j++)
     	{
        	 if(data[i]>data[j])
/* To sort in descending order, change > to <. */
          	{
            	 temp=data[i];
             	data[i]=data[j];
             	data[j]=temp;
         	}
    	}
	}

    printf("In ascending order: ");
    for(i=0; i<=n-1; i++)
        printf("%d  ",data[i]);
    return 0;
}

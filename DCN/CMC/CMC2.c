#include<stdio.h>

int main()
{
    int i,n[50],div[50],j,temp,quotient[20],z[10],f[20];

    //input first number(dividend),8 digits,larger number

    printf("Enter the 8 digit number(messenger):\n");
    for(i=0;i<8;i++)
    {
        scanf("%d",&n[i]);
    }

    //input divisor, 4 digit , smaller
    printf("Enter the divisor(generator):\n");
    for(i=0;i<4;i++)
    {
        scanf("%d",&div[i]);
    }

    //few zeroes are added in the first array
    //number of zero is equal to the number of digits,(divisor-1)

    for(i=8;i<12;i++)
    {
        n[i]=0;
    }
    //
    for(i=0;i<8;i++)
    {
    temp=i;
    if(n[i]==1)
    {
        for(j=0;j<4;j++)
        {
            if(n[temp]==div[j])
            {
                n[temp]=0;
                f[j]=0;
            }

            else
            {
                n[temp]=1;
                f[j]=1;
            }
                temp+=1;               
            }
            quotient[i]=1;
        }
        else
            quotient[i]=0;
    }

    printf("The quotient is->");
        for(i=0;i<8;i++)
        {
            printf("%d", quotient[i]);
        }

    printf("\nThe remainder/CRC is->");

    for(j=0;j<4;j++)
    printf("%d",f[j]);

    //printf("\n Codeword->");
    //printf("%d", f[j]+n[i]);
    return 0;
}

//if digit of two no. are not equal then at place of that digit 1 gets added in first array n[]
//after execution of both loops the final value of quotient & remaineder (f[])is displayed on the output screen 
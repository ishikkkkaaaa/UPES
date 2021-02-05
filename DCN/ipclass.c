#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b,c,d,i;
	int subnet=0,x=255,y=0;
	printf("ENTER THE IP ADDRESS: \n");
	scanf("%d.%d.%d.%d", &a,&b,&c,&d);

    for(i=1; i<100; i++)
    {
		printf("*");
	}

    printf("\n");

	if(a>=1 && a<=126)
	{
		printf("\nCLASS A\n");
		subnet=8;
	}
	else if(a>=128 && a<=191)
	{
		printf("\nCLASS B\n");
		subnet=16;
	}
	else if(a>=192 && a<=223)
	{
		printf("\nCLASS C\n");
		subnet=24;
	}
	else if(a>=224 && a<=239)
	{
		printf("\nCLASS D\n");
		printf("\n its a MULTICAST ADDRESS\n");
	}
	else if(a>=240 && a<=255)
	{
		printf("\nCLASS E\n");
		printf("\n its a RESERVED ADDRESS\n");
	}

	switch(subnet)
	{
		case 8:
                  printf("\nBROADCAST ADDRESS : %d.255.255.255\n",a);
                  printf("\nSUBNET MASK : %d.%d.%d.%d\n",x,y,y,y);
				  printf("\nNETWORK ID : %d.%d.%d.%d\n",a&x,b&y,c&y,d&y);
				  break;

		case 16:  printf("\nBROADCAST ADDRESS : %d.%d.255.255\n",a,b);
				  printf("\nSUBNET MASK : %d.%d.%d.%d\n",x,x,y,y);
				  printf("\nNETWORK ID : %d.%d.%d.%d",a&x,b&x,c&y,d&y);
				  break;

		case 24:  printf("\nBROADCAST ADDRESS : %d.%d.%d.255\n",a,b,c);
				  printf("\nSUBNET MASK : %d.%d.%d.%d\n",x,x,x,y);
				  printf("\nNETWORK ID : %d.%d.%d.%d",a&x,b&x,c&x,d&y);
				  break;
	}
    return 0;
}
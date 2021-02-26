#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	system("CLS");
	char mainstring[50];
	int len,l1;
	int carry=0;
	int j=0;

	char a[50],b[50],c[50],complement[100];

    long i,length;

	printf("STRING TO BE TRANSMITTED : \n");
    scanf("%s",&mainstring);
    len=strlen(mainstring);
    l1=len/2;
	for (i=0; i<len; i++)
	{
		if(i<l1);
		{
			a[i]=mainstring[i];
		}
		if(i>=l1)
		{
		    b[j]=mainstring[i];
		    j++;
		}
	}
	
	i=0;
	for(i=l1-1; i>=0; i--)
	{
		if(a[i]=='0' && b[i]=='0' && carry==0)
		{
			c[i]='0';
			carry=0;
		}
		else if(a[i]=='0' && b[i]=='0' && carry==1)
		{
			c[i]='1';
			carry=0;
		}
		else if( a[i]=='0' && b[i]=='1' && carry==0)
		{
			c[i]='1';
			carry=0;
		}
		else if( a[i]=='0' && b[i]=='1' && carry==1)
		{
			c[i]='0';
			carry=1;
		}
		else if( a[i]=='1' && b[i]=='0' && carry==0)
		{
			c[i]='1';
			carry=0;
		}
		else if( a[i]=='1' && b[i]=='0' && carry==1)
		{
			c[i]='0';
			carry=1;
		}
		else if( a[i]=='1' && b[i]=='1' && carry==0)
		{
			c[i]='0';
			carry=1;
		}
		else if( a[i]=='1' && b[i]=='1' && carry==1)
		{
			c[i]='1';
			carry=1;
		}
		else
		{	break;	}
	}
	printf("\n\n");
	for(i=0; i<l1; i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");
	for(i=0; i<l1; i++)
	{
		printf("%c",b[i]);
	}
	
	printf("\n========\n");

	for(i=0; i<l1; i++)
	{
		printf("%c",c[i]);
		complement[i]=c[i];
	}
	printf("\n\nCOMPLEMENT OF SUM: ");
	for(i=0; i<l1; i++)
	{
		if(complement[i]=='1')
		{
			complement[i]='0';
		}
		else
		{
			complement[i]='1';
		}
		printf("%c",complement[i]);
	}
	printf("\n\n\nDATA TRANSMITTED TO RECEIVER IS : ");
	printf("%s%s",mainstring,complement);
	

	return 0;
}

//1001100111100010                                                                                               
//11100010                                                                                                                              
//00100100                                                                                                                              
//10000100
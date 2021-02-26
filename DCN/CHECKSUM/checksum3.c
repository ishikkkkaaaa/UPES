#include<stdio.h>
#include<string.h>

char checksum(char *a, char*b){
	
	if(strlen(a)==strlen(b)){
		int length,i;
		length = strlen(a);
		char carry='0';
        
		for(i=length-1;i>=0;i--)
        {
			if(a[i]=='0' && b[i]=='0' && carry=='0')
            {
                b[i]='0';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='0' && carry=='1')
            {
                b[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='0')
            {
                b[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='1')
            {
                b[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='0')
            {
                b[i]='1';
                carry='0';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='1')
            {
                b[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='0')
            {
                b[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='1')
            {
                b[i]='1';
                carry='1';
 
            }
            else
                break;
        }
        for(i=length-1;i>=0;i--){
        	if(carry=='1' && b[i]=='1'){
        		b[i]='0';
        		carry='1';
			}
			else if(carry=='1' && b[i]=='0'){
				b[i]='1';
				carry='0';
			}
			else{
				break;
			}
		
		
		}
		printf("\tfunc  :  %s",b);
        
	}
	return b;
}

char complement(char *a , char *b){
	
	int i,length;
	length = strlen(a);
	for(i=0 ; i<length ; i++){
		if(a[i]=='0'){
			a[i]='1';
		}
		else if(a[i] == '1'){
			a[i] = '0';
		}

		
	}
	printf("\nCheck Sum = %s",a);
	printf("\nMessage = %s%s",b,a);
}

int reciever(char *msg , char *b){

	printf("\n\n!!!!       Reciever's end      !!!");
	int count,frame,i,j,k=0,leng;
	
	count = strlen(msg);
	leng = strlen(b);
	
	frame = count/leng;
	printf("\n\nreciever length = %d",leng);
	printf("\nReciever each legn = %d",frame);
	
	char rcvr[frame][20]; 
	  
	for(i=0;i<frame;i++){
		for(j=0;j<leng;j++){
			rcvr[i][j] = msg[k];
			k++;
		}
		rcvr[i][j+1]='\0';
	}	
	
	for(i=0;i<frame;i++){
		printf("\n Reciever Frame %d :-> %s",(i+1),rcvr[i]);
	}
	
	for(i = 0 ; i < frame-1 ; i++){
		printf("\tBefor ::  %s\n",rcvr[(i+1)]);
		checksum( rcvr[i] , rcvr[(i+1)] );
	}
	checksum(rcvr[frame-1],b);
	printf("\n\n\nFinal output : %s",b);
}



int main(){
	
	printf("\n!!!     Sender's end      !!!\n\n");
	int frames,i,j,k=0,count1=0,frame;
	char message[100];
	printf("Enter the total number of frames : ");
	scanf("%d",&frames);
	printf("Enter the message : ");
	scanf("%s",&message);
	
	char a='0';
 	
 	while(a!='\0'){
 		a = message[count1];
 		count1++;	
	 }
	count1--;
	printf("Count %d",count1);
	
	frame = count1/frames;
	printf("Frame %d",frame);

	char each[frames][20];   
	for(i=0;i<frames;i++){
		for(j=0;j<frame;j++){
			each[i][j] = message[k];
			k++;
		}
		each[i][j+1]='\0';
	}
		
	for(i=0;i<frames;i++){
		printf("\nFrame %d :-> %s",(i+1),each[i]);
	}
	
	for(i = 0 ; i < frames-1 ; i++){
		printf("\tBefor ::  %s\n",each[(i+1)]);
		checksum( each[i] , each[(i+1)] );
	}
		
	complement(each[frames-1],message);
	
	reciever(message,each[frames-1]);
	
	
}

m ,#include<stdio.h>
#define MAX 5

void push();
void pop();
void display();

int stack[MAX];
int top = -1;

main(){
	int choice, n;

	while(1){
		printf("enter the choice\n");
		printf("1. push\n2. pop\n3. display\n4. exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					push();
					break;
			case 2:
					pop();
					break;
			case 3:
					display();
					break;
			case 4:
					exit(1);
			default:
					printf("Wrong choice\n");
		}

	}
}
void push(){
	int n;
	if(top >= MAX-1)
		printf("stack overflow\n");
	else
	{
		top = top + 1;
		printf("enter the number to push");
			scanf("%d",&n);
		stack[top] = n;
	}
}
void pop(){
	if(top == -1)
		printf("stack is underflow\n");
	else
		top = top - 1;
}
void display(){
	int i = 0;
	if(top == -1)
		printf("stack is underflow\n");
	else{
			while(i <= top){
				printf("%d\n",stack[i]);
				i++;
			}

	}
}

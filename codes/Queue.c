#include<stdio.h>
#define MAX 5

void en_queue();
void de_queue();
void display();

int queue[MAX];
int rear = -1;
int front = -1;

main(){
	int choice, n;

	while(1){
		printf("enter the choice\n");
		printf("1. enqueue\n2. dequeue\n3. display\n4. exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					en_queue();
					break;
			case 2:
					de_queue();
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
void en_queue(){
	int n;
	if(rear == MAX-1 )
		printf("queue overflow\n");
	else if(rear == -1){
		rear = front = 0;
		printf("enter the number ");
		scanf("%d",&n);

		queue[rear] = n;
		}
	else{
		rear = rear + 1;
		printf("enter the number ");
		scanf("%d",&n);

		queue[rear] = n;
	}
}
void de_queue(){
	if(rear == -1)
		printf("queue is underflow\n");
	else if(front == rear)
		rear = front = -1;
	else
		front = front + 1;
}
void display(){
	int i = front;
	if(rear == -1)
		printf("queue is underflow\n");
	else{
			while(i <= rear){
				printf("%d\n",queue[i]);
				i++;
			}

	}
}

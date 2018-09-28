#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX 3

int count = 0;

struct park_stack{
	struct park_stack *next;
	char data[10];
};

struct park_stack *top = NULL;

void push(char num[]){
	
	struct park_stack *ptr;
	ptr = (struct park_stack*)malloc(sizeof(struct park_stack));
	strcpy(ptr -> data,num);

	if( top == NULL ){
		ptr -> next = NULL;
		top = ptr;
	}
	else{
		ptr -> next = top;
		top = ptr;
	}
	count++;
}

void display_stack(){

	printf("\nStack order:\n");
	struct park_stack *ptr;
	ptr = top;
	while( ptr -> next != NULL){
		printf("%s\n",ptr -> data);
		ptr = ptr ->  next;
	}
	printf("%s\n",ptr -> data);

}

struct park_stack *pop(){

	struct park_stack *ptr;
	char num[10];

	ptr = top;

	strcpy(num,ptr -> data);

	if ( top == NULL ){
		printf("error");
	} 
	else{
		top = top -> next;
	}
	printf("\n%s will be deleted from stack\n",ptr -> data);
	return ptr;
}

struct garage_queue{
	struct garage_queue *next;
	char data[10];
};

struct waiting_queue{
	struct waiting_queue *next;
	char data[10];
};

struct garage_queue *front = NULL;
struct garage_queue *rear = NULL;

void display(){

	struct garage_queue *ptr;
 	int i=1;

	ptr = front;

	if (front == NULL){
		printf("\nGarage is empty\n");
	}
	else{

		printf("\nVehicle order in the garage\n");

		while(ptr -> next != NULL){
			printf("%d %s\n",i,ptr -> data);
			ptr = ptr -> next;
			i++;
		} 
		printf("%d %s",i,ptr -> data);
	}	

}

struct garage_queue * out_garage(struct garage_queue *front){
	
	struct garage_queue *ptr;
	char num[10];

	ptr = front;

	if( front == NULL ){
		printf("\nGarage is empty\n");
	}
	else{
		front = front -> next;
		strcpy(num,ptr -> data);
		push(num);
		free(ptr);
	}
	return front;
}

struct garage_queue* in_garage(struct park_stack *top){

	struct garage_queue *ptr;

	ptr = (struct garage_queue*)malloc(sizeof(struct garage_queue));

	strcpy(ptr -> data,top -> data);

	if( front == NULL ){
		ptr -> next = NULL;
		front = rear = ptr;
	} 
	else{
		ptr -> next = front;
		front = ptr;
	}

	return front;

}


int main(){
	
	int option,i;
	char num[10];
	struct garage_queue *ptr;
	struct park_stack *preptr;
	int pos = 0;

	printf("\nMAIN MENUE\n");
	printf("1. ARRIVAL\n");
	printf("2. DEPARTURE\n");
	printf("3. DISPLAY\n");
	printf("4. EXIT\n");

	do{
		printf("\nEnter your option : ");
		scanf("%d",&option);

		switch(option){
			case 1: 
				
				printf("Insert vehicle plate : ");
				scanf("%s",num);

				ptr = (struct garage_queue*)malloc(sizeof(struct garage_queue));

				strcpy(ptr -> data,num);

				if( count == MAX ){
					printf("\nPark is full.\n");
				}
				else{
		
					if( front == NULL ){
						ptr -> next = NULL;
						front = rear = ptr;
					}
					else{
						rear -> next = ptr;
						ptr -> next = NULL;
						rear = ptr;
					}
					printf("%s has arrived to the park",rear -> data);
					count++;
				}
				break;
			
			case 2:
				pos = 0;
				printf("\nEnter the vehicle number to be departed : ");
				scanf("%s",num);

				ptr = front;

				while( strcmp(ptr -> data,num) != 0 ){
					front = out_garage(front);
					ptr = front;
					pos++;
				}
				front = out_garage(front);
				pos++;
				printf("\n%s will be departed from the garage from %d position\n",num,pos);
				display_stack();
				display();
				for( i=1; i<=pos; ){
					if(i==1){
						preptr = pop();
						free(preptr);
						printf("\n%s departed from the garage \n",num);
						i++;
					}
					else{
						preptr = pop();
						front = in_garage(preptr);
						i++;
					}
				}
				printf("\nGarage has been relocated\n");
				count--;
				break;
			
			case 3:
				display();
				break;
			case 4: 
				break;
			default:
				printf("Enter a valid option\n");
				break;
		}

	}while( option != 4 );

	return 0;
}

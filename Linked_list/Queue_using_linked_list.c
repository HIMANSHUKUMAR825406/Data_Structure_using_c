#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct node *front=NULL,*rear=NULL;
void enqueue(){
  struct node* temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data: ");
  scanf("%d",&temp->data);
  temp->next=NULL;
  if(front==NULL&&rear==NULL){
    rear=front=temp;
  } 
  else{
    rear->next=temp;
    rear=temp;
  }
}
void dequeue(){
  struct node* temp=front;
  if(front==NULL &&rear==NULL){
    printf("Queue underflow\n");
    return;
  } 
  else if(front==rear){
    front=rear=NULL;
  }
  else{
    front=front->next;
  }
  free(temp);
}
void display(){
  if(front==NULL && rear==NULL) printf("Queue is empty");
  else{
    struct node* temp=front;
    while(temp!=NULL){
      printf("%d\t",temp->data);
      temp=temp->next;
    }
  }
  printf("\n");
}
void peek(){
  if (front==NULL&& rear==NULL) printf("Queue is empty\n");
  else printf("%d\n",front->data);
}
int main(void) {
  char choice='y';
  printf("Enter 1 for enqueue\n");
  printf("Enter 2 for dequeue\n");
  printf("Enter 3 for display\n");
  printf("Enter 4 for peek\n");
  while(choice=='y'){
    int select;
    printf("\nEnter the choice: ");
    scanf("%d",&select);
    switch(select){
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        peek();
        break;
      default:
        printf("Wrong choice entered\n");
    }
    printf("Want to continue(y/n): ");
    scanf(" %c",&choice);
  }
  printf("Sucessfully executed\n");
  return 0;
}

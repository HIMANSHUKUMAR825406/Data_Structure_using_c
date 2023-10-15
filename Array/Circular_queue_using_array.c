#include <stdio.h>
#define n 5
int arr[n];
int front=-1,rear=-1;
void enqueue(int num){
  if (front==-1&&rear==-1){
    front++;
    rear++;
    arr[rear]=num;
  }
  else if((rear+1)%n==front) printf("Queue overflow\n");
  else{
    rear=(rear+1)%n;
    arr[rear]=num;
  }
}
void dequeue(){
  if(front==-1&&rear==-1) printf("Queue underflow\n");
  else if(front==rear){
    front=-1;
    rear=-1;
  }
  else front=(front+1)%n;
}
void display(){
  if(front==-1 && rear==-1) printf("Queue is empty");
  else{
    int i=front;
    while(i!=rear){
      printf("%d\t",arr[i]);
      i=(i+1)%n;
    }
    printf("%d\t",arr[i]);
  }
  printf("\n");
}
void peek(){
  if(front==-1&&rear==-1) printf("Queue is empty");
  else printf("%d",arr[front]);
  printf("\n");
}
int main(void) {
  printf("Welcome\n");
  char choice='y';
  int select,ele;
  printf("Enter 1 for enqueue\n");
  printf("Enter 2 for dequeue\n");
  printf("Enter 3 for Display\n");
  printf("Enter 4 for peek\n");
  while(choice=='y'){
    printf("\nEnter the choice: ");
    scanf("%d",&select);
    switch(select){
      case 1:
        printf("Enter the element: ");
        scanf("%d",&ele);
        enqueue(ele);
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
        printf("Wrong choice entered!!\n");
    }
    printf("Want to continue(y/n): ");
    scanf(" %c",&choice);
  }
  return 0;
}

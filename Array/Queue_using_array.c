#include <stdio.h>
#include <stdbool.h>
#define size 7
int front=-1,rear=-1;
int queue[size];
bool isFull(){
  if(rear==size-1) return true;
  return false;
}
bool isEmpty(){
  if (front==-1&&rear==-1) return true;
  return false;
}
void enqueue(){
  if(isFull()){
    printf("Queue overflow\n");
    return;
  }
  int ele;
  printf("Enter the element: ");
  scanf("%d",&ele);
  if(isEmpty()){
    front++;
    rear++;
    queue[front]=ele;
  }
  else queue[++rear]=ele;
  return;
}
void dequeue(){
  if(isEmpty()){
    printf("Queue underflow\n");
    return;
  }
  int ele;
  if(front==rear){
    ele=queue[rear];
    front=rear=-1;
  }
  else ele=queue[front++];
  printf("Deleted element is %d\n",ele);
  return;
}
void display(){
  if(isEmpty()){
    printf("Queue is empty\n");
    return;
  }
  else{
    printf("The elements are: ");
    for(int i=front;i<=rear;i++) printf("%d\t",queue[i]);
  } 
  printf("\n");
  return;
}
int main(void) {
  printf("Enter 1 for Enqueue operation\n");
  printf("Enter 2 for Dequeue operation\n");
  printf("Enter 3 for Display operation\n");
  char c='y';
  int choice;
  while(c=='y'){
    printf("\nEnter the choice: ");
    scanf(" %d",&choice);
    switch(choice){
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      default:
        printf("Invalid choice!!\n");
        break;
    }
    printf("Want to continue(y/n): ");
    scanf(" %c",&c);
  }
  printf("\nPrograms ends!!!");
  return 0;
}

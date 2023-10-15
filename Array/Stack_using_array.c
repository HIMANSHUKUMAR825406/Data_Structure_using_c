#include <stdio.h>
#include <stdbool.h>
#define N 7
int stack[N];
int top=-1;
bool isEmpty(){
  if(top==-1) return true;
  return false;
}
bool isFull(){
  if(top==N-1) return true;
  return false;
}
void push(){
  if(isFull()){
    printf("Stack overflow\n");
    return;
  }
  int ele;
  printf("Enter the element: ");
  scanf("%d",&ele);
  stack[++top]=ele;
}
void pop(){
  if(isEmpty()){
    printf("Stack underflow\n");
    return;
  }
  printf("Deleted element: %d\n",stack[top]);
  top--;
}
void display(){
  if(isEmpty()){
    printf("Stack is empty\n");
    return;
  }
  printf("The elements are: ");
  for(int i=0;i<=top;i++){
    printf("%d\t",stack[i]);
  }
  printf("\n");
}
int main(void) {
  char c='y';
  int choice;
  printf("Enter 1 for insertion\n");
  printf("Enter 2 for deletion\n");
  printf("Enter 3 for Display\n");
  while(c=='y'){
    printf("\nEnter your choice: ");
    scanf(" %d",&choice);
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
      default:
        printf("Invalid choice entered\n");
        break;
    }
    printf("Want to continue (y/n): ");
    scanf(" %c",&c);
  }
  printf("\nProgram ends!!!");
  return 0;
}

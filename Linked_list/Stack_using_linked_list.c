#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;
};
struct node* insert(struct node** top){
  struct node* newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  int element;
  printf("Enter the element: ");
  scanf("%d",&element);
  newnode->data=element;
  newnode->next=*top;
  *top=newnode;
  return *top;
}
struct node* deletion(struct node** top){
  if (*top==NULL){
    printf("Stack underflow!!!\n");
    return *top;
  }
  struct node* newnode;
  newnode=*top;
  *top=(*top)->next;
  free(newnode);
  return *top;
}
void display(struct node* top){
  if(top==NULL){
    printf("Stack is empty!!!\n");
    return;
  }
  printf("Elements are: ");
  while(top!=NULL){
    printf("%d\t",top->data);
    top=top->next;
  }
  printf("\n");
  return;
}
int main(void) {
  struct node *top=NULL;
  char ch='y';
  int choice;
  printf("Enter 1 for insertion\n");
  printf("Enter 2 for deletion\n");
  printf("Enter 3 for traversal\n");
  while(ch=='y'){
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        insert(&top);
        break;
      case 2:
        deletion(&top);
        break;
      case 3:
        display(top);
        break;
      default:
        printf("Invalid choice entered!!!\n");
    }
    printf("\nWant to continue(y/n): ");
    scanf(" %c",&ch);
  }
  printf("Program executed succesfully!!!");
  return 0;
}

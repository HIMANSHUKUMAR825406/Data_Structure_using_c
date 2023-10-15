#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node*next,*prev;
};
void InsertAtHead(struct node**head){
  int d;
  printf("Enter the data: ");
  scanf("%d",&d);
  struct node* temp;
  temp=(struct node*)(malloc(sizeof(struct node)));
  temp->data=d;
  temp->prev=NULL;
  if(*head==NULL){
    temp->next=NULL;
    *head=temp;
  }
  else{
    temp->next=(*head);
    *head=temp;
  }
  return;
}
void InsertAtTail(struct node**head){
  if(*head==NULL){
    InsertAtHead(head);
    return;
  } 
  struct node* newnode;
  struct node* temp;
  newnode=(struct node*)(malloc(sizeof(struct node)));
  int element;
  printf("Enter the element: ");
  scanf("%d",&element);
  newnode->data=element;
  newnode->next=NULL;
  temp=*head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=newnode;
  newnode->prev=temp;
  return;
}
void deletion(struct node**head){
  if(*head==NULL){
    printf("List is empty\n");
    return;
  } 
  int element;
  printf("Enter the element to delete: ");
  scanf("%d",&element);
  struct node*prev=NULL,*curr=*head;
  if(curr->data==element){//Handling first element
    *head=(*head)->next;
    free(curr);
    return;
  }
  while(curr!=NULL&&curr->data!=element){
    prev=curr;
    curr=curr->next;
  }
  if(curr==NULL){
    printf("Element not found!!!\n");
    return;
  }
  prev->next=curr->next;
  curr->next->prev=prev;
  free(curr);
  return;
}
void display(struct node *head){
  if(head==NULL){
    printf("Linked list has no elements!!!\n");
    return;
  }
  printf("The elements are: ");
  while(head!=NULL){
    printf("%d\t",head->data);
    head=head->next;
  }
  printf("\n");
}
void search(struct node* head){
  int element,pos=1,check=0;
  printf("Enter the element to search: ");
  scanf("%d",&element);
  while(head!=NULL){
    if(head->data==element){
      printf("Element found at position %d\n",pos);
      check=1;
      return;
    }
    head=head->next;
    pos++;
  }
  if(check==0){
    printf("ELement not found!!\n");
    return;
  }
}
int main(void) {
  printf("Welcome\n");
  struct node *head=NULL;
  char ch='y';
  int choice;
  printf("Enter 1 for insertion at beginning\n");
  printf("Enter 2 for insertion at tail\n");
  printf("Enter 3 for deletion\n");
  printf("Enter 4 for display\n");
  printf("Enter 5 for searching\n");
  while(ch=='y'){
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        InsertAtHead(&head);
        break;
      case 2:
        InsertAtTail(&head);
        break;
      case 3:
        deletion(&head);
        break;
      case 4:
        display(head);
        break;
      case 5:
        search(head);
        break;
      default:
        printf("Enter choice entered!!\n");
    }
    printf("\nWant to continue(y/n): ");
    scanf(" %c",&ch);
  }
  printf("Program executed successfully!!!");
  return 0;
}

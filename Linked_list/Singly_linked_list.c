#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node*next;
};
void InsertAtHead(struct node**head){
  int d;
  printf("Enter the data: ");
  scanf("%d",&d);
  struct node* temp;
  temp=(struct node*)(malloc(sizeof(struct node)));
  temp->data=d;
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
  return;
}
void InsertAtPos(struct node **head){
  if(*head==NULL){
    InsertAtHead(head);
    return;
  }
  struct node *temp=*head;
  int pos,t=1,element;
  printf("Enter the position to enter: ");
  scanf("%d",&pos);
  while(temp->next!=NULL&&t<pos-1){
    temp=temp->next;
    t++;
  }
  printf("Enter the element: ");
  scanf("%d",&element);
  struct node* newnode;
  newnode=(struct node *)(malloc(sizeof(struct node)));
  newnode->data=element;
  newnode->next=temp->next;
  temp->next=newnode;
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
  printf("Enter 3 for insertion at pos\n");
  printf("Enter 4 for deletion\n");
  printf("Enter 5 for display\n");
  printf("Enter 6 for searching\n");
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
        InsertAtPos(&head);
        break;
      case 4:
        deletion(&head);
        break;
      case 5:
        display(head);
        break;
      case 6:
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

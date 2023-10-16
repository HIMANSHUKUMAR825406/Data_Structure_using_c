#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* left,*right;
};
struct node* createnode(int val){
  struct node* root=(struct node*)malloc(sizeof(struct node));
  root->data=val;
  root->left=NULL;
  root->right=NULL;
  return root;
}
void inorder(struct node *root){
  if(root!=NULL){
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
  }
}
void preorder(struct node *root){
  if(root!=NULL){
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(struct node *root){
  if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
  }
}
void insert(struct node**root,int ele){
  if((*root)==NULL){
    (*root)=createnode(ele);
    return;
  } 
  if((*root)->data<ele) insert(&((*root)->right),ele);;
  if((*root)->data>ele) insert(&((*root)->left),ele);
}
struct node* nextinorder(struct node**root){
  struct node*curr=*root;
  while(curr&&curr->left!=NULL)
    curr=curr->left;
  return curr;
}
void delete(struct node**root,int ele){
  if((*root)==NULL) printf("\nElement not found!!\n");
  else if((*root)->data<ele) delete(&((*root)->right),ele);
  else if((*root)->data>ele) delete(&((*root)->left),ele);
  else if((*root)->left&&(*root)->right){
    struct node* next=nextinorder(&((*root)->right));
    (*root)->data=next->data;
    delete(&((*root)->right),next->data);
  }
  else{
    struct node**temp=root;
    if((*root)->left==NULL&&(*root)->right==NULL) (*root)=NULL;
    else if((*root)->left!=NULL) (*root)=(*root)->left;
    else if((*root)->right!=NULL) (*root)=(*root)->right;
    free(*temp);
  }
}
int main(void) {
  printf("Welcome\n");
  char ch='y';
  int ele;
  struct node *root=NULL;
  printf("Enter 1 for insertion\n");
  printf("Enter 2 for deletion\n");
  printf("Enter 3 for inorder traversal\n");
  printf("Enter 4 for preorder traversal\n");
  printf("Enter 5 for postorderorder traversal\n");
  while(ch=='y'){
    int choice;
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter element to insert: ");
        scanf("%d",&ele);
        insert(&root,ele);
        break;
      case 2:
        printf("Enter element to delete: ");
        scanf("%d",&ele);
        delete(&root,ele);
        break;
      case 3:
        inorder(root);
        break;
      case 4:
        preorder(root);
        break;
      case 5:
        postorder(root);
        break;
      default:
        printf("Invalid choice entered!!!\n");
    }
    printf("\nDo you want to continue(y/n): ");
    scanf(" %c",&ch);
  }
  printf("Program Executed successfully!!");
  return 0;
}

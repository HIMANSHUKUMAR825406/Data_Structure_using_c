#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#define N 100
char stack[N];
int top=-1;
bool isEmpty(){
  if(top==-1) return true;
  return false;
}
bool isFull(){
  if(top==N-1) return true;
  return false;
}
void push(char ele){
  if(isFull()){
    printf("Stack overflow\n");
    return;
  }
  stack[++top]=ele;
}
void pop(){
  if(isEmpty()){
    printf("Stack underflow\n");
    return;
  }
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
  char exp[100];
  printf("Enter the expression: ");
  fgets(exp, sizeof(exp), stdin);
  int i=0;
  for(i=0;i<strlen(exp);i++){
    if(exp[i]=='['||exp[i]=='{'||exp[i]=='(') push(exp[i]);
    else if(exp[i]==']'){
      if(isEmpty()) printf("Unbalanced\n");
      else if(stack[top]!='['){
        printf("Unbalanced\n");
        break;
      }
      else pop();
    }
    else if(exp[i]==')'){
      if(isEmpty()) printf("Unbalanced\n");
      else if(stack[top]!='('){
        printf("Unbalanced\n");
        break;
      }
      else pop();
    }
    else if(exp[i]=='}'){
      if(isEmpty()) printf("Unbalanced\n");
      else if(stack[top]!='{'){
        printf("Unbalanced\n");
        break;
      }
      else pop();
    }
  }
  if(isEmpty()) printf("Expression is balanced!!");
  return 0;
}

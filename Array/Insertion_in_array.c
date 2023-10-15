#include <stdio.h>
#define N 100
int main(void) {
  int size,ele,pos;
  printf("Enter the size of array: ");
  scanf("%d", &size);
  int arr[N];
  printf("Enter the elements: ");
  for(int i=0;i<size;i++) scanf("%d",&arr[i]);
  printf("Enter the element to insert: ");
  scanf("%d", &ele);
  printf("Enter the position: ");
  scanf("%d", &pos);
  size++;
  for(int i=size-1;i>=pos;i--) arr[i]=arr[i-1];//Shifting the elemtns to the right
  arr[pos-1]=ele;
  printf("Array after insertion: ");
  for(int i=0 ;i<size;i++) printf("%d ",arr[i]);
  return 0;
}

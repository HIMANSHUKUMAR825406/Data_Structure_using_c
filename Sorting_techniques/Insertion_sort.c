#include<stdio.h>
void swap(int *a,int*b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int main(void) {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the elements: ");
  for(int i=0;i<n;i++) scanf("%d",&arr[i]);
  for(int i=1;i<n;i++){
    for(int j=i;j>0;j--){
      if(arr[j-1]>arr[j]) swap(&arr[j],&arr[j-1]);
    }
  }
  printf("Element after sorting: \n");
  for(int i=0;i<n;i++){
    printf("%d\t",arr[i]);
  }
  return 0;
}

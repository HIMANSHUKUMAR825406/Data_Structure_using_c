#include <stdio.h>
int swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int main(void) {
  int n;
  printf("Enter the size: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the array: ");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  int j=n;
  while(j>=0){
    for(int i=0;i<j-1;i++){
      if(arr[i]>arr[i+1]) swap(&arr[i],&arr[i+1]);
    }
    j--;
  }
  printf("Sorted array is: ");
  for(int i=0;i<n;i++){
    printf("%d\t",arr[i]);
  }
  return 0;
}

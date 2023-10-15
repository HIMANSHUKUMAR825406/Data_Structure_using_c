#include <stdio.h>
void swap(int *a,int*b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int main(void) {
  int n;
  printf("Enter size of array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter elements: ");
  for(int i=0;i<n;i++) scanf("%d",&arr[i]);
  for(int i=0;i<n;i++){
    int min=i;
    for(int j=i;j<n;j++){
      if(arr[min]>arr[j]) min =j;
    }
    swap(&arr[min],&arr[i]);
  }
  for(int i=0;i<n;i++) printf("%d\t",arr[i]);
  return 0;
}

#include <stdio.h>
#include<time.h>
int linearsearch(int ele,int n,int *arr){
  for(int i=0;i<n;i++){
    if(arr[i]==ele) return i;
  }
  return -1;
}
int main(void) {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the element: ");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  time_t start,end;
  start=time(NULL);
  int ele;
  printf("Enter the element to search: ");
  scanf("%d",&ele);
  int index=linearsearch(ele,n,arr);
  if(index==-1) printf("Element not found!!\n");
  else printf("Element occur at index %d\n",index);
  end=time(NULL);
  printf("Execution time for linear search is : %f seconds\n",difftime(end,start));
  return 0;
}

#include <stdio.h>
#include<time.h>
int binarysearch(int ele,int n,int *arr){
  int s=0,e=n-1;
  int mid=s+(e-s)/2;
  while(s<=e){
    if(arr[mid]==ele) return mid;
    else if(arr[mid]>ele) e=mid-1;
    else if(arr[mid]<ele) s=mid+1;
    mid=s+(e-s)/2;
  }
  return -1;
}
int main(void) {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the sorted element: ");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  time_t start,end;
  start=time(NULL);
  int ele,index;
  printf("Enter the element to search: ");
  scanf("%d",&ele);
  index=binarysearch(ele,n,arr);
  if(index==-1) printf("Element not found!!\n");
  else printf("Element occur at index %d\n",index);
  end=time(NULL);
  printf("Execution time for binary search is : %f seconds",difftime(end,start));
  return 0;
}

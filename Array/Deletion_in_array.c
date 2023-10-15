#include <stdio.h>
int main() {
  int n;
  printf("Enter size of array: ");
  scanf("%d",&n);
  int a[n],i,index=-1;
  printf("Enter the elements: ");
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  int item;
  printf("Enter item to be deleted: ");
  scanf("%d",&item);
  //Searching for index of item
  for(i=0;i<n;i++){
    if(a[i]==item) index=i;
  }
  if (index==-1) printf("Element not present in the array\n");
  else{
    n--;
    for(i=index;i<n;i++) a[i]=a[i+1];
  }
  printf("After deletion : ");
  for(i=0;i<n;i++) printf("%d\t",a[i]);
  return 0;
}

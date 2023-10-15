#include <stdio.h>
void merge(int arr[], int s, int mid, int e) {
  int n1 = mid - s + 1, n2 = e - mid;
  int L[n1], R[n2];
  for(int i = 0; i < n1; i++) L[i] = arr[s + i];
  for(int i = 0; i < n2; i++) R[i] = arr[mid + i + 1];
  int i = 0, j = 0, k = s;
  while(i < n1 && j < n2) {
    if(L[i] < R[j]) {
      arr[k] = L[i];
      i++;
    }
    else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while(i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while(j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
  return;
}
void mergesort(int arr[], int s, int e) {
  if (s >= e) return;
  else{
  int mid = s + (e - s) / 2;
  mergesort(arr, s, mid);
  mergesort(arr, mid + 1, e);
  merge(arr, s, mid, e);
  }
}
int main(void) {
  int size;
  printf("Enter the size: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements: ");
  for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
  mergesort(arr, 0, size - 1);
  printf("After sorting: ");
  for(int i = 0; i < size; i++) printf("%d\t", arr[i]);
return 0;
}

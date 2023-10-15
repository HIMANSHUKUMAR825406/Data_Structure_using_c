#include <stdio.h>
void swap(int *f,int*s){
    int temp=*f;
    *f=*s;
    *s=temp;
}
int partion(int arr[],int s,int e){
    int i=s,j=e;
    int pivot=s;
    while(i<j){
        while(arr[i]<=arr[pivot]&&i<e) i++;
        while(arr[j]>arr[pivot]&&j>s) j--;
        if(i<j) swap(&arr[i],&arr[j]);
    }
    swap(&arr[pivot],&arr[j]);
    return j;
}
void quicksort(int arr[],int s,int e){
    if(s<e){
        int p=partion(arr,s,e);
        quicksort(arr,s,p-1);
        quicksort(arr,p+1,e);
    }
}
int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements: ");
    for(int i=0;i<size;i++) scanf("%d",&arr[i]);
    quicksort(arr,0,size-1);
    printf("Elements after sorting: ");
    for(int i=0;i<size;i++) printf("%d\t",arr[i]);
    return 0;
}

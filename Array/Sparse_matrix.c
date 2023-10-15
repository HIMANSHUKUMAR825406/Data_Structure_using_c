#include <stdio.h>
int main(void) {
  int rows,columns,size=0;
  printf("Enter the no. of rows: ");
  scanf("%d",&rows);
  printf("Enter the no of columns: ");
  scanf("%d",&columns);
  printf("Enter the elements: \n");
  int sparsematrix[rows][columns];
  for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
      scanf("%d",&sparsematrix[i][j]);
      if(sparsematrix[i][j]!=0) size++;
    }
  }
  int compactmatrix[3][size],k=0;
  for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
      if(sparsematrix[i][j]!=0){
        compactmatrix[0][k]=i;
        compactmatrix[1][k]=j;
        compactmatrix[2][k]=sparsematrix[i][j];
        k++;
      }
    }
  }
  printf("Sparse matrix representation: \n");
  for(int i=0;i<3;i++){
    for(int j=0;j<size;j++){
      printf("%d\t",compactmatrix[i][j]); //Each columns represent row, column, and value
    }
    printf("\n");
  }
  return 0;
}

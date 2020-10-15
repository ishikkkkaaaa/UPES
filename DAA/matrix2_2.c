/* #include<stdio.h>
#define max 2

int main()
{
int a[max][max],c,d,k;
int first[10][10],second[10][10],multiply[10][10];
int sum=0;


printf("Enter the elements of the first matrix\n");
for(c=0;c<max;c++)
  for(d=0;d<max;d++)
  scanf("%d",&first[c][d]);

  printf("Enter the elements of the second matrix\n");
  for(c=0;c<max;c++)
    for(d=0;d<max;d++)
    scanf("%d",&second[c][d]);

    for (c = 0; c < 2; c++) {
          for (d = 0; d < 2; d++) {
            for (k = 0; k < 2; k++) {
              sum = sum + first[2][2]*second[2][2];
            }

            multiply[2][2] = sum;
            sum = 0;
          }
        }
        printf("Product of the matrices:\n");

            for (c = 0; c < 2; c++) {
              for (d = 0; d < 2; d++)
                printf("%d\t", multiply[2][2]);

              printf("\n");
            }


          return 0;
        }
*/

/*
#include<stdio.h>
int a[4][4],b[4][4],c[4][4];
int multi(int,int,int);
int main()
{
 int i,x;
 printf("\n enter the matrix A : \n");
 for(i=0;i<4;i++)
      scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
 printf("\n Enter the matrix B :\n");
 for(i=0;i<4;i++)
 {
      scanf("%d%d%d%d",&b[i][0],&b[i][1],&b[i][2],&b[i][3]);
      c[i][0]=0;
      c[i][1]=0;
      c[i][2]=0;
      c[i][3]=0;
 }
 x=multi(0,0,0);
 printf("\n The two matrices & there product is : ");
 for(i=0;i<4;i++)
 {
      printf("\n %d %d %d %d",a[i][0],a[i][1],a[i][2],a[i][3]);
      printf("\t %d %d %d %d",b[i][0],b[i][1],b[i][2],b[i][3]);
      printf("\t\t %d %d %d %d",c[i][0],c[i][1],c[i][2],c[i][3]);
 }
 getch();
}

int multi(int i,int j,int k)
{
 int x;
 if(k<4)
      if(i<4)
           if(j<4)
           {
                c[k][i]=c[k][i]+a[k][j]*b[j][i];
                x=multi(i,j+1,k);
                if(j==3||j!=0)
                     return 0;
                x=multi(i+1,j,k);
                if(i==3||i!=0)
                     return 0;
                multi(i,j,k+1);
           }
}
*/

#include<stdio.h>
#define MAX 10

int matrixMultiply(int[MAX][MAX], int[MAX][MAX]);
int row1, row2, col1, col2;
int res[MAX][MAX];

int main() {

   int mat1[MAX][MAX], mat2[MAX][MAX], i, j, k;

   printf("Enter the row and column of first matrix: ");
   scanf("%d%d", &row1, &col1);
   printf("Enter the row and column of second matrix: ");
   scanf("%d%d", &row2, &col2);

   if (col1 != row2) {
      printf("Matrix multiplication is not possible");
   } else {
      printf("Enter the First matrix: ");
      for (i = 0; i < row1; i++) {
         for (j = 0; j < col1; j++) {
            scanf("%d", &mat1[i][j]);
         }
      }

      printf("Enter the Second matrix: ");
      for (i = 0; i < row2; i++) {
         for (j = 0; j < col2; j++) {
            scanf("%d", &mat2[i][j]);
         }
      }

      matrixMultiply(mat1, mat2);
   }

   printf("\nThe multiplication of two matrixes is : \n");
   for (i = 0; i < row1; i++) {
      printf("\n");
      for (j = 0; j < col2; j++) {
         printf("%d ", res[i][j]);
      }
   }
   return 0;
}

int matrixMultiply(int a[MAX][MAX], int b[MAX][MAX]) {
   static int sum, i = 0, j = 0, k = 0;

   if (i < row1) {

      if (j < col2) {
         if (k < col1) {
            sum = sum + a[i][k] * b[k][j];
            k++;
            matrixMultiply(a, b);
         }
         res[i][j] = sum;
         sum = 0;
         k = 0;
         j++;
         matrixMultiply(a, b);
      }
      j = 0;
      i++;
      matrixMultiply(a, b);
   }
}

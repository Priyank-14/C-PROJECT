#include<stdio.h>
#define MAX 10

void readMatrix(int A[MAX][MAX],int r,int c);
void printMatrix(int A[MAX][MAX],int r,int c);
void addMatrix(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int r,int c);
void subMatrix(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int r,int c);
void mulMatrix(int A[MAX][MAX],int B[MAX][MAX], int C[MAX][MAX],int r1,int c1,int r2, int c2);
void Transpose(int A[MAX][MAX],int T[MAX][MAX],int r,int c);
void scalarMultiply(int A[MAX][MAX], int C[MAX][MAX], int r, int c, int k);
int traceMatrix(int A[MAX][MAX], int n);
int isSymmetric(int A[MAX][MAX], int n);
int isIdentity(int A[MAX][MAX], int n);
int determinant2x2(int A[MAX][MAX]);
int determinant3x3(int A[MAX][MAX]);


int main(){
    int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];
    int r1,c1,r2,c2,choice;
    int k, n, trace, det;

    while(1){
        printf("\n\t=== MATRIX CALCULATOR ===\n");
        printf("1. ADDITION\t\t\t2. SUBSTRACTION\n");
        printf("3. MULTIPLICATION\t\t4. TRANSPOSE\n");
        printf("5. SCALAR MULTIPLICATION\t6. TRACE OF MATRIX\n");
        printf("7. CHECK SYMMETRIC MATRIX\t8. CHECK IDENTITY MATRIX\n");
        printf("9. DETERMINANT (2x2 / 3x3)\t10. EXIT\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);

        if(choice==10){
            printf("EXITING...\n");
            break;
        }

        if(choice==1||choice==2){
            printf("enter rows and columns for matrix A and B:\n");
            scanf("%d%d",&r1,&c1);
            printf("Enter elements of Matrix A:\n");
            readMatrix(A,r1,c1);
            printf("Enter elements of Matrix B:\n");
            readMatrix(B,r1,c1);
            if(choice==1){
                addMatrix(A,B,C,r1,c1);
                printf("Result(A+B):\n");
                printMatrix(C,r1,c1);
            }
            else{
                subMatrix(A,B,C,r1,c1);
                printf("Result(A-B):\n");
                printMatrix(C,r1,c1);
            }
        }
        else if(choice==3){
            printf("Enter number of rows and columns of matrix A:\n");
            scanf("%d%d",&r1,&c1);
            printf("enter elements of A:\n");
            readMatrix(A,r1,c1);
            printf("Enter number of rows and columns of matrix B:\n");
            scanf("%d%d",&r2,&c2);
            if(c1!=r2){
                printf("Matrix multiplication is not possible!\n");
                continue;
            }
            printf("enter elements of B:\n");
            readMatrix(B,r2,c2);
            mulMatrix(A,B,C,r1,c1,r2,c2);
            printf("Result(A*B):\n");
            printMatrix(C,r1,c2);
        }
        else if(choice==4){
            printf("Enter row and column of Matrix A:\n");
            scanf("%d%d",&r1,&c1);
            printf("enter elements of matrix A:\n");
            readMatrix(A,r1,c1);
            Transpose(A,C,r1,c1);
            printf("Transpose of Matrix A:\n");
            printMatrix(C,c1,r1);
        }
        else if(choice==5){
            printf("Enter rows and columns for Matrix A:\n");
            scanf("%d%d",&r1,&c1);
            printf("Enter elements of Matrix A:\n");
            readMatrix(A,r1,c1);
            printf("Enter scalar value k:\n");
            scanf("%d",&k);
            scalarMultiply(A,C,r1,c1,k);
            printf("Result (k * A):\n");
            printMatrix(C,r1,c1);
        }
        else if(choice==6){
            printf("Enter order n of square Matrix A (n x n):\n");
            scanf("%d",&n);
            if(n>MAX){
                printf("Order exceeds MAX limit (%d)\n", MAX);
                continue;
            }
            printf("Enter elements of Matrix A (%d x %d):\n", n, n);
            readMatrix(A,n,n);
            trace = traceMatrix(A,n);
            printf("Trace of Matrix A: %d\n", trace);
        }
        else if(choice==7){
            printf("Enter order n of square Matrix A (n x n):\n");
            scanf("%d",&n);
            if(n>MAX){
                printf("Order exceeds MAX limit (%d)\n", MAX);
                continue;
            }
            printf("Enter elements of Matrix A (%d x %d):\n", n, n);
            readMatrix(A,n,n);
            if(isSymmetric(A,n)){
                printf("Matrix A is SYMMETRIC.\n");
            }
            else{
                printf("Matrix A is NOT symmetric.\n");
            }
        }
        else if(choice==8){
            printf("Enter order n of square Matrix A (n x n):\n");
            scanf("%d",&n);
            if(n>MAX){
                printf("Order exceeds MAX limit (%d)\n", MAX);
                continue;
            }
            printf("Enter elements of Matrix A (%d x %d):\n", n, n);
            readMatrix(A,n,n);
            if(isIdentity(A,n)){
                printf("Matrix A is an IDENTITY MATRIX.\n");
            }
            else{
                printf("Matrix A is NOT an identity matrix.\n");
            }
        }
        else if(choice==9){
            printf("Enter order of square Matrix A (2 or 3):\n");
            scanf("%d",&n);
            if(n!=2 && n!=3){
                printf("Invalid order! Only 2x2 or 3x3 supported.\n");
                continue;
            }
            printf("Enter elements of Matrix A (%d x %d):\n", n, n);
            readMatrix(A,n,n);
            if(n==2){
                det = determinant2x2(A);
            }
            else{
                det = determinant3x3(A);
            }
            printf("Determinant of Matrix A: %d\n", det);
        }
        else{
            printf("Invalid Choice! Enter between (1-10)\n");
        }
    }
    return 0;
}

void readMatrix(int A[MAX][MAX],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Element[%d][%d]:",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }
}

void printMatrix(int A[MAX][MAX],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

void subMatrix(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            C[i][j]=A[i][j]-B[i][j];
        }
    }
}

void mulMatrix(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int r1,int c1,int r2,int c2){
    int i,j,k;
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            C[i][j]=0;
        }
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            for(k=0;k<c1;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

void Transpose(int A[MAX][MAX],int T[MAX][MAX],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            T[j][i]=A[i][j];
        }
    }
}

void scalarMultiply(int A[MAX][MAX], int C[MAX][MAX], int r, int c, int k){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            C[i][j] = k * A[i][j];
        }
    }
}

int traceMatrix(int A[MAX][MAX], int n){
    int i, sum = 0;
    for(i=0;i<n;i++){
        sum += A[i][i];
    }
    return sum;
}

int isSymmetric(int A[MAX][MAX], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(A[i][j] != A[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

int isIdentity(int A[MAX][MAX], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                if(A[i][j] != 1){
                    return 0;
                }
            }
            else{
                if(A[i][j] != 0){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int determinant2x2(int A[MAX][MAX]){
    int det;
    det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    return det;
}

int determinant3x3(int A[MAX][MAX]){
    int det;
    det =  A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1])
         - A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0])
         + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);
    return det;
}

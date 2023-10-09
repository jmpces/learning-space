## Gemm types

  - sgemm - for single precision matrix (float)
  - dgemm - for double precision matrix (double)

## Blas GEMM parameters

MatrixA <- left hand side matrix

MatrixB <- right hand side matrix

MatrixC <- output matrix, dot product matrix

NOTE: cblas_?gemm() functions adds the dot product output into the MatrixC, which means ```MatrixC = MatrixC+(dot(MatrixA,MatrixB))```

**cblas_?gemm(MatrixOrder, TransposeMatrixA?, TransposeMatrixB?, M, N, K, alpha, MatrixA, lda, MatrixB, ldb, beta, MatrixC, ldc);**

  - MatrixOrder - this could either be row major or column major order of accessing elements in the memory
  - TransposeMatrixA? - specify if you want to transpose MatrixA before operation or not
  - TransposeMatrixB? - specify if you want to transpose MatrixB before operation or not
  - M - this is the number of rows of MatrixA
  - N - this is the number of columns of MatrixB
  - K - this is the number of columns of MatrixA, and the number of rows of MatrixB, (Matrix A's columns & Matrix B's row should have the same number/counts)
  - alpha - this scales the elements of the dot product of MatrixA and MatrixB => ```MatrixC = MatrixC+((MatrixA*MatrixB)*alpha)```
  - beta - this scales the initial default values of the MatrixC => ```MatrixC = MatrixC*beta```, you can think of beta being applied first before alpha
  - lda - if MatrixA is a **sub matrix** of a larger matrix the value of lda is the numbers of rows of that larger matrix, but if MatrixA is not not a **sub matrix** of another larger matrix, then the lda will be the same as **M** or the row the MatrixA
  - ldb - is the same as lda, but for MatrixB being a **sub matrix** or not
  - ldc - is the row of the output matrix

## Examples:

### Matrix dot product - Row Major Operation (the more intuitive way)
```c++
cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans,3,3,2,1,A,3,B,3,0,C,3);
```

### Matrix dot product - Column Major Operation
```c++
cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans,3,3,2,1,A,3,B,3,0,C,3);
```

note: in column major we use the parameters of row major to get the same results, though this might be counter intuitive because even though we did not transpose the MatrixA, we are still using ```3``` for our ```M```, and etc., all of this because we are using column order

### Matrix A
```
1	-3
2	 4
1	-1
```

### Matrix B
```
 1	2	 1
-3	4	-1
```

### Sample Program
```c++
#include <cblas.h>
#include <stdio.h>

int main()
{
    int i=0;

    double A[6] =
    {
         1.0, 2.0,  1.0,
        -3.0, 4.0, -1.0
    };

    double B[6] =
    {
         1.0, 2.0,  1.0,
        -3.0, 4.0, -1.0
    };

    double C[9] =
    {
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0
    };

    printf("Column Major Order\n");

    cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans,3,3,2,1,A,3,B,3,0,C,3);

    for(i=0; i<9; i++)
    {
            if(i%3==0) printf("\n");
            printf("%lf ", C[i]);
    }

    printf("\n\nRow Major Order\n");

    cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans,3,3,2,1,A,3,B,3,0,C,3);

    for(i=0; i<9; i++)
    {
            if(i%3==0) printf("\n");
            printf("%lf ", C[i]);
    }

    printf("\n");
}
```

output:
```shell
Column Major Order

10.000000 -10.000000 4.000000 
-10.000000 20.000000 -2.000000 
4.000000 -2.000000 2.000000 

Row Major Order

10.000000 -10.000000 4.000000 
-10.000000 20.000000 -2.000000 
4.000000 -2.000000 2.000000 
```

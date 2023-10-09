/*
    Single Precision Floating Point 4x4 Matrix Multiplication
*/

#include <iostream>
#include <immintrin.h>
#include <vector>
#include <cstring>
#include "minibench.hpp"

void print4x4(float *mat, std::string name="")
{
    std::cout << name;
    for(size_t i=0; i<4; ++i)
    {
        for(size_t j=0; j<4; ++j)
            std::cout << mat[i*4+j] << ' ';
        std::cout << "\n";
    }
    std::cout << "\n";
}

void kernel4x4_plain_transpose(float *&mat)
{
    float * trans = new float[4*4];
    size_t cnt = 0;
    for(size_t j=0; j<4; ++j)
    {
        for(size_t i=0; i<4; ++i)
        {
            trans[cnt++] = mat[i*4+j];
        }
    }
    delete [] mat;
    mat = trans;
}

void kernel4x4_simd_transpose(float *mat)
{
    __m128 row0 = _mm_loadu_ps(mat);
    __m128 row1 = _mm_loadu_ps(mat+4);
    __m128 row2 = _mm_loadu_ps(mat+8);
    __m128 row3 = _mm_loadu_ps(mat+12);

    _MM_TRANSPOSE4_PS(row0,row1,row2,row3);

    _mm_storeu_ps(mat,row0);
    _mm_storeu_ps(mat+4,row1);
    _mm_storeu_ps(mat+8,row2);
    _mm_storeu_ps(mat+12,row3);
}

void kernel4x4_simd_transpose(float *src, float *dest)
{
    __m128 row0 = _mm_loadu_ps(src);
    __m128 row1 = _mm_loadu_ps(src+4);
    __m128 row2 = _mm_loadu_ps(src+8);
    __m128 row3 = _mm_loadu_ps(src+12);

    _MM_TRANSPOSE4_PS(row0,row1,row2,row3);

    _mm_storeu_ps(dest,row0);
    _mm_storeu_ps(dest+4,row1);
    _mm_storeu_ps(dest+8,row2);
    _mm_storeu_ps(dest+12,row3);
}

#define ITERATIONS 10000001

int main()
{
    float *mat = new float[4*4];
    for(size_t i=0; i<4; ++i)
    {
        for(size_t j=0; j<4; ++j)
            mat[i*4+j] = 10+((i+j)*(i+1));
    }
    
    print4x4(mat,"original:\n");

    BENCHMARK_MICROSECONDS("plain trans",ITERATIONS,
        kernel4x4_plain_transpose(mat);
    );
    print4x4(mat,"plain transpose:\n");

    BENCHMARK_MICROSECONDS("simd  trans",ITERATIONS+1,
        kernel4x4_simd_transpose(mat);
    )
    print4x4(mat,"simd transpose:\n");

    delete [] mat;
    return 0;
}

/*
    Single Precision Floating Point 4x4 Matrix Multiplication
*/

#include <iostream>
#include <immintrin.h>
#include <vector>
#include <cstring>
#include "minibench.hpp"

void kernel4x4_simd(float *a, float *b, float *c)
{
    __m128 b_row0 = _mm_loadu_ps(b);
    __m128 b_row1 = _mm_loadu_ps(b+4);
    __m128 b_row2 = _mm_loadu_ps(b+8);
    __m128 b_row3 = _mm_loadu_ps(b+12);
    
    for(int i=0; i<4; i++)
    {
        __m128 a_rowcol0 = _mm_set1_ps(a[i*4+0]);
        __m128 a_rowcol1 = _mm_set1_ps(a[i*4+1]);
        __m128 a_rowcol2 = _mm_set1_ps(a[i*4+2]);
        __m128 a_rowcol3 = _mm_set1_ps(a[i*4+3]);

        __m128 ab_prod0 = _mm_mul_ps(b_row0, a_rowcol0);
        __m128 ab_prod1 = _mm_mul_ps(b_row1, a_rowcol1);
        __m128 ab_prod2 = _mm_mul_ps(b_row2, a_rowcol2);
        __m128 ab_prod3 = _mm_mul_ps(b_row3, a_rowcol3);

        __m128 ab01 = _mm_add_ps(ab_prod0,ab_prod1);
        __m128 ab23 = _mm_add_ps(ab_prod2,ab_prod3);

        __m128 cur_row_dotp = _mm_add_ps(ab01,ab23);

        _mm_store_ps(c+(4*i),cur_row_dotp);
    }
}

// faster than `kernel4x4_simd()` if the matricies by default is in column major order
void mmul_sse(float * a, float * b, float * r)
{
    // https://fhtr.blogspot.com/2010/02/4x4-float-matrix-multiplication-using.html
    /// originally column major order
    float tempA[16], tempB[16]; // added to support row major order
    
    kernel4x4_simd_transpose(a,tempA); // added to support row major order
    kernel4x4_simd_transpose(b,tempB); // added to support row major order
    
    __m128 a_line, b_line, r_line;
    for (int i=0; i<16; i+=4) {
        // unroll the first step of the loop to avoid having to initialize r_line to zero
        a_line = _mm_load_ps(tempA);         // a_line = vec4(column(a, 0))
        b_line = _mm_set1_ps(tempB[i]);      // b_line = vec4(b[i][0])
        r_line = _mm_mul_ps(a_line, b_line); // r_line = a_line * b_line
        
        for (int j=1; j<4; j++) {
            a_line = _mm_load_ps(&tempA[j*4]); // a_line = vec4(column(a, j))
            b_line = _mm_set1_ps(tempB[i+j]);  // b_line = vec4(b[i][j])
                                     // r_line += a_line * b_line
            r_line = _mm_add_ps(_mm_mul_ps(a_line, b_line), r_line);
        }
        _mm_store_ps(&r[i], r_line);     // r[i] = r_line
    }
    
    kernel4x4_simd_transpose(r,r); // added to support row major order
}

void kernel4x4_ijk_loop(float *a, float *b, float *dest)
{
    for(size_t i=0; i<4; ++i)
    {
        for(size_t j=0; j<4; ++j)
        {
            for(size_t k=0; k<4; ++k)
            {
                dest[i*4+j] += a[i*4+k]*b[k*4+j];
            }
        }
    }
}

void kernel4x4_ikj_loop(float *a, float *b, float *dest)
{
    for(size_t i=0; i<4; ++i)
    {
        for(size_t k=0; k<4; ++k)
        {
            for(size_t j=0; j<4; ++j)
            {
                dest[i*4+j] += a[i*4+k]*b[k*4+j];
            }
        }
    }
}

#define ITERATIONS 10000001

int main()
{
    float *product = new float[4*4];
    
    std::vector<float> a {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 0, 1, 2,
        3, 4, 5, 6
    }, 
    
    b {
        12,13,14,15,
        16,17,18,19,
        20,21,22,23,
        24,25,26,27
    };

    BENCHMARK_MICROSECONDS("ijk loop",ITERATIONS,
        memset(product,0,sizeof(float)*(4*4));
        kernel4x4_ijk_loop(a.data(),b.data(),product);
    );
    print4x4(product,"\nijk loop product :\n");

    BENCHMARK_MICROSECONDS("ikj loop",ITERATIONS,
        memset(product,0,sizeof(float)*(4*4));
        kernel4x4_ikj_loop(a.data(),b.data(),product);
    );
    print4x4(product,"\nikj loop product :\n");

    BENCHMARK_MICROSECONDS("simd loop",ITERATIONS,
        memset(product,0,sizeof(float)*(4*4));
        kernel4x4_simd(a.data(),b.data(),product);
    );
    print4x4(product,"\nsimd loop product :\n");

    delete [] product;
    return 0;
}

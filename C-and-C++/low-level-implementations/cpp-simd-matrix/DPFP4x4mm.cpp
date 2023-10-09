/*
    Double Precision Floating Point 4x4 Matrix Multiplication
*/

#include <iostream>
#include <immintrin.h>
#include <vector>
#include <cstring>
#include "minibench.hpp"

void kernel4x4_simd(double *a, double *b, double *c)
{
    __m128d b_row0a = _mm_loadu_pd(b);
    __m128d b_row0b = _mm_loadu_pd(b+2);

    __m128d b_row1a = _mm_loadu_pd(b+4);
    __m128d b_row1b = _mm_loadu_pd(b+6);

    __m128d b_row2a = _mm_loadu_pd(b+8);
    __m128d b_row2b = _mm_loadu_pd(b+10);

    __m128d b_row3a = _mm_loadu_pd(b+12);
    __m128d b_row3b = _mm_loadu_pd(b+14);
    
    for(int i=0; i<4; i++)
    {
        __m128d a_rowcol0a = _mm_set1_pd(a[i*4+0]);
        __m128d a_rowcol0b = _mm_set1_pd(a[i*4+0]);

        __m128d a_rowcol1a = _mm_set1_pd(a[i*4+1]);
        __m128d a_rowcol1b = _mm_set1_pd(a[i*4+1]);

        __m128d a_rowcol2a = _mm_set1_pd(a[i*4+2]);
        __m128d a_rowcol2b = _mm_set1_pd(a[i*4+2]);

        __m128d a_rowcol3a = _mm_set1_pd(a[i*4+3]);
        __m128d a_rowcol3b = _mm_set1_pd(a[i*4+3]);

        a_rowcol0a = _mm_mul_pd(b_row0a,a_rowcol0a);
        a_rowcol0b = _mm_mul_pd(b_row0b,a_rowcol0b);

        a_rowcol1a = _mm_mul_pd(b_row1a,a_rowcol1a);
        a_rowcol1b = _mm_mul_pd(b_row1b,a_rowcol1b);

        a_rowcol2a = _mm_mul_pd(b_row2a,a_rowcol2a);
        a_rowcol2b = _mm_mul_pd(b_row2b,a_rowcol2b);

        a_rowcol3a = _mm_mul_pd(b_row3a,a_rowcol3a);
        a_rowcol3b = _mm_mul_pd(b_row3b,a_rowcol3b);

        ///

        a_rowcol0a = _mm_add_pd(a_rowcol0a,a_rowcol1a);
        a_rowcol0b = _mm_add_pd(a_rowcol0b,a_rowcol1b);

        a_rowcol2a = _mm_add_pd(a_rowcol2a,a_rowcol3a);
        a_rowcol2b = _mm_add_pd(a_rowcol2b,a_rowcol3b);

        ///

        a_rowcol0a = _mm_add_pd(a_rowcol0a,a_rowcol2a);
        a_rowcol0b = _mm_add_pd(a_rowcol0b,a_rowcol2b);

        _mm_store_pd(c+(4*i),a_rowcol0a);
        _mm_store_pd(c+((4*i)+2),a_rowcol0b);
    }
}

void kernel4x4_ijk_loop(double *a, double *b, double *dest)
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

void kernel4x4_ikj_loop(double *a, double *b, double *dest)
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
    double *product = new double[4*4];
    
    std::vector<double>
    a {
        1.2, 2.3, 3.7, 4.8,
        5.8, 6.2, 7.5, 8.7,
        9.8, 0.5, 1.3, 2.1,
        3.1, 4.9, 5.4, 6.4
    },

    b {
        12.1, 13.2, 14.2, 15.8,
        16.3, 17.9, 18.3, 19.3, 
        20.2, 21.8, 22.4, 23.3, 
        24.5, 25.7, 26.5, 27.6
    };

    BENCHMARK_MICROSECONDS("ijk loop",ITERATIONS,
        memset(product,0,sizeof(double)*(4*4));
        kernel4x4_ijk_loop(a.data(),b.data(),product);
    );
    print4x4(product,"\nijk loop product :\n");

    BENCHMARK_MICROSECONDS("ikj loop",ITERATIONS,
        memset(product,0,sizeof(double)*(4*4));
        kernel4x4_ikj_loop(a.data(),b.data(),product);
    );
    print4x4(product,"\nikj loop product :\n");

    BENCHMARK_MICROSECONDS("simd loop",ITERATIONS,
        memset(product,0,sizeof(double)*(4*4));
        kernel4x4_simd(a.data(),b.data(),product);
    );
    print4x4(product,"\nsimd loop product :\n");

    delete [] product;
    return 0;
}

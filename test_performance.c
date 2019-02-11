#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "string_matching.h"

int main() {
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand(time(NULL));

    int tries = 1000;
    int M = 400;

    double total_naive;
    double total_kmp;

    for (int N = 10000; N < 1000001; N = N + 50000){
        for (int i = 0; i < tries; i = i + 1){
            char text[N];
            for (int j = 0; j < N; j = j + 1) {
                int pos = rand() % (int)(sizeof(charset) - 1);
                text[i] = charset[pos];
            }

            char pattern[M];
            for (int k = 0; k < M; k = k + 1) {
        	    int pos = rand() % (int)(sizeof(charset) - 1);
                pattern[i] = charset[pos];
            }


            clock_t t1 = clock();
            string_matching_naive(text, N, pattern, M);
            clock_t t2 = clock();
            total_naive = total_naive + (double)(t2 - t1) / CLOCKS_PER_SEC;

            clock_t t3 = clock();
            string_matching_kmp(text, N, pattern, M);
            clock_t t4 = clock();
            total_kmp = total_kmp + (double)(t4 - t3) / CLOCKS_PER_SEC;
        }

        printf("N=%d, avg naive: %f, avg kmp: %f\n", N, total_naive / tries, total_kmp / tries);
        total_naive = 0;
        total_kmp = 0;
    }

    return 0;
}

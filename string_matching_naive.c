#include "string_matching.h"

int string_matching_naive(char *text, int N, char* pattern, int M){
	int count = 0;
	int j;
	for (int i = 0; i < N; i = i + 1) {
		j = i;
		while (*(text + j) == *(pattern + j - i)) {
			j = j + 1;
			if (j == i + M) {
				count = count + 1;
			}
		}
	}

	return count;
}

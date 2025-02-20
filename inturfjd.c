#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define LENGTH 5
#define COUNT 120
#define MAX_CHAR_REPEAT 4

int array_isfull(int *arr, int value_max, int size) 
{
	for (int i = 0; i < size; i++) 
		if (arr[i] < value_max) {
		//	printf("\nfalse %d:%d\n", i, arr[i]);
			return 0;
		} 		
		//	printf("\ntrue\n");
			return 1;		
}

int array_sum(int *arr, int size) 
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum+=arr[i];
	return sum;

}

int main() {

	char char_array[] = "abcdefghijklmnopqrstuvwxyz";
	int char_count[27] = {0};
	int len = strlen(char_array), char_random, char_prev_random = 42;
	int count_len_chars = 0, count_len_words = 0;
	
	srand(time(NULL));

	while(1) {
		char_random = rand() % len;
		
		if (count_len_chars >= LENGTH) {
			count_len_chars = 0;
			count_len_words++;
			printf(" ");
		}

		if (count_len_words >= COUNT) break;

		if (array_isfull(char_count, MAX_CHAR_REPEAT, len)) {
			printf("\nfull/break1\n"); 
			break; 
		}

		while (char_random == char_prev_random || char_count[char_random] > MAX_CHAR_REPEAT) {
			if (array_isfull(char_count, MAX_CHAR_REPEAT, len)) {
				printf("full/break\n"); 
				break; 
			}
			char_random = rand() % len;
		//	printf("random char = %d\n", char_random);
		}

		//printf("random double? char = %d\n", char_random);

		putchar(char_array[char_random]);
		char_count[char_random]++;
		char_prev_random = char_random;
		count_len_chars++;

		//break;
	}
	
/* 	for (int i = 0; i < 0; i++) {
		if (array_isfull(char_count, 2, len)) break;
		for (int k = 0; k < LENGTH; k++) {
			if (array_isfull(char_count, 2, len)) break;
			char_random = rand() % len;

			while ((char_count[char_random] > COUNT - 1) || (char_random == char_prev_random))
			{
				if (array_sum(char_count, len) > LENGTH * COUNT)
					break;
				char_random = rand() % len;
				// printf("debug %d\n", array_sum(char_count, len));
			}

			while (char_random == char_prev_random) 
				char_random = rand() % len; 

			putchar(char_array[char_random]);
			char_count[char_random]++;
			char_prev_random = char_random;
			//printf("%d ", array_isfull(char_count, 1, len));
		}
		printf(" ");
	} */

	printf("\n\n--------\nchar(count): ");
	for (int i = 0; i < len; i++)        
			printf("%c(%d) ", char_array[i], char_count[i]);
	printf("\n\nused chars: %s (len: %d)\n", char_array, len);
	printf("%d \n", array_sum(char_count, len));
	return 0;
}
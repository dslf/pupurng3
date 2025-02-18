#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define LENGTH 5
#define COUNT 2000

int main() {

    char char_array[] = "abcdefghijklmnopqrstuvwxyz";
    int char_count[26] = {0};
    int len = strlen(char_array), char_random, char_prev_random = 42;
    
    srand(time(NULL));

    for (int i = 0; i < COUNT; i++) {
        for (int k = 0; k < LENGTH; k++) {
            char_random = rand() % len;
            while (char_random == char_prev_random) 
                char_random = rand() % len;
            putchar(char_array[char_random]);
            char_count[char_random]++;
            char_prev_random = char_random;
        }
        printf(" ");
    }

    printf("\n\n--------\nchar(count): ");
    for (int i = 0; i < len; i++)        
            printf("%c(%d) ", char_array[i], char_count[i]);
    printf("\n\nused chars: %s (len: %d)\n", char_array, len);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define LENGTH 5
#define COUNT 120

int main() {

    char j[] = "abcdefghijklmnopqrstuvwxyz";
    int count_chars[26] = {0};
    int len = strlen(j), random_char, prev_random_char = 42;
    
    
    srand(time(NULL));

    for (int i = 0; i < COUNT; i++) {
        for (int k = 0; k < LENGTH; k++) {
            random_char = rand() % len;
            while (random_char == prev_random_char) 
                random_char = rand() % len;
            putchar(j[random_char]);
            count_chars[random_char]++;
            prev_random_char = random_char;

        }
        printf(" ");
    }

    printf("\n\n--------\n\nchar(count): ");
    for (int i = 0; i < len; i++)
        //if (count_chars[i] != 0) 
            printf("%c(%d) ", j[i], count_chars[i]);
    printf("\n\nused chars: %s (len: %d)\n", j, len);


//    printf("Hello, World\n");
    return 0;
}
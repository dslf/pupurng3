#include <stdio.h>
#include <string.h>

int main() {

    char j[] = "adfjrfjdksfgmvmjsdkf3sdjfru";

    int len = strlen(j);
    
    for (int i = 0; i < len; i++)
        printf("%02d, %c\n", i, j[i]);
    printf("%s (len: %d)\n", j, len);


//    printf("Hello, World\n");
    return 0;
}
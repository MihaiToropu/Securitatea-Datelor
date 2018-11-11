#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define NR 100


int main() {
    int count[256] = {0};

    char plaintext[NR];

    printf("\nScrie ce vrei:");
    gets(plaintext);
    int max = 0;
    char ch;
    int plaintextLength = strlen(plaintext);

    for (int i = 0; i < plaintextLength; i++) {
        count[plaintext[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] > max) {
            max = count[i];
            ch = (char)i;
        }
    }

    printf("cel mai frecvent : %c", ch);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


#define NR 64

char VigenereEncrypt(char *alphabet, int *intKey, char text, int position)
{
    int encryptedText;

    for (int i = 0; i < 26; i++)
    {
        if (text == alphabet[i])
        {
            encryptedText = (i + intKey[position]) % 26;
            return alphabet[encryptedText];
        }
    }
}

char VigenereDecrypt(char *alphabet, int *intKey, char text, int position)
{
    int decryptedText;

    for (int i = 0; i < 26; i++)
    {
        if (text == alphabet[i])
        {
            decryptedText = (i - intKey[position]) % 26;
            return alphabet[decryptedText];
        }
    }
}

int main() {
    char plainText[NR], alphabet[27] = "abcdefghijklmnopqrstuvwxyz", key[NR], encryptedText[NR], decryptedText[NR];
    int intKey[NR], position = 0;
    printf("plaintext:\n");
    gets(plainText);
    printf("key\n");
    gets(key);

    int textLength = strlen(plainText);
    int keyLength = strlen(key);

    for (int i = 0; i < keyLength; i++) {
        for(int j = 0; j < 26; j++)
        {
            if (key[i] == alphabet[j])
            {
                intKey[i] = j;
            }
        }
    }

    int x = 1;
    printf("\nChoose:\n1.Encrypt text.\n2.Decrypt text.\n");
    scanf("%d", &x);

    switch (x)
    {
        case 1:
            for(int i = 0; i < textLength; i++)
            {
                encryptedText[i] = VigenereEncrypt(alphabet, intKey, plainText[i], position % keyLength);
                ++position;
            }
            encryptedText[textLength] = '\0';
            printf("\nEncrypted text: %s\n", encryptedText);
            break;

        case 2:
            for(int i = 0; i < textLength; i++)
            {
                decryptedText[i] = VigenereDecrypt(alphabet, intKey, plainText[i], position % keyLength);
                ++position;
            }
            decryptedText[textLength] = '\0';
            printf("\nDecrypted text: %s\n", decryptedText);
            break;

        default:
            printf("Exit");
    }

    return 0;
}

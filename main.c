#include<stdio.h>

void Decryption(char text[100], int key)
{
    char ch;

    for(int iter = 0; text[iter] != '\0'; ++iter){
        ch = text[iter];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            text[iter] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;

            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }

            text[iter] = ch;
        }
    }

    printf("Decryption %s", text);
}

void Encryption(char text[100], int key)
{
    char ch;
    for (int iter = 0; text[iter] != '\0'; ++iter)
    {
        ch = text[iter];
        if (ch >= 'a' && ch <= 'z')
        {
            ch += key;
            if (ch > 'z')
                ch = ch - 'z' + 'a' - 1;
            text[iter] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if (ch > 'Z')
                ch = ch - 'Z' + 'A' - 1;
            text[iter] = ch;
        }
    }

    printf("Encryption: %s", text);
}

int main()
{
    int key = 3;
    char text1[255] = "ana are mere";
    char text2[255] = "dqd duh phuh";
    Encryption(text1, key);
    printf("\n");
    Decryption(text2, key);

    return 0;
}
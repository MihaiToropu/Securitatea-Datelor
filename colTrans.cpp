#include<bits/stdc++.h>


using namespace std;


string decryptText(string encryptedText) {

    int column = key.length();

    int row = encryptedText.length() / column;
    char cipherMat[row][column];

    for (int j = 0, k = 0; j < column; j++)
        for (int i = 0; i < row; i++)
            cipherMat[i][j] = encryptedText[k++];

    int index = 0;
    for (map<int, int>::iterator ii = km.begin(); ii != km.end(); ++ii)
        ii->second = index++;

    char decCipher[row][column];
    map<int, int>::iterator ii = km.begin();
    int k = 0;
    for (int l = 0, j; key[l] != '\0'; k++) {
        j = km[key[l++]];
        for (int i = 0; i < row; i++) {
            decCipher[i][k] = cipherMat[i][j];
        }
    }

    string text = "";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (decCipher[i][j] != '_')
                text += decCipher[i][j];
        }
    }
    return text;
}

void OrderOfMap() {
    for (int iter = 0; iter < key.length(); ++iter)
        km[key[iter]] = iter;
}


string encryptText(string text) {
    int column;
    int row,
    string encryptedText = "";

    column = key.length();
    row = text.length() / column;

    if (text.length() % column)
        ++row;

    char matrix[row][column];

    for (int iter = 0, k = 0; iter < row; iter++) {
        for (int j = 0; j < column;) {
            if (text[k] == '\0') {
                matrix[iter][j] = '_';
                j++;
            }

            if (isalpha(text[k]) || text[k] == ' ') {
                matrix[iter][j] = text[k];
                j++;
            }
            k++;
        }
    }

    for (map<int, int>::iterator ii = km.begin(); ii != km.end(); ++ii) {
        j = ii->second;

        for (int iter = 0; iter < row; iter++) {
            if (isalpha(matrix[iter][j])
                || matrix[iter][j] == ' '
                || matrix[iter][j] == '_')
                encryptedText += matrix[iter][j];
        }
    }

    return encryptedText;
}



int main(void) {

    string const key = "CATALIN";
    map<int, int> km;
    int iter;
    string text = "CETIDORESCEUTIEDULCEROMANIE";
    string encryptedText, decrypt;

    OrderOfMap();
    encryptedText = encryptText(text);
    decryptedTex = decryptText(encryptedText);


    cout << "Encrypt " << encryptedText;
    cout << "Decrypt " <<  decrypt;

    return 0;
}

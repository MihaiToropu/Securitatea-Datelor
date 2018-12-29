#include<bits/stdc++.h>

using namespace std;

char gridMatrix[5][5];
char key[26];
char message[100];
int symbol[130], len, r, c;


void createGridMatrix();

void showGridMatrix();

void encipher();

void decipher();

void init();

void start() {
    system("CLS");
    int n;
    string op[] = {"1. Encipher", "2. Decipher", "3. Exit"};
    cout << op[0] << endl << op[1] << endl << op[2] << endl << "Enter choice: ";
    cin >> n;
    if (n == 1) encipher();
    else if (n == 2) decipher();
    else exit(1);
}

void init() {
    memset(symbol, 0, sizeof(symbol));
    system("CLS");
}

int main() {
    start();
    return 0;
}

void decipher() {
    init();
    createGridMatrix();
    cout << "Cypher text: ";
    char cypText[150];
    cin >> cypText;
    getchar();
    int l = strlen(cypText);


    cout << "Decipher text: ";

    int P, Q, S, f1, f2;
    char x, y;
    int R[l + l + 2], C[l + l + 2];
    P = 0;
    Q = 0;
    for (int i = 0; i < l / 2; i++) {
        for (int k = 0; k < 5; k++) {
            for (int m = 0; m < 5; m++) {
                if (cypText[i] == gridMatrix[k][m]) {
                    R[P] = k;
                    P++;
                    R[P] = m;
                    P++;
                    break;
                }
            }
        }
    }
    int index = 0;
    for (int i = l / 2; i < l; i++) {
        for (int k = 0; k < 5; k++) {
            for (int m = 0; m < 5; m++) {
                if (cypText[i] == gridMatrix[k][m]) {
                    C[index++] = k;
                    C[index++] = m;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < index; i++)
        cout << gridMatrix[R[i]][C[i]];
    cout << endl << endl;
    system("PAUSE");
    start();
}

void encipher() {
    init();
    createGridMatrix();
    cout << "Message to cypher: ";
    gets(message);
    int l = strlen(message);
    char reqText[150];
    int in = 0, j = 0;
    for (int i = 0; i < l; i++) {
        j = i + 1;
        if (message[i] == ' ') {
            i++;
            j++;
        }
        if (message[j] == ' ') j++;
        if (toupper(message[i]) == 'J') message[i] = 'i';
        if (toupper(message[i]) == toupper(message[j])) {
            reqText[in] = toupper(message[i]);
            reqText[in + 1] = 'X';
            in++;
        } else {
            reqText[in] = toupper(message[i]);
        }
        in++;
    }

    if (in % 2 != 0) {

        reqText[in++] = 'X';
    }

    cout << "Cypher text: ";

    int P, Q, R, S, f1, f2;
    char x, y;
    int mat[in + in + 2];
    P = 0;
    Q = in;
    for (int i = 0; i < in; i++) {
        for (int k = 0; k < 5; k++) {
            for (int m = 0; m < 5; m++) {
                if (reqText[i] == gridMatrix[k][m]) {
                    mat[P++] = k;
                    mat[Q++] = m;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < in + in; i += 2)
        cout << gridMatrix[mat[i]][mat[i + 1]];
    cout << endl << endl;
    system("PAUSE");
    start();
}

void createGridMatrix() {
    cout << "Keyword: ";
    cin >> key;
    getchar();
    len = strlen(key);
    symbol['J'] = 1;
    r = 0, c = 0;


    for (int i = 0; i < len; i++) {
        if (!symbol[toupper(key[i])]) {
            symbol[toupper(key[i])] = 1;
            gridMatrix[r][c++] = toupper(key[i]);
            if (c % 5 == 0) {
                c = 0;
                r++;
            }
        }
    }


    for (int i = 'A'; i <= 'Z'; i++) {
        if (symbol[i] == 0) {
            gridMatrix[r][c++] = i;
            symbol[i] = 1;
            if (c % 5 == 0) {
                if (r == 4 && c == 5) break;


                r++;
                c = 0;
            }
        }
    }
}

void showGridMatrix() {
    cout << "5x5 Matrix" << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << gridMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
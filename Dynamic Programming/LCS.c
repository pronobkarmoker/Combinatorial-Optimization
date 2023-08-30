#include <stdio.h>
#include <string.h>

int c[100][100];
char b[100][100];

void lcsLength(char X[], char Y[], int m, int n) {
    for (int i = 1; i <= m; i++) {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        c[0][j] = 0;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '|';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '-';
            }
        }
    }
}

void printLCS(char b[][100], char X[], int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == '\\') {
        printLCS(b, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    } else if (b[i][j] == '|') {
        printLCS(b, X, i - 1, j);
    } else {
        printLCS(b, X, i, j - 1);
    }
}

int main() {
    char X[] = "ABCBDA";
    char Y[] = "BDCABA";
    
    int m = strlen(X);
    int n = strlen(Y);
    
    lcsLength(X, Y, m, n);
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%c%d ", b[i][j], c[i][j]);
        }
        printf("\n");
    }
    
    printf("Longest Common Subsequence: ");
    printLCS(b, X, m, n);
    printf("\n");
    
    return 0;
}

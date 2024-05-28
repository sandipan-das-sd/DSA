#include<stdio.h>

int i,j,d,k;

void printoptimalSoln(int s[][5], int i, int j) {
    if(i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printoptimalSoln(s, i, s[i][j]);
        printoptimalSoln(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n = 5;
    int p[] = {5, 4, 3, 5, 7, 8};
    int m[5][5] = {0};
    int s[5][5] = {0};

    for(d = 1; d < n; d++) {
        for(i = 1; i < n - d; i++) {
            int j = i + d;
            int min = 2147483647;
            for(k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q < min) {
                    min = q;
                    s[i][j] = k;
                    m[i][j] = min;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
    printf("Optimal Parentheses: ");
    printoptimalSoln(s, 1, n - 1);
    printf("\n");

    return 0;
}

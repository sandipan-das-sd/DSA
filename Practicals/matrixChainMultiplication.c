#include<stdio.h>
#include<stdlib.h>
int d,i,j,l,k;
void printOptimalParenthesis(int s[][5], int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main()
{
    int n = 5; // Number of matrices is n-1
    int p[] = {5, 4, 6, 2, 7}; // Dimensions of the matrices
    int m[5][5] = {0}; // m[i][j] will hold the minimum number of multiplications needed to multiply matrices A_i...A_j
    int s[5][5] = {0}; // s[i][j] will hold the index of the matrix after which the optimal split is made

    for ( d = 1; d < n; d++)
    {
        for ( i = 1; i < n - d; i++)
        {
            int j = i + d;
            int min = 2147483647; // Using the maximum integer value instead of a magic number like 32767
            for ( k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                    m[i][j] = min;
                }
            }
        }
    }

    printf("Minimum number of multiplications is %d\n", m[1][n - 1]);
    printf("Optimal Parenthesis: ");
    printOptimalParenthesis(s, 1, n - 1);
    printf("\n");
    return 0;
}


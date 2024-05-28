//#include<stdio.h>
//#include<stdlib.h>
//int i,j,d,k;
//void printOptimalParenthesis(int s[][5], int i, int j)
//{
//    if (i == j)
//    {
//        printf("A%d", i);
//    }
//    else
//    {
//        printf("(");
//        printOptimalParenthesis(s, i, s[i][j]);
//        printOptimalParenthesis(s, s[i][j] + 1, j);
//        printf(")");
//    }
//}
//
//int main()
//{
//    int n = 5; // Number of matrices is n-1
//    int p[] = {5, 4, 6, 2, 7}; // Dimensions of the matrices
//    int m[5][5] = {0}; // m[i][j] will hold the minimum number of multiplications needed to multiply matrices A_i...A_j
//    int s[5][5] = {0}; // s[i][j] will hold the index of the matrix after which the optimal split is made
//
//    for ( d = 1; d < n; d++)
//    {
//        for ( i = 1; i < n - d; i++)
//        {
//            int j = i + d;
//            int min = 2147483647; // Using the maximum integer value instead of a magic number like 32767
//            for ( k = i; k < j; k++)
//            {
//                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
//                if (q < min)
//                {
//                    min = q;
//                    s[i][j] = k;
//                    m[i][j] = min;
//                }
//            }
//        }
//    }
//
//    printf("Minimum number of multiplications is %d\n", m[1][n - 1]);
//    printf("Optimal Parenthesis: ");
//    printOptimalParenthesis(s, 1, n - 1);
//    printf("\n");
//    return 0;
//}


#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int i,j;
// Function to store the optimal split points
int MatrixChainOrder(int p[], int n, int s[][n])
{
    int m[n][n];
    int i, j, k, L, q;

    // m[i][i] = 0 for all i
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    return m[1][n - 1];
}

// Function to print the optimal parenthesization
void printOptimalParenthesis(int s[][6], int i, int j)
{
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    
    // Array to store the optimal split points
    int s[N][N];
    for( i = 0; i < N; i++) {
        for( j = 0; j < N; j++) {
            s[i][j] = 0;
        }
    }

    // Function call to compute minimum multiplications
    int minMul = MatrixChainOrder(arr, N, s);

    printf("Minimum number of multiplications is %d\n", minMul);
    printf("Optimal Parenthesization is: ");
    printOptimalParenthesis(s, 1, N - 1);
    printf("\n");

    return 0;
}


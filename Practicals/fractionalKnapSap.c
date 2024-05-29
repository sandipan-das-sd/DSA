#include <stdio.h>

void fractionalKnapsack(int W[], int V[], int n, int M) {
    // Initialize an empty array SelectedItems
    int SelectedItems[n];
    int total = 0;
    
    // Calculate cost and sort in descending order
    float cost[n];
    for (int i = 0; i < n; i++) {
        cost[i] = (float)V[i] / W[i];
    }
    
    // Sort-Descending (cost)
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (cost[i] < cost[j]) {
                float temp = cost[i];
                cost[i] = cost[j];
                cost[j] = temp;
                
                int temp2 = W[i];
                W[i] = W[j];
                W[j] = temp2;
                
                temp2 = V[i];
                V[i] = V[j];
                V[j] = temp2;
            }
        }
    }
    
    // Initialize i
    int i = 0;
    
    // Loop
    while (i < n) {
        // If item can be fully added
        if (W[i] <= M) {
            SelectedItems[i] = W[i];
            M -= W[i];
            total += V[i];
        }
        // If item needs to be fractionally added
        else if (W[i] > M) {
            float fraction = (float)M / W[i];
            SelectedItems[i] = fraction * W[i];
            total += fraction * V[i];
            break; // Exit loop
        }
        i++;
    }
    
    // Print SelectedItems
    printf("Selected Items: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", SelectedItems[j]);
    }
    printf("\nTotal Value: %d\n", total);
}

int main() {
    int W[] = {10, 20, 30};
    int V[] = {60, 100, 120};
    int M = 50;
    int n = sizeof(W) / sizeof(W[0]);
    fractionalKnapsack(W, V, n, M);
    return 0;
}

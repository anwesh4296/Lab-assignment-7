#include <stdio.h>

typedef struct {
    int value;
    int original_index;
} ArrayElement;

void bubbleSort(ArrayElement arr[], int n, int swaps[]) {
    int i, j;
    ArrayElement temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].value > arr[j+1].value) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[arr[j].original_index]++;
                swaps[arr[j+1].original_index]++;
            }
        }
    }
}

int main() {
    ArrayElement arr[] = {{97, 0}, {16, 1}, {45, 2}, {63, 3}, {13, 4}, {22, 5}, {7, 6}, {58, 7}, {72, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int swaps[n];
    for(int i=0; i<n; i++)
        swaps[i] = 0;
    
    bubbleSort(arr, n, swaps);
    
    for(int i=0; i<n; i++)
        printf("Number of swaps needed for index %d: %d\n", i, swaps[i]);
    
    return 0;
}
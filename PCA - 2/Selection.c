#include<stdio.h>

void selectionSort(int arr[], int n) {
    int smallestIdx;
    for(int i = 0 ; i < n ; i++) {
        smallestIdx = i;
        for(int j = i + 1 ; j < n ; j++) {
            if(arr[j] < arr[smallestIdx]) {
                arr[smallestIdx] = arr[smallestIdx] ^ arr[j];
                arr[j] = arr[smallestIdx] ^ arr[j];
                arr[smallestIdx] = arr[smallestIdx] ^ arr[j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the no of terms:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements:\n");
    for(int i = 0 ; i < n ; i ++) {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("The array elements are: \n");
    for(int i = 0 ; i < n ; i++){
        printf("%d, ", arr[i]);
    }
}
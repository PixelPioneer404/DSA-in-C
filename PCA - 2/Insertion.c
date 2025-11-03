#include<stdio.h>

void insertionSort(int arr[], int n) {
    int curr, prev;
    for(int i = 1 ; i < n ; i++) {
        curr = arr[i];
        prev = i-1;
        while(prev >= 0 && arr[prev] > curr) {
            if(arr[prev] > curr) {
                arr[prev+1] = arr[prev];
                prev--; 
            }
        }
        arr[prev+1] = curr;
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
    insertionSort(arr, n);
    printf("The array elements are: \n");
    for(int i = 0 ; i < n ; i++){
        printf("%d, ", arr[i]);
    }
}
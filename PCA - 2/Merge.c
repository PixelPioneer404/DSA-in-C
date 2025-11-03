#include <stdio.h>

void merge(int arr[], int st, int mid, int end) {
    int i = st;
    int j = mid+1;
    int k = 0;
    int temp[end - st + 1];

    //comparision
    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        } else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    //leftovers
    while(i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= end) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    //adding to the main array
    for(int i = st, k = 0 ; i <= end ; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int st, int end) {
    if(st < end) {
        int mid = (st + end) / 2;
        mergeSort(arr, st, mid); //left
        mergeSort(arr, mid+1, end); //right
        merge(arr, st, mid, end);
    }
}

int main()
{
    int n;
    printf("Enter the no of terms:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("The array elements are: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
}
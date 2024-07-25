#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void copy_array(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int n = 1000;
    int arr[n];
    int arr_copy[n];
    srand(time(0));

    // Preenchendo o array com valores aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    // Medindo o tempo do Selection Sort
    copy_array(arr, arr_copy, n);
    clock_t start = clock();
    selection_sort(arr_copy, n);
    clock_t end = clock();
    double selection_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Selection Sort: %.6f segundos\n", selection_sort_time);

    // Medindo o tempo do Insertion Sort
    copy_array(arr, arr_copy, n);
    start = clock();
    insertion_sort(arr_copy, n);
    end = clock();
    double insertion_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Insertion Sort: %.6f segundos\n", insertion_sort_time);

    return 0;
}

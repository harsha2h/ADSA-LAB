#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_VAL 100

// 1. INSERTION SORT
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// 2. BUBBLE SORT
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 3. SELECTION SORT
void selectionSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// 4. SHELL SORT
void shellSort(int arr[], int n) {

    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; i++) {

            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

// 5. QUICK SORT
int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] <= pivot) {

            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {

    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 6. MERGE SORT
void merge(int arr[], int l, int m, int r) {

    int L[MAX_SIZE];
    int R[MAX_SIZE];

    int n1 = m - l + 1;
    int n2 = r - m;

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {

    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// 7. HEAP SORT
void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {

        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

// 8. RADIX SORT
int getMax(int arr[], int n) {

    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

void countingByDigit(int arr[], int n, int exp) {

    int output[MAX_SIZE];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {

        int digit = (arr[i] / exp) % 10;

        output[count[digit] - 1] = arr[i];

        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {

    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingByDigit(arr, n, exp);
}

// 9. COUNTING SORT
void countingSort(int arr[], int n) {

    int count[MAX_VAL + 1] = {0};
    int output[MAX_SIZE];

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= MAX_VAL; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {

        output[count[arr[i]] - 1] = arr[i];

        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// 10. BUCKET SORT
void bucketSort(int arr[], int n) {

    int buckets[10][MAX_SIZE];
    int bucketCount[10] = {0};

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    for (int i = 0; i < n; i++) {

        int index;

        if (max == min)
            index = 0;
        else
            index = (arr[i] - min) * 9 / (max - min);

        buckets[index][bucketCount[index]++] = arr[i];
    }

    int k = 0;

    for (int i = 0; i < 10; i++) {

        insertionSort(buckets[i], bucketCount[i]);

        for (int j = 0; j < bucketCount[i]; j++)
            arr[k++] = buckets[i][j];
    }
}

// 11. RADIX EXCHANGE SORT
void radixExchangeSort(int arr[], int left, int right, int bit) {

    if (left >= right || bit < 0)
        return;

    int i = left;
    int j = right;

    while (i <= j) {

        while (i <= right && ((arr[i] >> bit) & 1) == 0)
            i++;

        while (j >= left && ((arr[j] >> bit) & 1) == 1)
            j--;

        if (i < j) {

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    radixExchangeSort(arr, left, j, bit - 1);
    radixExchangeSort(arr, i, right, bit - 1);
}

// 12. ADDRESS CALCULATION SORT
void addressCalculationSort(int arr[], int n) {

    int output[MAX_VAL + 1] = {0};

    for (int i = 0; i < n; i++)
        output[arr[i]]++;

    int k = 0;

    for (int i = 0; i <= MAX_VAL; i++) {

        while (output[i] > 0) {

            arr[k++] = i;
            output[i]--;
        }
    }
}

// Print array
void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

// Main
int main() {

    int n;
    int arr[MAX_SIZE];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal array:\n");
    printArray(arr, n);

    int temp[MAX_SIZE];

    // 1. Insertion
    memcpy(temp, arr, sizeof(int) * n);
    insertionSort(temp, n);
    printf("Insertion Sort: ");
    printArray(temp, n);

    // 2. Bubble
    memcpy(temp, arr, sizeof(int) * n);
    bubbleSort(temp, n);
    printf("Bubble Sort: ");
    printArray(temp, n);

    // 3. Selection
    memcpy(temp, arr, sizeof(int) * n);
    selectionSort(temp, n);
    printf("Selection Sort: ");
    printArray(temp, n);

    // 4. Shell
    memcpy(temp, arr, sizeof(int) * n);
    shellSort(temp, n);
    printf("Shell Sort: ");
    printArray(temp, n);

    // 5. Quick
    memcpy(temp, arr, sizeof(int) * n);
    quickSort(temp, 0, n - 1);
    printf("Quick Sort: ");
    printArray(temp, n);

    // 6. Merge
    memcpy(temp, arr, sizeof(int) * n);
    mergeSort(temp, 0, n - 1);
    printf("Merge Sort: ");
    printArray(temp, n);

    // 7. Heap
    memcpy(temp, arr, sizeof(int) * n);
    heapSort(temp, n);
    printf("Heap Sort: ");
    printArray(temp, n);

    // 8. Radix
    memcpy(temp, arr, sizeof(int) * n);
    radixSort(temp, n);
    printf("Radix Sort: ");
    printArray(temp, n);

    // 9. Counting
    memcpy(temp, arr, sizeof(int) * n);
    countingSort(temp, n);
    printf("Counting Sort: ");
    printArray(temp, n);

    // 10. Bucket
    memcpy(temp, arr, sizeof(int) * n);
    bucketSort(temp, n);
    printf("Bucket Sort: ");
    printArray(temp, n);

    // 11. Radix Exchange
    memcpy(temp, arr, sizeof(int) * n);
    radixExchangeSort(temp, 0, n - 1, 30);
    printf("Radix Exchange Sort: ");
    printArray(temp, n);

    // 12. Address Calculation
    memcpy(temp, arr, sizeof(int) * n);
    addressCalculationSort(temp, n);
    printf("Address Calculation Sort: ");
    printArray(temp, n);

    return 0;
}
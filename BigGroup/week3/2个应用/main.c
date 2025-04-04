#include <stdio.h>

void func1(int arr[], int n);
void func2(int arr[], int n, int k);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void printArray(int arr[], int n);
void quickSort(int arr[], int low, int high);

void func1(int arr[], int n) {
    int p0 = 0, p1 = 0, p2 = n - 1;
    while (p1 <= p2) {
        if (arr[p1] == 0) {
            swap(&arr[p1], &arr[p0]);
            p0++;
            p1++;
        } else if (arr[p1] == 2) {
            swap(&arr[p1], &arr[p2]);
            p2--;
        } else {
            p1++;
        }
    }
}

void func2(int arr[], int n, int k) {
    int low = 0, high = n - 1;
    int pivotIndex;
    while (low <= high) {
        pivotIndex = partition(arr, low, high);
        if (pivotIndex == k - 1) {
            printf("�����е�%d���������::%d\n", k, arr[pivotIndex]);
            return;
        } else if (pivotIndex > k - 1) {
            high = pivotIndex - 1;
        } else {
            low = pivotIndex + 1;
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;
    for (j = low; j < high; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {2, 1, 0, 2, 1, 1, 0, 0, 2, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {3, 2, 1, 5, 6, 4, 14, 7, 9, 11, 7, 12, 13, 8, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k;

    printf("func1��ԭʼ����: ");
    printArray(arr1, n1);
    func1(arr1, n1);
    printf("func1����������: ");
    printArray(arr1, n1);
	
	printf("func2��ԭʼ����: ");
    printArray(arr2, n2);
	quickSort(arr2, 0, n2 - 1);
    printf("func2��ԭʼ���������: ");
    printArray(arr2, n2);
    printf("������k��ֵ: ");
    scanf("%d", &k);
    if (k < 1 || k > n2) {
        printf("����:k��ֵ������Χ��������һ������1��%d֮���ֵ��\n", n2);
        return 1;
    }
    func2(arr2, n2, k);

    return 0;
}

#include "header.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertSort(int arr[], int n) {
	int i;
    for (i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;  
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l;  
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void countSort(int arr[], int n) {
    int i, max, min, range;
    int *output, *count;
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    range = max - min + 1;
    output = (int *)malloc(n * sizeof(int));
    count = (int *)calloc(range, sizeof(int));
    for (i = 0; i < n; i++)
        count[arr[i] - min]++;
    for (i = 1; i < range; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
    free(output);
    free(count);
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int exp;
    int *output = (int *)malloc(n * sizeof(int));
    for (exp = 1; max / exp > 0; exp *= 10) {
        int count[10] = {0}; 
        int i;
        for (i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        for (i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    free(output);
}

void generateData(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

void saveToFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    int i;
    for (i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
    printf("数据已保存在data.txt\n");
}

void readFromFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "r");
    int i;
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double measureBigDataTime(void (*sortFunction)(int[], int), int arr[], int n) {
    clock_t start = clock();
    sortFunction(arr, n);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    return time_spent;
}

double measureBigDataTimeWithIndices(void (*sortFunction)(int[], int, int), int arr[], int n, int low, int high) {
    int *temp = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    clock_t start = clock();
    sortFunction(temp, low, high);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    free(temp);
    return time_spent;
}

double measureSmallDataTime(void (*sortFunction)(int[], int), int n) {
    int arr[100];
    double totalTime = 0;
    int i;
    for (i = 0; i < 100000; i++) {
        generateData(arr, n);
        clock_t start = clock();
        sortFunction(arr, n);
        clock_t end = clock();
        totalTime += (double)(end - start) / CLOCKS_PER_SEC;
    }
    return totalTime;
}

double measureSmallDataTimeWithIndices(void (*sortFunction)(int[], int, int), int n) {
    int arr[100];
    double totalTime = 0;
    int i;
    for (i = 0; i < 100000; i++) {
        generateData(arr, n);
        clock_t start = clock();
        sortFunction(arr, 0, n - 1);
        clock_t end = clock();
        totalTime += (long double)(end - start) / CLOCKS_PER_SEC;
    }
    return totalTime;
}

int main() {
    int sizes[] = {10000, 50000, 200000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int arr[MAX_SIZE];
    int i, n;
    int *tempArr;

    //测试大数据 
    for (i = 0; i < num_sizes; i++) {
        n = sizes[i];
        generateData(arr, n);
        int *tempArr = (int *)malloc(n * sizeof(int));
		memcpy(tempArr, arr, n * sizeof(int));  
        printf("数据大小: %d\n", n);
        printf("插入排序: %.4Lfs\n", measureBigDataTime(insertSort, tempArr, n));
        memcpy(tempArr, arr, n * sizeof(int)); 
        printf("归并排序: %.4Lfs\n", measureBigDataTimeWithIndices(mergeSort, tempArr, n, 0, n-1));
        memcpy(tempArr, arr, n * sizeof(int)); 
        printf("快速排序: %.4Lfs\n", measureBigDataTimeWithIndices(quickSort, tempArr, n, 0, n-1));
        memcpy(tempArr, arr, n * sizeof(int)); 
        printf("计数排序: %.4Lfs\n", measureBigDataTime(countSort, tempArr, n));
        memcpy(tempArr, arr, n * sizeof(int)); 
        printf("基数计数排序: %.4Lfs\n", measureBigDataTime(radixSort, tempArr, n));
        memcpy(tempArr, arr, n * sizeof(int)); 
        printf("\n");
        free(tempArr);
    }

    //测试多组小数据 
    printf("小数据测试(100个数据*100k次排序):\n");
    printf("插入排序: %.4Lfs\n", measureSmallDataTime(insertSort, 100));
    printf("归并排序: %.4Lfs\n", measureSmallDataTimeWithIndices(mergeSort, 100));
    printf("快速排序: %.4Lfs\n", measureSmallDataTimeWithIndices(quickSort, 100));
    printf("计数排序: %.4Lfs\n", measureSmallDataTime(countSort, 100));
    printf("基数计数排序: %.4Lfs\n", measureSmallDataTime(radixSort, 100));
    printf("\n");
	
	system("pause");
	system("cls");
	int t = 0;
	printf("请输入您要生成的数据的数据量: ");
	scanf("%d",&t);
	generateData(arr,t);
	int choice = 0;
	printf("请选择排序算法: \n1. 插入排序\n2. 归并排序\n3. 快速排序\n4. 计数排序\n5. 基数排序\n");
	printf("请输入你的选择:");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			insertSort(arr,t);
			saveToFile(arr, t, "data.txt");
			break;
		case 2:
			mergeSort(arr, 0, t-1);
			saveToFile(arr, t, "data.txt");
			break;
		case 3:
			quickSort(arr, 0, t-1);
			saveToFile(arr, t, "data.txt");
			break;
		case 4:
			countSort(arr,t);
			saveToFile(arr, t, "data.txt");
			break;
		case 5:
			radixSort(arr,t);
			saveToFile(arr, t, "data.txt");
			break;
		default:
			printf("选择错误");	
	}
		
    return 0;
}

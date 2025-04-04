#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 200000

void swap(int *a, int *b);
void insertSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void countSortForRadix(int arr[], int n);
void radixSort(int arr[], int n);
void generateData(int arr[], int n);
void saveToFile(int arr[], int n, const char *filename);
void readFromFile(int arr[], int n, const char *filename);
void printArray(int arr[], int n);
double measureBigDataTime(void (*sortFunction)(int[], int), int arr[], int n);
double measureBigDataTimeWithIndices(void (*sortFunction)(int[], int, int), int arr[], int n, int low, int high);
double measureSmallDataTime(void (*sortFunction)(int[], int), int n);
double measureSmallDataTimeWithIndices(void (*sortFunction)(int[], int, int), int n);

#endif 

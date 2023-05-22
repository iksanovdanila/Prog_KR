#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void insertion_sort(int *array, int size)
{
	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++) {
			if (array[i] > array[j])
				swap(&array[i], &array[j]);
		}
	}
}

void heapify(int *arr, int size, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, size, largest);
	}
}

void Heap_sort(int *array, int size)
{
	for (int i = size/2-1; i >= 0; i--)
		heapify(array, size, i);
	for (int i = size - 1; i >= 0; i--) {
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
	}
}

int main()
{
	int size = 100;
	int array1[size];
	int array2[size];

	for (int i = 0; i < size; i++) {
		array1[i] = getrand(0, 1000);
		array2[i] = array1[i];
	}

	insertion_sort(array1, size);
	Heap_sort(array2, size);

	for (int i = 0; i < size; i++)
		printf("%d ", array1[i]);
	printf("\n");
	for (int i = 0; i < size; i++)
                printf("%d ", array2[i]);
        printf("\n");

	return 0;
}

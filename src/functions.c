#include "functions.h"

//Bubble Sort
void bubble_sort(int a[], int num) {
	int i, j, temp;

	for(i = 0 ; i < num ; i++) {
		for(j = num-1 ; j >= i + 1 ; j--) {
			if(a[j] < a[j-1]) {
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}

	return;
}

//Recursive Bubble Sort
void bubble_sort_recursive(int a[], int num) {
	int i ,temp;

	if (num == 1)
		return;

	for(i =  0 ; i < num - 1 ; i++) {
		if(a[i] > a[i+1]) {
			temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
		}
	}

	bubble_sort_recursive(a, num-1);

	return;
}

//Insertion Sort
void insertion_sort(int a[], int num) {
	int i, j, temp, key;

	for (j = 1 ; j < num ; j++) {
		key = a[j];
		i = j - 1;

		while ((i >= 0) && ( a[i] > key)) {
			a[i+1] = a[i];
			i--;
		}

		a[i+1] = key ;
	}

	return;
}

//Recursive Insertion Sort
void insertion_sort_recursive(int a[], int num) {
	int i, temp, key;

	if (num <= 1)
		return;

	insertion_sort_recursive(a, num-1);

	key = a[num-1];
	i = num - 2;

	while (i >= 0 && a[i] > key) {
		a[i+1] = a[i];
		i--;
	}

	a[i+1] = key;

	return;
}

//Binary Insertion Sort
void binary_insertion_sort(int a[], int num) {
	int i, j, left, right, center, key;

	for ( i = 1 ; i < num ; i++) {
		key = a[i];
		left = 0;
		right = i;

		while ( left < right) {
			center = left +  (right-left)/2;
			if ( a[center] > key)
				right = center;
			else
				left = center + 1;
		}

		for (j = i ; j > left ; j--)
			a[j] = a[j-1];

		a[j] = key;
	}

	return;
}

//Merge Sort
void merge_sort(int a[], int low, int high, int num) {
	int mid, i;

	if ((high - low) < 2)
		return;

	mid = low + (high-low)/2;
	merge_sort(a, low, mid, num);

	merge_sort(a, mid , high, num);

	merge(a, low, mid, high, num);

	return;
}

void merge(int a[], int low, int mid, int high, int num) {
	int i = low, j = mid, k = 0;
	int temp[num];

	while ((i < mid) && (j <= high)) {
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while ( i < mid )
		temp[k++] = a[i++];

	while (j <= high)
		temp[k++] = a[j++];

	for (i = 0 ; i < k ; ++i)
		a[low+i] = temp[i];

	return;
}

//Selection Sort
void selection_sort(int a[], int num) {
	int i, min = 0, temp;

	for(i = 1 ; i <= num-1 ; i++) {
		min = i - 1;

		temp = a[i-1];
		a[i-1] = a[min];
		a[min] = temp;
	}

	return;
}

//Quick_Sort
void quicksort (int a[], int p, int r) {
	int q;

	if ( p < r ) {
		q = partition(a,p,r);

		quicksort(a,p,q-1);

		quicksort(a,q+1,r);
	}

	return;
}

int partition(int a[], int p, int r) {
	int x, i, j, temp;

	x = a[r];
	i = p-1;

	for(j = p ; j < r ; j++) {
		if(a[j] <= x) {
			i++;

			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	a[r] = a[i+1];
	a[i+1] = temp;

	return (i+1);
}

//Heap_Sort
void heap_sort(int a[], int num, int *h) {
	build_max_heap(a,num,h);
	int i, aux;

	for(i = num - 1 ; i > 0 ; i--) {
		aux = a[0];
		a[0] = a[i];
		a[i] = aux;
		*h = *h  - 1;

		max_heapify(a,0,h);
	}

	return;
}

void build_max_heap(int a[], int num, int *h) {
	int i;
	*h = num - 1;

	for (i = num/2 ; i >= 0 ; i--)
		max_heapify(a,i,h);

	return;
}

void max_heapify(int a[], int i, int *h) {
	int largest, left, right, aux;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if(left <= *h && a[left] > a[i])
		largest =  left;
	else
		largest = i;

	if (right <= *h && a[right] > a[largest])
		largest = right;

	if(largest != i) {
		aux = a[i];
		a[i] = a[largest];
		a[largest] = aux;

		max_heapify(a, largest, h);
	}

	return;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "functions.h"

int main(int argc, char* argv[])
	{
	int i, heap_size = 0, size;
	int *array;	
	double sttime, endtime;
		
	if (argc != 3)
		{
		printf("Error in input arguments\n");
		return -1;
		}	
				
	if ((array = malloc(size * sizeof(int))) == NULL) 
		{
  		printf("malloc failed\n");
  		return -1;
		}
	
	size = atoi(argv[2]);
	
	//Initialize array		
	srand(time(NULL));
	for (i = 0 ; i < size ; i++)	
		array[i] = rand() % 10000 + 1;

	if (!strcmp(argv[1], "-bubble"))
		{
		printf("----------Recursive Bubble Sort----------\n");
		printf("\nUnsorted array is:\n");
		for(i = 0 ; i < size ; i++) 
			printf("%d ", array[i]);
		
		sttime = ((double) clock())/CLOCKS_PER_SEC;
		bubble_sort(array, size);
		endtime = ((double) clock())/CLOCKS_PER_SEC;
		
		printf("\n\nSorted array is:\n");
		for (i = 0 ; i < size ; i++)	
			printf("%d ", array[i]);
		
		printf("\n");	
		}
	else if (!strcmp(argv[1], "-bubblerec"))
		{
		printf("----------Recursive Bubble Sort----------\n");
		printf("\nUnsorted array is:\n");
		for(i = 0 ; i < size ; i++) 
			printf("%d ", array[i]);
		
		sttime = ((double) clock())/CLOCKS_PER_SEC;
		bubble_sort_recursive(array, size);
		endtime = ((double) clock())/CLOCKS_PER_SEC;
		
		printf("\n\nSorted array is:\n");
		for (i = 0 ; i < size ; i++)	
			printf("%d ", array[i]);
		
		printf("\n");	
		}	
	else if (!strcmp(argv[1], "-insertion"))
		{
		printf("----------Recursive Insertion Sort----------\n");
		printf("\nUnsorted array is:\n");
		
		for(i = 0 ; i < size ; i++) 
			printf("%d ", array[i]);
		
		sttime = ((double) clock())/CLOCKS_PER_SEC;
		insertion_sort(array, size);
		endtime = ((double) clock())/CLOCKS_PER_SEC;
		
		printf("\n\nSorted array is:\n");
		for (i = 0 ; i < size ; i++)	
			printf("%d ", array[i]);
		
		printf("\n");	
		}
	else if (!strcmp(argv[1], "-insertionrec"))
		{
		printf("----------Recursive Insertion Sort----------\n");
		printf("\nUnsorted array is:\n");
		
		for(i = 0 ; i < size ; i++) 
			printf("%d ", array[i]);
		
		sttime = ((double) clock())/CLOCKS_PER_SEC;
		insertion_sort_recursive(array, size);
		endtime = ((double) clock())/CLOCKS_PER_SEC;
		
		printf("\n\nSorted array is:\n");
		for (i = 0 ; i < size ; i++)	
			printf("%d ", array[i]);
		
		printf("\n");	
		}	
	else if (!strcmp(argv[1], "-binary"))
		{
		printf("----------Binary Insertion Sort----------\n");
		printf("\nUnsorted array is:\n");

		for(i = 0 ; i < size ; i++) 
			printf("%d ", array[i]);
		
		sttime = ((double) clock())/CLOCKS_PER_SEC;
		binary_insertion_sort(array, size);
		endtime = ((double) clock())/CLOCKS_PER_SEC;
		
		printf("\n\nSorted array is:\n");
		for (i = 0 ; i < size ; i++)	
			printf("%d ", array[i]);
		
		printf("\n");	
		}
	else if (!strcmp(argv[1], "-selection"))
		{
		printf("----------Selection Sort----------\n");
		printf("\nUnsorted array is:\n");

		for(i = 0 ; i < size ; i++) 
			printf("%d ", array[i]);
		
		sttime = ((double) clock())/CLOCKS_PER_SEC;
		selection_sort(array, size);
		endtime = ((double) clock())/CLOCKS_PER_SEC;
		
		printf("\n\nSorted array is:\n");
		for (i = 0 ; i < size ; i++)	
			printf("%d ", array[i]);
		
		printf("\n");	
		}
	else if (!strcmp(argv[1], "-merge"))
		{
		printf("----------Merge Sort----------\n");
		printf("\nUnsorted array is:\n");

		for(i = 0 ; i < size ; i++) 
			printf("%d ", array[i]);
		
		sttime = ((double) clock())/CLOCKS_PER_SEC;
		merge_sort(array,0, size-1, size);
		endtime = ((double) clock())/CLOCKS_PER_SEC;
		
		printf("\n\nSorted array is:\n");
		for (i = 0 ; i < size ; i++)	
			printf("%d ", array[i]);
		
		printf("\n");	
		}
	else if (!strcmp(argv[1], "-quick"))
		{
		printf("----------Quick Sort----------\n");
		printf("\nUnsorted array is:\n");

		for(i = 0 ; i < size ; i++) 
			printf("%d ", array[i]);
		
		sttime = ((double) clock())/CLOCKS_PER_SEC;
		quicksort(array, 0, size-2);
		endtime = ((double) clock())/CLOCKS_PER_SEC;
		
		printf("\n\nSorted array is:\n");
		for (i = 0 ; i < size ; i++)	
			printf("%d ", array[i]);
		
		printf("\n");	
		}
	else if (!strcmp(argv[1], "-heap"))
		{
		printf("----------Heap Sort----------\n");
		printf("\nUnsorted array is:\n");	

		for(i = 0 ; i < size ; i++) 
			printf("%d ", array[i]);
		
		sttime = ((double) clock())/CLOCKS_PER_SEC;
		heap_sort(array, size, &heap_size);
		endtime = ((double) clock())/CLOCKS_PER_SEC;
		
		printf("\n\nSorted array is:\n");
		for (i = 0 ; i < size ; i++)	
			printf("%d ", array[i]);
		
		printf("\n");	
		}			
	else
		{
		printf("Error in input arguments\n");
		return -1;		
		}		
		
	printf("\nRunning time is:  %.2f secs\n", endtime - sttime);
	free(array);	
	return 0;		
	}	
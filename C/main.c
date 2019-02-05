#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/* C implementation QuickSort */

/* A utility function to swap two elements */
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
	array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; /*pivot */
	int i = (low - 1); /*Index of smaller element */
    int j;
	for (j = low; j <= high- 1; j++) 
	{ 
		/*If current element is smaller than or 
		 equal to pivot */
		if (arr[j] <= pivot) 
		{ 
			i++; /* increment index of smaller element */
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high); 

		/*Separately sort elements before 
		partition and after partition */
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d\n", arr[i]); 
	 
} 



void iceBreaker(int *ptr,int size){
    int i=0,j,k;
    int sum=0;
    for(i=0;i<size-2 && ptr[i] < 0;i++){
        j = i+1;
        k = size-1;
        while(j!=k){
            sum = ptr[i]+ptr[j]+ptr[k];
            if(sum==0){
                printf("Fair\n");
                return;
            }
            else if(sum>0){
                k--;
            }
            else{
                j++;
            }
        }
       
    }
    printf("Rigged\n");
   
}

int main() {
    int nGuests;
    while(scanf("%d",&nGuests)!= EOF){
        if(nGuests<=0){
            continue;
        }
        int i;
        int * ptr = (int*) malloc(nGuests * sizeof(int));
        for(i=0;i<nGuests;i++){
            scanf("%d",&ptr[i]);
        }
	    
        /*printArray(ptr, n); */
	    quickSort(ptr, 0, nGuests-1); 
	    /*printArray(ptr, nGuests); */

        iceBreaker(ptr,nGuests);

        free(ptr);

    }
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(int size, int* list){
	if(size == 0){ return; }
	
	int *sorted = (int*)malloc(sizeof(int)*size);
	int smallercount = 0, largercount = 0;
	int pivot = list[0];

	for(int i = 1; i < size; i++){
		if(list[i] < pivot){
			sorted[smallercount++] = list[i];
		}
		else{
			sorted[size-1-largercount++] = list[i];
		}
	}
	sorted[smallercount] = pivot;
	memcpy(list, sorted, sizeof(int)*size);
	free(sorted);

	quicksort(smallercount, list);
	quicksort(largercount, list+smallercount+1);
}


int main(int argc, char** argv){
	int* list = (int*)malloc(sizeof(int)*(argc-1));
	int size = argc-1;

	for(int i = 1; i < argc; i++){
		list[i-1] = atoi(argv[i]);
	}

	quicksort(size, list); 

	for(int i = 0; i < size-1; i++){
		printf("%d ", list[i]);
	}
	printf("%d\n", list[size-1]);

	return 0;
}
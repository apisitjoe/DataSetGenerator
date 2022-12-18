#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <alloca.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <time.h>
#include <stack>
#include <deque>
#include <algorithm>

#include <iostream>
#include <omp.h>
#include <parallel/algorithm>

#define N 10000

#define INDEX uint64_t

//#define DataType uint32_t
//#define DataType uint64_t
#define DataType double
//#define DataMax UINT32_MAX
//#define DataMax UINT64_MAX
#define DataMax DBL_MAX

#define UNIQUE 100

#define REVERSED 0
#define NEARLYSORTED 0
#define FEWUNIQUE 0
void newinitData(DataType *arr, INDEX num){
	srand(time(NULL));
	__gnu_parallel::sort(&arr[left],&arr[right+1],__gnu_parallel::balanced_quicksort_tag());
}
void initData(DataType *arr,INDEX num){
	srand(time(NULL));
#if REVERSED
	for(INDEX i=0;i<num;i++){
        arr[i] = num-i;
    }
#else
	#if NEARLYSORTED
	
	for(INDEX i=0;i<num;i++){
		if(i%7==1||i%7==3||i%7==5)
			arr[i] = i-rand()%i;
		else
        	arr[i] = i;
    }
	#else
		#if FEWUNIQUE
			DataType unique[UNIQUE];
			for(INDEX i=0;i<UNIQUE;i++){
				unique[i] = rand()%DataMax;
			}
		    for(INDEX i=0;i<num;i++){
        		arr[i] = unique[rand()%UNIQUE];
   	 		}
		#else

    	for(INDEX i=0;i<num;i++){
        	arr[i] = rand()%DataMax;
   	 	}
   	 	#endif
    #endif
#endif
}

int main(){
	DataType* arr = (DataType*)malloc(sizeof(DataType)*N);
	initData(arr,N);
	
	int i;
	for(i=0;i<N;i++){
		std::cout<<arr[i]<<" ";
	}
	return 0;
}
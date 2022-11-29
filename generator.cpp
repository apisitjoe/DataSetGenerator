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

#define INDEX uint64_t
#define DataType uint32_t
#define DataMax UINT32_MAX
#define UNIQUE 100

#define REVERSED 0
#define NEARLYSORTED 0
#define FEWUNIQUE 0

void initData(DataType *arr,INDEX num){
	
#if REVERSED
	for(INDEX i=0;i<num;i++){
        arr[i] = num-i;
    }
#else
	#if NEARLYSORTED
	srand(time(NULL));
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
		
    	srand(time(NULL));
    	for(INDEX i=0;i<num;i++){
        	arr[i] = rand()%DataMax;
   	 	}
   	 	#endif
    #endif
#endif
}
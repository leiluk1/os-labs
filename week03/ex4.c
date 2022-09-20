#include <stdio.h>
#include <stdlib.h>

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){
    int* res = malloc(sizeof(int));
    *res = *((int*)a) + *((int*)b);
    return res;

}

void* addDouble(const void* a, const void* b){
    double* res = malloc(sizeof(double));
    *res = *((double*)a) + *((double*)b);
    return res;
        
}

void* mulInt(const void* a, const void* b){
    int* res = malloc(sizeof(int));
    *res = *((int*)a) * *((int*)b);
    return res;
    
}

void* mulDouble(const void* a, const void* b){
    double* res = malloc(sizeof(double));
    *res = *((double*)a) * *((double*)b);
    return res;

}

void* meanInt(const void* a, const void* b){

    //<WRITE YOUR CODE HERE>;
    
}

void* meanDouble(const void* a, const void* b){

    //<WRITE YOUR CODE HERE>;
    
}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){

	void* output;

	if (size==sizeof(int)){ // base is a pointer to an integer
	
	    //<WRITE YOUR CODE HERE>;


	}else{ // base is a pointer to a double
	
	    //<WRITE YOUR CODE HERE>;
	    
	}

	return output;
}




int main(){

        int* ints = malloc(sizeof(int)*5);
        double* doubles = malloc(sizeof(double)*5);
        
        //<WRITE YOUR CODE HERE>;


	// Addition
	
        int* result1a;
        
        //<WRITE YOUR CODE HERE>;
        
        printf("%d\n", *result1a);

	double* result2a;
	
	//<WRITE YOUR CODE HERE>;
	
        printf("%f\n", *result2a);
                

	// Multiplication
	
        int* result1m;
        
        //<WRITE YOUR CODE HERE>;
        
        printf("%d\n", *result1m);

	double* result2m;
	
        //<WRITE YOUR CODE HERE>;
	
        printf("%f\n", *result2m);
        
        
        
	// Mean
	
        int* result1mean;
        
        //<WRITE YOUR CODE HERE>;
    
        printf("%d\n", *result1mean);

	double* result2mean;
	
	//<WRITE YOUR CODE HERE>;
	
        printf("%f\n", *result2mean);
	
        
        // free the pointers
        //<WRITE YOUR CODE HERE>;


        return EXIT_SUCCESS;
}


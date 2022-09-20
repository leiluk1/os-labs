#include <stdio.h>
#include <stdlib.h>

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

struct Mean {
    double mean;
    int count;
};

typedef struct Mean Mean;

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
    Mean* m = (Mean*) a;
    int* elem = (int*) b;
    Mean* res = malloc(sizeof(Mean));
    res->count = m->count + 1;
    res->mean = (m->mean * m->count + *elem) / res->count;
    return res;
}

void* meanDouble(const void* a, const void* b){
    Mean* m = (Mean*) a;
    double* elem = (double*) b;
    Mean* res = malloc(sizeof(Mean));
    res->count = m->count + 1;
    res->mean = (m->mean * m->count + *elem) / res->count;
    return res;
}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){
    void* output = initial_value;
    void* prev;
    for (int i = 0; i < n; i++) {
        prev = output;
        output = opr(output, (base + i * size));
        if (i != 0) {
            free(prev);
        }
    }
    return output;
}

int main(){
    int* ints = malloc(sizeof(int)*5);
    double* doubles = malloc(sizeof(double)*5);
 
    int init1a = 0; 
    int init1m = 1;
    double init2a = 0;
    double init2m = 1;
    Mean init1mean = {0, 0}, init2mean = {0, 0};

    for (int i = 0; i < 5; i++) {
        scanf("%d", &ints[i]);
    }

    for (int i = 0; i < 5; i++) {
        scanf("%lf", &doubles[i]);
    }

	// Addition
	
    int* result1a = aggregate(ints, sizeof(int), 5, &init1a, addInt);
    printf("%d\n", *result1a);

	double* result2a = aggregate(doubles, sizeof(double), 5, &init2a, addDouble);
    printf("%f\n", *result2a);
                
	// Multiplication
	
    int* result1m = aggregate(ints, sizeof(int), 5, &init1m, mulInt);
    printf("%d\n", *result1m);

	double* result2m = aggregate(doubles, sizeof(double), 5, &init2m, mulDouble);
    printf("%f\n", *result2m);
              
	// Mean
    double* result1mean = aggregate(ints, sizeof(int), 5, &init1mean, meanInt);
    printf("%f\n", *result1mean);

	double* result2mean = aggregate(doubles, sizeof(double), 5, &init2mean, meanDouble);
    printf("%f\n", *result2mean);
    
    // // free the pointers
    free(result1a);
    free(result2a);
    free(result1m);
    free(result2m);
    free(result1mean);
    free(result2mean);
    
    return EXIT_SUCCESS;
}


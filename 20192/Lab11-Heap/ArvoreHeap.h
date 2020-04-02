#ifndef __ARVORE_HEAP__
#define __ARVORE_HEAP__ 1


typedef struct 	{ 	int* heap;
               		int numElem;
               		int maxElem;
               	} tHeap;
               
               
// ***********************************************
bool createHeap(tHeap* h, int n );

// ***********************************************
void clearHeap(tHeap* h );

// ***********************************************
bool insertHeap(tHeap* h, int k);

// ***********************************************
bool removeHeap(tHeap* h, int* k);

// ***********************************************
void upHeap(tHeap* h);

// ***********************************************
void downHeap(tHeap* h);

// ***********************************************

#endif // __ARVORE_HEAP__
    


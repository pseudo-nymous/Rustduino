#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// There are several bugs relating to memory on this snippet.
// Find them all!
// I have commented the errors and also correct ways of doing these

// Vector type can only hold ints.
typedef struct
{
    int *data;    // Pointer to our array on the heap
    int length;   // How many elements are in our array
    int capacity; // How many elements our array can hold
} vector;

vector *vector_new()
{
    // Error #1
    // is returning address of a local variable instead of a pointer to a vector
    /*vector *v;
  v->data=NULL;
  v->length=0;
  // Error #2
  //push operation will not work explained below.
  v->capacity= any non zero +ve small value; 
  return v;*/

    vector v;
    v.data = NULL;
    v.length = 0;
    v.capacity = 0;
    return &v;
}

void vector_push(vector *v, int n)
{
    //Error #3
    // It will not work as initially both are equal to zero
    // thus new capacity will also be zero implies new_data pointer will be null
    // solution is to give an initial capacity of non zero value
    if (v->length == v->capacity)
    {
        int new_capacity = v->capacity * 2;
        int *new_data = (int *)malloc(new_capacity);
        //Error #4
        //program dies here as initial push will always give new_data as NULL
        assert(new_data != NULL);

        for (int i = 0; i < v->length; ++i)
        {
            new_data[i] = v->data[i];
        }
        //Error 5
        // Failed to free the initial located memory
        // free(v->data);
        v->data = new_data;
        v->capacity = new_capacity;
    }

    v->data[v->length] = n;
    ++v->length;
}

void vector_free(vector *v)
{
    //Error #6
    //first free v->data then free v cuz after freeing v it will not be able to free v->data
    // free(v->data);
    // free(v);
    free(v);
    free(v->data);
}

void main()
{
    // All function call will also be invalid as functions are full of errors
    vector *v = vector_new();
    vector_push(v, 107);

    int *n = &v->data[0];
    vector_push(v, 110);
    printf("%d\n", *n);

    //Error #8
    // Do not free here its best to free in the fuction itself
    // remove free(v->data);
    free(v->data);
    vector_free(v);
}

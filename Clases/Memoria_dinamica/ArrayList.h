#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

typedef struct
{
    int size;
    int rSize;
    void **pElements;

}ArrayList;

#endif // ARRAYLIST_H_INCLUDED

#define INIT_SIZE 10

ArrayList* arrayList_new(void);
int arrayList_add(ArrayList* pArray, void *element);



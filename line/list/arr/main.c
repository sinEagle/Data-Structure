#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

int main() {
    sqlist *list = NULL, *list1 = NULL;
    datatype arr[] = {12, 23, 34, 45, 56};
    datatype arr1[] = {89, 90, 78, 67, 56, 45};
    list = sqlist_create();
    if(list == NULL) {
        fprintf(stderr, "sqlist_create() failed !\n");
        exit(1);
    }
    list1 = sqlist_create();
    if(list1 == NULL) {
        fprintf(stderr, "sqlist_create() failed !\n");
        exit(1);
    }
    int i, err;
    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++) {
        if((err = sqlist_insert(list, 0, &arr[i])) != 0) {
            if(err == -1) 
                fprintf(stderr, "The arr is full.\n");
            else if(err == -2) {
                fprintf(stderr, "The pos you want to insert is wrong.\n");
            } else {
                fprintf(stderr, "Error!\n");
            }
            exit(1);
        }
    }

    sqlist_display(list);
    
    for(i = 0; i < sizeof(arr1) / sizeof(*arr1); i++) {
        sqlist_insert(list1, 0, &arr1[i]);
    }
    sqlist_display(list1);

    sqlist_union(list, list1);
    sqlist_display(list);


#if 0
    sqlist_delete(list, 1);

    sqlist_display(list);
#endif
    sqlist_destory(list);
    sqlist_destory(list1);

    exit(0);
}

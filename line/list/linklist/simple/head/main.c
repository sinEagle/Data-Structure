#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    list * l;
    datatype arr[] = {12, 9,  23, 2, 34, 6, 45};

    l = list_create();
    if(l == NULL) exit(1);

    int i = 0;
    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++) {
        if(list_order_insert(l, &arr[i]) ) {
            exit(1);
        }
    }
    list_display(l);

    datatype value;
    int err = list_delete_at(l, 2, &value);
    if(err) exit(1);
    list_display(l);
    printf("delete:%d\n", value);

#if 0
    int value = 12;
    list_delete(l, &value);
    list_display(l);
#endif

    list_destory(l);

    exit(0);
}

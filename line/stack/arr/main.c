#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"



int main() {
    datatype arr[] = {19, 23, 0, 45, 67};
    sqstack * st;
    int i;

    st = st_create();
    if(st == NULL) exit(1);
    
    for(i = 0; i < sizeof(arr)/ sizeof(*arr); i ++) {
        st_push(st, &arr[i]);
    }

    st_travel(st);

    /*
    datatype tmp = 1;
    int ret = st_push(st, &tmp);
    if(ret != 0) printf("st_push failed.\n");
    else st_travel(st);

    */
    datatype tmp;
    while(st_pop(st, &tmp) == 0) {
        printf("POP: %d\n", tmp);
    }

    
    st_destory(st);
    exit(0);
}

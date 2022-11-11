#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main() {
    queue * sq;
    datatype arr[] = {2, 34, 98, 12};

    sq = qu_create();
    if (sq == NULL) exit(1);

    int i;
    for (i = 0; i < sizeof(arr)/sizeof(*arr); i ++) {
        qu_enqueue(sq, &arr[i]);
    }
    qu_travel(sq);

#if 0    
    
    datatype tmp = 100;
    if (qu_enqueue(sq, &tmp) == -1) {
        printf("queue is full! \n");
    } else
        qu_travel(sq);
#endif
    
    datatype tmp;
    qu_dequeue(sq, &tmp);
    printf("DEQUEUE : %d\n", tmp);

    qu_travel(sq);

    
    qu_destroy(sq);

    exit(0);
}

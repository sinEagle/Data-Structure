#include <stdio.h>
#include <stdlib.h>
#include "nohead.h"

int main() {
    struct node_st * list = NULL;
    struct score_st tmp;
    int i, ret;
    for(i = 0; i < 7; i ++) {
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "stu%d", i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;

        ret = list_insert(&list, &tmp);
        if(ret != 0) exit(1);

    }
    list_show(list);
    printf("\n\n");
    list_delete(&list);

    list_show(list);
    printf("\n\n");

    int id = 3;
    struct score_st * ptr;
    ptr = list_find(list, id);
    if(ptr == NULL) {
        printf("Can not find ! \n");
    } else {
        printf("%d %s %d %d\n", ptr->id, ptr->name, ptr->math, ptr->chinese);
    }

    list_destory(list);

    exit(0);
}

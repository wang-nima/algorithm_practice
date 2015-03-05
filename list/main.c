#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t myList;

typedef struct MyStruct {
	int num;
	list_link_t l;
}MyStruct;

int main() {
	list_init(&myList);
	if(list_empty(&myList)) {
		printf("empty list\n");
	} else {
		printf("list is not empty\n");
	}
	MyStruct *p;
	int i;
	for(i = 0; i < 10; i++) {
		p = (MyStruct*)malloc(sizeof(MyStruct));
		p->num = i;
		list_insert_before(&myList, &(p->l));
	}
	list_iterate_begin(&myList, p, MyStruct, l) {
		printf("%d\n", p->num);
	} list_iterate_end();
	return 0;
}

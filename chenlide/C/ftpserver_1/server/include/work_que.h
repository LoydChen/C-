#ifndef __WORK_QUE_H__
#define __WORK_QUE_H__

#include "head.h"

typedef struct node{
	int new_fd;
	char pwd[128];
	struct node* next;
}node_t,*pnode;

typedef struct{
	pnode head,tail;
	pthread_mutex_t mutex;
	int size;
}que_t,*pque;

void que_init(pque);

#endif

#include "factory.h"

void que_init(pque pq){
	pq->head = NULL;
	pq->tail = NULL;
	pthread_mutex_init(&pq->mutex,NULL);
	pq->size = 0;
}

void que_insert(pque pq,pnode pnew){
	pthread_mutex_lock(&pq->mutex);
	if(pq->tail == NULL){
		pq->head = pnew;
		pq->tail = pnew;
	}else{
		pq->tail->next == pnew;
		pq->tail = pnew;
	}
	(pq->size)++;
	pthread_mutex_unlock(&pq->mutex);

}

void que_get(pfactory pf,pnode* pget){
	pthread_mutex_lock(&(pf->fque.mutex));
	while(pf->fque.size == 0){
		pthread_cond_wait(&pf->cond,&(pf->fque.mutex));
	}
	*pget = pf->fque.head;
	pf->fque.head = pf->fque.head->next;
	(pf->fque.size)--;
	if(pf->fque.size == 0){
		pf->fque.tail = NULL;
	}
	pthread_mutex_unlock(&(pf->fque.mutex));
}

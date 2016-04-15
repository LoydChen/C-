#include "factory.h"

void factory_init(pfactory pf,pfunc pth_pfunc,int pth_num,int capability){
	pf->p = pth_pfunc;
	pf->pth = (pthread_t*)malloc(pth_num * sizeof(pthread_t));
	pf->pnum = pth_num;
	que_init(&pf->fque);
	pf->capability = capability;
	pthread_cond_init(&pf->cond,NULL);
	pf->flag = 0;
}

void factory_start(pfactory pf){
	int i;
	int ret;
	for(i=0;i<pf->pnum;i++){
		ret = pthread_create(&(pf->pth)[i],NULL,pf->p,(void*)pf);
		if(ret != 0){
		printf("pthread_create failed!\n");
			exit(-1);
		}
	}
	pf->flag = 1;
}

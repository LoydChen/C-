#include "factory.h"

int main(){
	char buf1[15] = {0};
	char buf2[5] = {0};
	char buf3[5] = {0};
	char buf4[5] = {0};
    int fd_conf;
	fd_conf = open("../conf/config",O_RDONLY);
    if(fd_conf == -1){
        perror("open");
    }
	read(fd_conf,buf1,12);
	read(fd_conf,buf2,4);
	read(fd_conf,buf3,2);
	read(fd_conf,buf4,3);
    close(fd_conf);    
	int num = atoi(buf3);
	int cap = atoi(buf4);
	factory f;
	factory_init(&f,child_handle,num,cap);
	factory_start(&f);
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sfd){
		perror("socket");
		return -1;
	}
	int ret;
	struct sockaddr_in ser;
	ser.sin_family = AF_INET;
	ser.sin_port = htons(atoi(buf2));
	ser.sin_addr.s_addr = inet_addr(buf1);
	ret = bind(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	if(-1 == ret){
		perror("bind");
		return -1;
	}
	listen(sfd,cap);
	int epfd = epoll_create(1);
	if(-1 == epfd){
		perror("epoll_create");
		return -1;
	}
	struct epoll_event event;
	event.events = EPOLLIN;
	event.data.fd = sfd;
	ret = epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&event);
	pnode pnew;

	while(1){
		ret = epoll_wait(epfd,&event,1,-1);
		if(ret > 0){
			if(event.events == EPOLLIN && event.data.fd == sfd){
				pnew = (pnode)malloc(sizeof(node_t));
				pnew->new_fd = accept(sfd,NULL,NULL);
				getcwd(pnew->pwd,sizeof(pnew->pwd));
				if(-1 == pnew->new_fd){
					perror("accept");
					return -1;
				}
				que_insert(&f.fque,pnew);
				pthread_cond_signal(&f.cond);
			}
		}
	}
}	

void* child_handle(void *p){
	pfactory fp = (pfactory)p;
	pnode pget;
	while(1){
		que_get(fp,&pget);
		char buf[128] = {0};
		char tmp[128] = {0};
		int i;
		int ret;
		printf("connect success!pthread_id %d\n",(unsigned)pthread_self());
		while(1){
			ret = recv(pget->new_fd,buf,sizeof(buf),0);
			if(ret == -1){
				printf("recv failed!\n");
			}
			if(strncpy(tmp,buf,2),!strcmp(tmp,"cd")){
				command_cd(pget->new_fd,buf,sizeof(buf),pget->pwd);
			}else if(!strcmp(tmp,"ls")){
				send(pget->new_fd,pget->pwd,sizeof(pget->pwd),0);
			}else if(strncpy(tmp,buf,3),!strcmp(tmp,"pwd")){
				send(pget->new_fd,pget->pwd,sizeof(pget->pwd),0);
			}else if(strncpy(tmp,buf,4),!strcmp(tmp,"gets")){
				command_gets(pget->new_fd,buf,sizeof(buf),pget->pwd);
			}else if(!strcmp(tmp,"puts")){
				recv(pget->new_fd,buf,1,0);
				if(buf[0] == '1'){
					command_puts(pget->new_fd,pget->pwd);
				}else{
					printf("wrong wrong wong !\n");
				}
			}else if(strncpy(tmp,buf,6),!strcmp(tmp,"remove")){
				command_remove(pget->new_fd,buf,sizeof(buf),pget->pwd);
			}
			bzero(buf,sizeof(buf));
			bzero(tmp,sizeof(tmp));
		}
		free(pget);
	}
}

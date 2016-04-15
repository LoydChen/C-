#include "func.h"

void recv_file(int sfd){
	int ret;	
	char buf[1024] = {0};
	int len;
	recv_n(sfd,(char*)&len,sizeof(int));
	recv_n(sfd,buf,len);
//	printf("file name : %s\n",buf);
	int fd = open(buf,O_CREAT|O_RDWR,0666);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	while(1){
		recv_n(sfd,(char*)&len,sizeof(int));
		if(len == 0){
			break;
		}
		bzero(buf,sizeof(buf));
		recv_n(sfd,buf,len);
		ret = write(fd,buf,len);
		if(-1 == ret){
			perror("write");
			exit(-1);
		}
	}
	close(fd);
}

void transmit_file(int new_fd,char* buf,int len){
	int i;
	char buf1[20];
	for(i=5;i<len-1;i++){
		buf1[i-5] = buf[i];
	}
	int fd = open(buf1,O_RDONLY);
	if(fd == -1){
		send(new_fd,"0",1,0);
		printf("puts file fail!\n");
		close(fd);
	}else{
		send(new_fd,"1",1,0);
		send_file(new_fd,buf1,strlen(buf1));
		printf("puts file success!\n");
	}
	
}	

void command_ls(char* pwd){
	DIR *pDir;
    struct dirent *d;
    struct stat bufs;
    char p[128];
    char t[128];
    pDir = opendir(pwd);
    if(NULL == pDir){
        perror("open dir fail!");
    }
    char buf[128] = {0};
    while((d=readdir(pDir))!=NULL){
        bzero(p,sizeof(p));
        sprintf(p,"%s/%s",pwd,d->d_name);
        stat(p,&bufs);
        bzero(t,sizeof(t));
        strncpy(t,ctime(&bufs.st_mtime)+4,15);
        
        if(d->d_name[0] != '.'){
            printf("%-13s%10d%20s\n",d->d_name,(int)bufs.st_size,t);
        }
    }

}

int main(){
	int fd_conf;
	fd_conf = open("../conf/config",O_RDONLY);
	if(fd_conf == -1){
		perror("open");
	}
	char buf1[15] = {0},buf2[5] = {0};
	read(fd_conf,buf1,12);
	read(fd_conf,buf2,4);
	close(fd_conf);
	int sfd;
	sfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sfd){
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family = AF_INET;
	ser.sin_port = htons(atoi(buf2));
	ser.sin_addr.s_addr = inet_addr(buf1);
	int ret;
	ret = connect(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	if(-1 == ret){
		perror("connect");
		return -1;
	}
	
	int i;
	char buf[128] = {0};
	char tmp[128] = {0};
	while(1){
		read(0,buf,sizeof(buf));
		ret = send(sfd,buf,strlen(buf)-1,0);
		if(ret == -1){
			printf("send failed\n");
		}
		strncpy(tmp,buf,2);
		if(!strcmp(tmp,"ls")){
			bzero(buf,sizeof(buf));
			recv(sfd,buf,sizeof(buf),0);
			command_ls(buf);
		}else if(!strcmp(tmp,"cd")){
			bzero(buf,sizeof(buf));
			recv(sfd,buf,sizeof(buf),0);
			printf("%s",buf);
		}	
		strncpy(tmp,buf,3);
		if(!strcmp(tmp,"pwd")){
			bzero(buf,sizeof(buf));
			recv(sfd,buf,sizeof(buf),0);
			printf("%s\n",buf);
		}
		strncpy(tmp,buf,4);
		if(!strcmp(tmp,"gets")){
			bzero(buf,sizeof(buf));
			recv(sfd,buf,sizeof(buf),0);
			printf("%s",buf);
			if(buf[10] == 's'){
				recv_file(sfd);
			}
		}else if(!strcmp(tmp,"puts")){
			transmit_file(sfd,buf,strlen(buf));
		}
		strncpy(tmp,buf,6);
		if(!strcmp(tmp,"remove")){
			bzero(buf,sizeof(buf));
			recv(sfd,buf,sizeof(buf),0);
			printf("%s",buf);
		}
		bzero(buf,sizeof(buf));
		bzero(tmp,sizeof(tmp));	
	}
	close(sfd);
	return 0;
}

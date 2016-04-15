#include "head.h"

void send_file(int sfd,char* buf,int len,char* pwd){
	data d;
	bzero(&d,sizeof(d));
	d.len = len;
	strcpy(d.buf,buf);
	int ret,fd;
	fd = open(pwd,O_RDONLY);
	if(-1 == fd){
		perror("open");
		exit(-1);
	}
	send_n(sfd,(char*)&d,4+d.len);
	while(1){
		bzero(&d,sizeof(d));
		d.len=read(fd,d.buf,sizeof(d.buf));
		if(d.len>0){
			send_n(sfd,(char*)&d,4+d.len);
		}else if(d.len == 0){
			send_n(sfd,(char*)&d,4+d.len);
			break;
		}else{
			perror("read");
			exit(-1);
		}
	}
	close(fd);
	return;
}

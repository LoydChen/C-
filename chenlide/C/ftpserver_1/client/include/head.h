#ifndef __HEAD_H__
#define __HEAD_H__
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
typedef struct {
	int len;
	char buf[1000];
}data;

void send_file(int,char*,int,char*);
int send_n(int,char*,int);

#define DOWNLOAD "file"

#endif

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


typedef struct{
	pid_t pid;
	int fdw;
	int busy;
}child,*pchild;

typedef struct{
	int len;
	char buf[1000];
}data;

void child_create(pchild,int);
void child_handle(int);
void send_file(int,char*,int);
int send_n(int,char*,int);
void send_message(int,int);
void recv_message(int,int*);

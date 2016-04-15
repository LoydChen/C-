#include "factory.h"

void change_pwd(char* pwd,char* buf,int len){
//更改相对路径为绝对路径
	char pwd_cp[128];
	strcpy(pwd_cp,pwd);
    char tmp1[128] = {0};
    char tmp2[128] = {0};
    int count;
    tmp2[0] = '/';
    int i,j;
    count = 0;  
    for(i=3;i<len;i++){
       if(buf[i] == '.'){
            count++;
        }
     }
    if(count == 0){
        for(i=3;i<len;i++){
            tmp2[i-2] = buf[i];
        }   
    }else if(count == 1){
        for(i=5;i<len;i++){
            tmp2[i-4] = buf[i];
        }
    }else{
        for(i=3;buf[i] != '/'  && i < len; i++){
            tmp1[i-3] = buf[i]; 
        }
        for(i=3+3*count/2;i<len;i++){
            tmp2[i-(3+3*count/2)+1] = buf[i];
        }   
        count = count/2;
    }

    if(!strcmp(tmp1,"..")){
        for(i=strlen(pwd);i>0;i--){
            if(pwd[i] == '/'){
                count--;
                if(count==0){
                    pwd[i] = '\0';
                    break;
                }
            }
        }
    }

    strcat(pwd,tmp2);
	int pwd_len = strlen(pwd) - 1;
    if(pwd[pwd_len] == '/'){
		pwd[pwd_len] = '\0';
	}
	DIR *pDir;
	pDir = opendir(pwd);
	if(NULL == pDir){
		strcpy(pwd,pwd_cp);
	}
}

void command_cd(int new_fd,char* buf,int len,char* pwd){
	printf("%s\n",pwd);
	change_pwd(pwd,buf,len);
	printf("%s\n",pwd);
	int ret = chdir(pwd);
	if(ret == -1){
		send(new_fd,"cd error!\n",11,0);
	}else{
		send(new_fd,"cd success!\n",13,0);
	}
}

void command_gets(int new_fd,char* buf,int len,char* pwd){
	char pwd_cp[128];
	strcpy(pwd_cp,pwd);
	
	int i;
	for(i=5;i<len;i++){
		buf[i-5] = buf[i];
	}
	strcat(pwd,"/");	
	strcat(pwd,buf);
	int fd = open(pwd,O_RDONLY);
	if(fd == -1){	
		send(new_fd,"no such file!\n",15,0);
		printf("puts file fail!\n");
	}else{
		send(new_fd,"gets file success!\n",21,0);
		sleep(1);
		send_file(new_fd,buf,sizeof(buf),pwd);
		printf("puts file success!\n");
	}
	strcpy(pwd,pwd_cp);
}

void command_puts(int new_fd,char* pwd){	
	printf("%s\n",pwd);
	char pwd_cp[128];
	strcpy(pwd_cp,pwd);
    int ret;        
    char buf[1024] = {0};
	int len;
    recv_n(new_fd,(char*)&len,sizeof(int));
    recv_n(new_fd,buf,len);
	
	strcat(pwd,"/");	
	strcat(pwd,buf);
	printf("%s\n",pwd);
    int fd = open(pwd,O_CREAT|O_RDWR,0666);
    if(-1 == fd){
        perror("open");
        exit(-1);
    }   
    while(1){
        recv_n(new_fd,(char*)&len,sizeof(int));
        if(len == 0){ 
            break;
        }   
        bzero(buf,sizeof(buf));
        recv_n(new_fd,buf,len);
        ret = write(fd,buf,len);
        if(-1 == ret){
            perror("write");
            exit(-1);
        }   
    }
	printf("gets file success!\n");   
	strcpy(pwd,pwd_cp);
	printf("%s\n",pwd);
	close(fd);	
}

void command_remove(int new_fd,char* buf,int len,char* pwd){
	char pwd_cp[128];
	strcpy(pwd_cp,pwd);
	int i;
	for(i=7;i<len;i++){
		buf[i-7] = buf[i];
	}
	strcat(pwd,"/");	
	strcat(pwd,buf);
	printf("%s\n",pwd);
	
	i = remove(pwd);
	if(-1 == i){
		send(new_fd,"remove fail!\n",14,0);	
		printf("remove file fail!\n");
	}else{
		send(new_fd,"remove success!\n",17,0);
		printf("remove file success!\n");
	}
	strcpy(pwd,pwd_cp);
}

 ///
 /// @file    malloc_new.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-16 15:01:20
 ///
 
#include <iostream>
#include <string.h>

int a = 10;
char *p1;

int main(){
	int b;
	char s[] = "abc";
	char *p2;
	char *p3 = "123456";
	static int c = 0;
	p1 = new char[10];
	p2 = new char[5];
	strcpy(p1,"123456");
}

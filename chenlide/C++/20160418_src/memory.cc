 ///
 /// @file    memory.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-18 11:04:02
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


int a = 0;
char * p1;

int main(void)
{
	int b;
	char s[] = "123456";
	char * p2;
	char * p3 = "123456";
	static int c = 10;
	p1 = new char [10];
	p2 = new char [10];
	strcpy(p1, "123456");

	printf("&a  = %p\n", &a);
	printf("&p1 = %p\n", &p1);
	printf("p1  = %p\n", p1);

	printf("&b  = %p\n", &b);
	printf("s =   %p\n", s);
	printf("&p2 = %p\n", &p2);
	printf("p2  = %p\n", p2);
	printf("&p3 = %p\n", &p3);
	printf("p3 = %p\n", p3);
	printf("&c  = %p\n", &c);

	return 0;
}

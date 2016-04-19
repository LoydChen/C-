 ///
 /// @file    io.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-18 10:30:54
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;


int main(void)
{
	int a;
#if 0
	while(scanf("%d", &a))
	{
		printf("a = %d\n", a);
	}
#endif


	string str;
#if 0 
	while(cin >> str)//以空格去分隔字符串
	{
		cout << "str = " << str << endl;
	}
#endif
	while(getline(cin, str))//读取一行
	{
		cout << "str = " << str << endl;
	}
}

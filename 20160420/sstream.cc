 ///
 /// @file    sstream.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-20 21:41:17
 ///
 
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;

int test1(){
	int num1 = 128;
	int num2 = 998;
	stringstream ss;
	ss << "num1 = " << num1 << ",num2 = " << num2 << endl;
	string str = ss.str();
	cout << str << endl;

	char buf[128];
	sprintf(buf,"num1 = %d,num2 = %d\n",num1,num2);
	cout << buf << endl;
	return 0;
}

int test2(){
	string s = "hello world wangdao c++";

	string word;
	istringstream iss(s);
	while(iss >> word){
		cout << word << endl;
	}
	return 0;
}

int main(){
	int num = 20;
	ostringstream oss;
	oss << num;
	string numstr = oss.str();
	cout << numstr << endl;
}

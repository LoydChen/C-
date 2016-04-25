 ///
 /// @file    string_sub.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-18 19:24:25
 ///
 
#include <iostream>
using namespace std;

int main(){
	string s1("hello,world");
	s1 = s1.substr();
	cout << "s1 = " << s1 << endl;
	string s2;
	s2 = s1.substr(0,5);
	cout << "s2 = " << s2 << endl;
	string s3;
	s3 = s1.substr(6,5);
	cout << "s3 = " << s3 << endl;
	return 0;
}

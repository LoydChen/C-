 ///
 /// @file    string_earse.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-18 19:10:01
 ///
 
#include <iostream>
using namespace std;

int main(){
	string s1 = "helloo,world";
	cout << "s1 = " << s1 << endl;
	s1.erase(5,1);//从s1[5]开始删除一个元素，若不填第二个参数，默认到结尾
	cout << "s1 = " << s1 << endl;
	return 0;
}


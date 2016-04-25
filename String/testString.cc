 ///
 /// @file    testString.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-25 20:01:18
 ///

#include "func.h"
using std::cout;
using std::endl;

int main(){
	String s1 = "hello world";
	s1 += "!";
	cout << "s1.size() = " << s1.size()  << endl;
	String s2(s1);
	cout << (s2 == s1) << endl;
	std::cin >> s1;
	cout << s1 << endl;
	s1 + "helloaskdj haq" = s2;
}

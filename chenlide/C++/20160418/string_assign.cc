 ///
 /// @file    string_assign.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-18 19:03:55
 ///
 
#include <iostream>
using namespace std;

int main(){
	string s1 = "hello";
	string s2;
	s2.assign("world");
	cout << s1 << "," << s2 << endl;
	s1 = "";
	s2.erase();
	cout << s1 << "," << s2 << endl;
	return 0;
}

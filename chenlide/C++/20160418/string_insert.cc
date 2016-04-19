 ///
 /// @file    string_insert.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-18 19:18:40
 ///
 
#include <iostream>
using namespace std;

int main(){
	string s1 = "helloworld";
	s1.insert(5,",");
	cout << "s1 = " << s1 << endl;
	return 0;
}

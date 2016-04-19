 ///
 /// @file    string_assign.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-18 18:42:36
 ///
 
#include <iostream>
using namespace std;

int main(){
	string s1 = "hello";
	string s2 = ",world!";
//	s1 += s2;
	s1.append(s2);
	cout << "s1 =  "<< s1 << endl;
	
	return 0;
}


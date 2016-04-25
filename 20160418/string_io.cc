 ///
 /// @file    string_io.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-18 17:35:18
 ///
 
#include <iostream>
using namespace std;

int main(){
	string str;
#if 0
	while(cin >> str){
		cout << str << endl;
	}
#endif
	while(getline(cin,str)){
		cout << str << endl;
	}
	return 0;
}

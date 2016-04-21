 ///
 /// @file    io2.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-20 20:24:50
 ///
 
#include <iostream>
#include <limits>
using namespace std;

int main(){
	int inum;
	while(cin >> inum,!cin.eof()){
		if(cin.bad()){
			cout << "IO stream is corrupted!!!" << endl;
			return -1;
		}
		if(cin.fail()){
			cout << "error input ! try again !" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			continue;
		}
		cout << "num = " << inum << endl;
	}
}

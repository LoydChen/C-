 ///
 /// @file    io1.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-20 20:10:09
 ///
 
#include <iostream>
#include <limits>
#include <string>
using namespace std;

void printbit(){
	cout << "bad = " << cin.bad() << endl;
	cout << "fail = " << cin.fail() << endl;
	cout << "eof = " << cin.eof() << endl;
	cout << "good = " << cin.good() << endl;
}

int main(){
	printbit();
	int inum;
	while(cin >> inum){
		cout << "inum = " << inum << endl;
	}
	printbit();
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << endl;
	printbit();

	string str;
	getline(cin,str);
	cout << str << endl;

	return 0;


}

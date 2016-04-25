 ///
 /// @file    fstream2.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-20 21:06:05
 ///
 
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	ifstream ifs("vector.cc");
	if(!ifs.good()){
		cout << "ifstream error !" << endl;
		return -1;
	}

	ofstream ofs("vector.txt");
	if(!ofs.good()){
		cout << "ofstream error !" << endl;
		return -1;
	}

	string str;
	while(getline(ifs,str)){
		ofs << str << endl;
	}
	cout << "copy success!" << endl;
	ifs.close();
	ofs.close();
	return 0;
}


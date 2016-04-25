 ///
 /// @file    fstream3.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-20 21:13:24
 ///
 
#include <iostream>
#include <fstream>
using namespace std;

int test1(){
	ofstream ofs("vector.txt",ios::app);
	if(!ofs.good()){
		cout << "ofstream error!" << endl;
		return -1;
	}

	int pos = ofs.tellp();
	cout << "pos = " << pos << endl;
	return 0;
}

int test2(){
	ifstream ifs("vector.txt",ios::ate);
	if(!ifs.good()){
		cout << "ifstream error !" << endl;
	}
	
	int pos = ifs.tellg();
	cout << "pos = " << pos << endl;
	return 0;
}

int main(){
	fstream fs("io.txt",ios::in|ios::out);
	if(!fs.good()){
		cout << "fstream error !" << endl;
		return -1;
	}

	int val;
	for(int i=0;i < 10; i++){
		cin >> val;
		fs << val << " ";
	}
	cout << endl;

	int pos = fs.tellg();
	cout << "pos = " << pos << endl;

	fs.seekg(0,ios::beg);
	pos = fs.tellg();
	cout << "pos = " << pos << endl;

	for(int i=0;i<10;i++){
		fs >> val;
		cout << val << endl;
	}

	return 0;

}

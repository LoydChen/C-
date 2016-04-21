 ///
 /// @file    fstream1.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-20 20:57:24
 ///
 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ifstream ifs("vector.cc");
	if(!cin.good()){
		cout << "ifstream error !" << endl;
		return -1;
	}

	string str;
	vector<string> strVec;
	while(getline(ifs,str)){
		strVec.push_back(str);
	}

	for(int i = 0; i < strVec.size(); i++){
		cout << strVec[i] << endl;
	}
	ifs.close();
	return 0;
}

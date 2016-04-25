 ///
 /// @file    vector.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-20 20:40:41
 ///
 
#include <iostream>
#include <vector>
using namespace std;

void printSize(vector<int> & vec){
	cout << "size = " <<vec.size() << endl;
	cout << "capacity = " << vec.capacity() << endl;
}



int main(){
	vector<int> intVec;
	intVec.reserve(5);

	intVec.push_back(1);
	printSize(intVec);
	intVec.push_back(2);
	intVec.push_back(3);
	intVec.push_back(4);
	intVec.push_back(5);
	intVec.push_back(6);
	printSize(intVec);
	
	int i;
	for(i=0;i<intVec.size();i++){
		cout << intVec[i] << endl;
	}

	return 0;
}



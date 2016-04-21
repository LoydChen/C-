 ///
 /// @file    sizeof.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-19 15:33:46
 ///

#include <string.h>
#include <iostream>
using namespace std;

class date{
	int a;// 4
	double b;//4(waste) + 8
	float c;//4
	short d[6];//4 + 8
	char e[5];//5
	char & f;//3(waste) + 8
	double* g;// 8
};

int main(){
	cout << "sizeof(date) = " << sizeof(date) << endl;
	return 0;
}

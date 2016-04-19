 ///
 /// @file    const.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-16 15:46:07
 ///
 
#include <iostream>

using namespace std;

int main(){
	const int a = 10;
	//a = 20;

	int ia = 10;
	int ib = 20;
	//const int* pa = &ia;
	int const* pa = &ia;
	//*pa = 20;
	pa = &ib;
	//cout << "*pa = "<< *pa << endl;

	int* const pb = &ib;
	*pb = 40;
	//pb = &ia;
	//cout << "pb = "<< *pb << endl;

	const int* const pd = &ia;
	//*pd = 45;
	//pd = &ib;
	cout << "pd = "<< *pd << endl;


	return 0;
}

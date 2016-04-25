 ///
 /// @file    m_brackets.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-24 20:59:48
 ///

#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class CharArr{
	public:
		CharArr(int size)
		: _len(size){
			_pBuf = new char[_len];
		}
		
		~CharArr(){
			delete [] _pBuf;
		}

		int getLength(){
			return _len;
		}
		
		char & operator[](int idx);

	private:
		int _len;
		char * _pBuf;
};

char & CharArr::operator [](int idx){
	cout << "operator [] " << endl;
	static char nullchar = '\0';
	if(idx < _len && idx >= 0){
		return _pBuf[idx];
	}else{
		cout << "error !" << endl;
		return nullchar;
	}
}

int main(){
	char pstr[] = "hello,word";
	CharArr ca(strlen(pstr) + 1);
	for(int idx=0;idx != ca.getLength(); ++idx){
		ca[idx] = pstr[idx];	
	}

	for(int idx=0;idx != ca.getLength(); ++idx){
		cout << ca[idx];
	}
	cout << endl;
	return 0;
}

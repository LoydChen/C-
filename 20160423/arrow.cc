 ///
 /// @file    arrow.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-24 20:48:48
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data{
	public:
		int getlength(){
			return 5;
		}
};

class DataPtr{
	public:
		DataPtr(){
			_pData = new Data;
		}

		~DataPtr(){
			delete _pData;
		}

		Data * operator ->(){
			cout << "operator->()" << endl;
			return _pData;
		}

		Data * getDataPtr(){
			return _pData;
		}
	private:
		Data * _pData;
};

int main(){
	DataPtr dp;
	cout << dp->getlength() << endl;
	cout << dp.getDataPtr()->getlength() << endl;
	return 0;
}


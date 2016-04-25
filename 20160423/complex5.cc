 ///
 /// @file    complex.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-23 00:10:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex{
	public:
		Complex(double dreal,double dimag = 0)
		:	_dreal(dreal)
		,	_dimag(dimag)
		{}
		friend Complex operator + (const Complex &lhs,const Complex &rhs);
		friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
		friend std::istream & operator>>(std::istream & is, Complex & rhs);

		void print(){
			if(_dreal != 0){
				cout << _dreal;
				_dimag > 0 ? cout << "+" << _dimag : cout << "-" << _dimag *(-1);
				cout << "i" << endl;
			}else{
				if(_dimag != 0){
					_dimag > 0  ? cout << "+" : cout << "-";
					cout << _dimag << "i" << endl;
				}else{
					cout << "0" << endl;
				}
			}
		}
	private:
		double _dreal;
		double _dimag;
};

Complex operator + (const Complex &lhs,const Complex &rhs){
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimag + rhs._dimag);
}

std::ostream & operator << (std::ostream & os,const Complex & rhs){
	if(rhs._dreal != 0){
		os << rhs._dreal;
		rhs._dimag > 0 ? os << "+" << rhs._dimag : os << "-" << rhs._dimag *(-1);
		os << "i" << endl;
	}else{
		if(rhs._dimag != 0){
			rhs._dimag > 0  ? os << "+" : os << "-";
			os << rhs._dimag << "i" << endl;
		}else{
			os << "0" << endl;
		}
	}
}

std::istream & operator>>(std::istream & is, Complex & rhs)
{
	is >> rhs._dreal;
	while(is.get() != '*');
	is >> rhs._dimag;
	return is;
}


int main(){
	Complex cxn1(1,-2);
	cxn1.print();
	Complex cxn2(-4,3);
	cxn2.print();
	Complex cxn3 = cxn1 + cxn2;
	cxn3 = 5 + cxn2;
	cxn3.print();
	cout << "cxn3 = " << cxn3 << endl;
	std::cin >> cxn3;
	cout << "cxn3 = " << cxn3 << endl;

	return 0;
}

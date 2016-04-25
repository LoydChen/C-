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
		Complex(double dreal,double dimag)
		:	_dreal(dreal)
		,	_dimag(dimag)
		{}
		friend Complex operator + (const Complex &lhs,const Complex &rhs);
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

int main(){
	Complex cxn1(1,-2);
	cxn1.print();
	Complex cxn2(-4,3);
	cxn2.print();
	Complex cxn3 = cxn1 + cxn2;
	cxn3.print();
	return 0;
}

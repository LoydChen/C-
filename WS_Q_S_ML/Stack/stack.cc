 ///
 /// @file    stack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-25 16:07:39
 ///
 
#include "stack.h"
#include <iostream>
using std::cout;
using std::endl;

Stack::Stack(int num)
: _size(num)
, _top(-1)
{
	_vecInt.reserve(num);
}


void Stack::push(int num)
{
	if(!full())
	{
		++_top;
		_vecInt[_top] = num;
	}
}

void Stack::pop()
{
	if(empty())
	{
		cout << "栈空" << endl;
	}
	else
		--_top;
}

int Stack::top()
{
	if(_top != -1 )
		return _vecInt[_top];
}

bool Stack::empty()
{
	return _top == -1;
}

bool Stack::full()
{
	return _top == (_size - 1);
}

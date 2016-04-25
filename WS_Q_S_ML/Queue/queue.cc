 ///
 /// @file    queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-25 16:45:14
 ///
 
#include "queue.h"
#include <iostream>
using std::cout;
using std::endl;


Queue::Queue(int size)
: _size(size)
, _front(0)
, _end(0)
{
	_vecInt.reserve(_size);
}

void Queue::push(int num)
{
	if(!full())
	{
		_vecInt[_end] = num;
		_end = (_end + 1) % _size;
	}
}

void Queue::pop()
{
	if(!empty())
	{
		_front = (_front + 1) % _size;
	}
}

int Queue::front()
{
	return _vecInt[_front];
}

int Queue::back()
{
	return _vecInt[(_end - 1 + _size) % _size];
}

bool Queue::empty()
{
	return _front == _end;
}

bool Queue::full()
{
	return _front == (_end + 1) % _size;
}

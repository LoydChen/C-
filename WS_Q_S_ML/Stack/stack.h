 ///
 /// @file    stack.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-25 16:04:37
 ///

#ifndef __MY_STACK_H_
#define __MY_STACK_H_

#include <vector>
using std::vector;

class Stack
{
public:
	Stack(int num);
	void push(int num);
	void pop();
	int top();
	bool empty();
	bool full();
private:
	int _size;
	int _top;
	vector<int> _vecInt;
};


#endif

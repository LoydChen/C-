 ///
 /// @file    testStack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-25 16:14:59
 ///

#include "stack.h"
#include <iostream>
using std::cout;
using std::endl;


int main(void)
{
	Stack stack(10);
	stack.push(10);
	stack.push(12);
	stack.push(14);
	cout << "栈顶元素:" << stack.top() << endl;
	stack.pop();
	cout << "栈顶元素:" << stack.top() << endl;
	stack.pop();
	cout << "栈顶元素:" << stack.top() << endl;
	stack.pop();
	cout << "栈顶元素:" << stack.top() << endl;
	stack.pop();

}

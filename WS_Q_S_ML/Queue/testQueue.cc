 ///
 /// @file    testQueue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-25 16:52:36
 ///
 
#include "queue.h"
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	Queue que(4);
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	cout << "队头元素:" << que.front()<< endl;
	cout << "队尾元素:" << que.back()<< endl;
	que.pop();
	cout << "队头元素:" << que.front()<< endl;
	cout << "队尾元素:" << que.back()<< endl;
	que.push(4);
	cout << "队头元素:" << que.front()<< endl;
	cout << "队尾元素:" << que.back()<< endl;


	
	return 0;

}

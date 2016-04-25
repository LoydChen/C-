 ///
 /// @file    queue.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-25 16:41:50
 ///

#ifndef __MY_QUEUE_H_
#define __MY_QUEUE_H_

#include <vector>
using std::vector;


class Queue
{
public:
	Queue(int size);

	void push(int num);
	void pop();
	int front();
	int back();
	bool empty();
	bool full();
private:
	vector<int> _vecInt;
	int _size;
	int _front;
	int _end;
};

#endif


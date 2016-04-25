 ///
 /// @file    func.h
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-23 15:35:16
 ///
 
#include <iostream>
#include <pthread.h>
using namespace std;

class Condition;

class MutexLock{
	friend Condition;
	public:
		MutexLock();
		~MutexLock();
		void lock();
		void unlock();
	private:
		pthread_mutex_t _mutex;
};

class Condition{
	public:
		Condition();
		~Condition();
		void wait(MutexLock & Mlock);
		void notify();
		void notifyall();
	private:
		pthread_cond_t _cond;
};

 ///
 /// @file    mylog.h
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-23 14:32:30
 ///
 
#include <iostream>
#include <string>
#include <sstream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

class Mylog{
	public:
		Mylog();
		~Mylog();

		void warn(const char * msg);
		void warn();
		void error();
		void debug();
		void info();

	private:
		log4cpp::Category & _root;

};

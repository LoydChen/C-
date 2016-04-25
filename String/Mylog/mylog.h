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

using std::string;
using std::ostringstream;

class Mylog{
	public:
		static Mylog * getInstance();
		static void destory();
		void warn(const char * msg);
		void error(const char * msg);
		void debug(const char * msg);
		void info(const char * msg);

	private:
		log4cpp::Category & _root;
		Mylog();
		~Mylog();
		static Mylog * _pInstance;
};

inline string int2String(int num){
	ostringstream oss;
	oss << num;
	return oss.str();
}

#define postfix(msg)\
	string(msg).append("||").append(__FILE__)\
	.append(":").append(__func__).append(":")\
	.append(int2String(__LINE__)).append("||").c_str()

void logWarn(const char * msg);
void logInfo(const char * msg);
void logError(const char * msg);
void logDebug(const char * msg);

#define LogWarn(msg) logWarn(postfix(msg))
#define LogInfo(msg) logInfo(postfix(msg))
#define LogErrir(msg) logError(postfix(msg))
#define LogDebug(msg) logDebug(postfix(msg))

 
 /// @file    mylog.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-25 14:39:29
 ///
 
#ifndef __MY_LOG_H_
#define __MY_LOG_H_

#include <string>
#include <sstream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>


using std::string;
using std::ostringstream;

class Mylog
{
public:
	static Mylog * getInstance();
	static void destroy();
	void warn(const char * msg);
	void info(const char * msg);
	void error(const char * msg);
	void debug(const char * msg);

private:
	Mylog();
	~Mylog();
private:
	log4cpp::Category & _root;
	static Mylog * _pInstance;
};

inline string int2String(int num)
{
	ostringstream oss;
	oss << num;
	return oss.str();
}


#define  postfix(msg) \
	string(msg).append("||").append(__FILE__)\
	.append(":").append(__func__).append(":")\
	.append(int2String(__LINE__)).append("||").c_str()

void logWarn(const char * msg);
void logInfo(const char * msg);
void logError(const char * msg);
void logDebug(const char * msg);

#define LogWarn(msg) logWarn(postfix(msg))
#define LogInfo(msg) logInfo(postfix(msg))
#define LogError(msg) logError(postfix(msg))
#define LogDebug(msg) logDebug(postfix(msg))

#endif

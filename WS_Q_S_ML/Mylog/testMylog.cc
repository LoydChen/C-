 ///
 /// @file    testMylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-25 14:58:17
 ///
 
#include "mylog.h"

#include <iostream>


int main(void)
{
#if 0
	Mylog * plog = Mylog::getInstance();
	//plog->warn("warn message");
	plog->warn(postfix("warn message"));
	plog->info(postfix("inf message"));
	plog->error(postfix("error message"));
	plog->debug(postfix("debug message"));
#endif

	LogWarn("warn message");
	LogInfo("info message");
	LogError("error message");
	LogDebug("debug message");
	//logWarn(postfix("warn message"));
	//logInfo(postfix("info message"));
	//logError(postfix("error message"));
	//logDebug(postfix("debug message"));
	

	return 0;
}

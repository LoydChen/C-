 ///
 /// @file    log4cpp_appender.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-22 19:00:15
 ///
 
#include <iostream>
#include <string>
#include <sstream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

int main(){
	//初始化两个Layout并指定格式
	log4cpp::PatternLayout * ptnLayout1 = new log4cpp::PatternLayout();
	ptnLayout1->setConversionPattern("%d: %p %c %x: %m%n");
	log4cpp::PatternLayout * ptnLayout2 = new log4cpp::PatternLayout();
	ptnLayout2->setConversionPattern("%d: %p %c %x: %m%n");
	
	//初始化OstreamAppender1,将Latout1绑定
	log4cpp::OstreamAppender * ostreamAppender1 = new log4cpp::OstreamAppender("ostream1",&cout);
	ostreamAppender1->setLayout(ptnLayout1);


	//初始化OstreamAppender2,将Latout2绑定
	log4cpp::OstreamAppender * ostreamAppender2 = new log4cpp::OstreamAppender("ostream2",&cout);
	ostreamAppender2->setLayout(ptnLayout2);
	
	//初始化Category
	log4cpp::Category & root = log4cpp::Category::getRoot();
	
	//用getInstance方法得到子Category
	log4cpp::Category & sub1 = root.getInstance("sub1");
	sub1.addAppender(ostreamAppender1);
	sub1.setPriority(log4cpp::Priority::DEBUG);
	sub1.error("sub1 error");

	//用getInstance方法得到子Category
	log4cpp::Category & sub2 = root.getInstance("sub2");
	sub2.addAppender(ostreamAppender2);
	sub2.setPriority(101);
	sub2.warn("sub2 warning");
	sub2.fatal("sub2 fatal");
	sub2.alert("sub2 alert");
	sub2.crit("sub2 crit");

	//关闭Category
	log4cpp::Category::shutdown();
	return 0;
}

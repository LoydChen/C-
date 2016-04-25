 ///
 /// @file    171.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-21 22:07:40
 ///
 
#include <iostream>
#include <string>
using namespace std;
class Solution {
	public:
	    int titleToNumber(string s) {
	        int sum = 0;
	        for(int i=0;i<s.size();i++){
		            sum += s[i];
	        }
      return sum;	
	}
};

int main(){
	Solution q1;
	cout << q1.titleToNumber("AAB") << endl;
}

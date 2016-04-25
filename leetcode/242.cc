 ///
 /// @file    242.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-21 17:17:37
 ///
 
#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	bool isAnagram(string s,string t){
		if(s.size() == t.size()){
			int i;
			for(i=0;i< s.size();i++){
				int pos = t.find(s[i]);
				if(pos >= t.size()){
					return false;
					break;
				}else{
					t.erase(pos,1);
				}
			}
			if(t.size() == 0){
				return true;
			}
		}
		return false;
	}
	bool isAnagram_b(string s,string t){
		if(s.size() != t.size())
			return false;
		int a[26] = {0};
		for(int i=0;i<s.size();i++){
			a[s[i]%26]++;
			a[t[i]%26]--;
		}
		for(int i=0;i<26;i++){
			if(a[i]!=0)	return false;
		}
		return true;
	}
};

int main(){
	Solution q1;
	cout << "result:" << q1.isAnagram_b("swqszqwe","qwssewzq") << endl;

	return 0;
}





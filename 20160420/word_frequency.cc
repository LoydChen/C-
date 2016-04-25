 ///
 /// @file    word_frequency.cc
 /// @author  loydchen(loydchen729@gmail.com)
 /// @date    2016-04-20 22:01:19
 ///
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

class WORD{

	public:
		WORD()
		: _times(1)
		, _word("")
		{
		}
	int _times;
	string _word;
};

class WordStatic{
	public:
		void read_file(char* filename);
		void print();
	private:
		WORD Wword;
		vector<WORD> vec;
};



void WordStatic::read_file(char * filename){
	cout << "Please wait!" << endl;
	ifstream ifs(filename);
	if(!ifs.good()){
		cout << "open file error" << endl;
		exit;
	}
	string str;
	string word;
	int i,j;
	while(getline(ifs,str)){
	//for(i=0;i<10;i++){
		//getline(ifs,str);
		//cout << str << endl;
		istringstream iss(str);
		while(iss >> word){
			//WORD Wword;
			Wword._word = word;
			if(vec.size() == 0){
				vec.push_back(Wword);
			}else{
				for(j=0;j<vec.size();j++){
					if(vec[j]._word == word){
						vec[j]._times++;
						break;
					}
				}
				if(j == vec.size()){
					vec.push_back(Wword);
				}
			}
		}
	}

}

void WordStatic::print(){
	for(int i=0;i<vec.size();i++){
		cout << vec[i]._word << " " << vec[i]._times << endl;
	}	
}

int main(){
	WordStatic Bible;
	cout << "please input filemane" << endl;
	char file_name[30];
	cin >> file_name;
	Bible.read_file(file_name);
	Bible.print();
	return 0;
}

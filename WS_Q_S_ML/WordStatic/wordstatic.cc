 ///
 /// @file    wordstatic.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-04-25 10:06:55
 ///
 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

struct Record
{
	string _word;
	int _freq;
};


class WordStatic
{
public:
	WordStatic()
	{
		_vecRecord.reserve(1000);
	}

	void readFile(const string & filename);
	void writeFile(const string & filename);
private:
	void addRecord(const string & word);
private:
	vector<Record> _vecRecord;
};

void WordStatic::readFile(const string & filename)
{
	ifstream ifs(filename.c_str());
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return ;
	}

	string line;
	string word;
	while(getline(ifs, line))
	{
		istringstream iss(line);
		iss >> word;
		addRecord(word);
	}
	ifs.close();
}

void WordStatic::writeFile(const string & filename)
{
	ofstream ofs(filename.c_str());
	if(!ofs.good())
	{
		cout << "ofstream open error!" << endl;
		return;
	}

	vector<Record>::iterator it = _vecRecord.begin();
	for(; it != _vecRecord.end(); ++it)
	{
		ofs << _vecRecord._word << " " << 
			<< _vecRecord._freq << "\n";
	}
	ofs.close();
}


void WordStatic::addRecord(const string & word)
{
	int size = _vecRecord.size();
	int idx;
	for(idx = 0; idx != size; ++idx)
	{
		if(_vecRecord[idx]._word == word)
		{
			++(_vecRecord[idx]._freq);
			break;
		}
	}
	if(idx == size)
	{//在数组里面没有这个单词
		Record record;
		record._word = word;
		record._freq = 1;
		_vecRecord.push_back(record);
	}
}


int main(void)
{
	WordStatic ws;
	ws.readFile("The_Holy_Bible.txt");
	ws.writeFile("dict.txt");
	return 0;
}


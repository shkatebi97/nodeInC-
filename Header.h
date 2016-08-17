#include<Windows.h>
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

class args
{
	//vector<int> numbers;
	vector<string> strings;
	//vector<char> order;
public:
	args();
	void add(string);
	string * get(int & n);
};

//****************************************************************

class node
{
	string path;
public:
	node(string);
	void run(string ,args);
	char* stringToChar(string);
};
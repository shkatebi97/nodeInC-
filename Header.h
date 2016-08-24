#include<Windows.h>
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

class args
{
	vector<string> dependenci;
	vector<string> strings;
	void evolve(string);
	//vector<char> order;
public:
	args();
	void add(string);
	void add_D(string);
	string * get(int & n);
	string * get_D(int & n);
	friend class node;
};

//****************************************************************

class node
{
	string path;
public:
	//node(string);
	node();
	node(string _path);
	void run(string ,args);
	char* stringToChar(string);
};
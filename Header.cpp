#include "Header.h"

node::node(string _path)
{
	path = _path;
}

void node::run(string _function, args arg)
{
	string func;
	fstream fs;
	string newPath = path;
	newPath += "/temp.js";
	fs.open(newPath, ios::in || ios::out || ios::trunc);
	fs << _function;
	fs.close();
	func = "node ";
	func += newPath;
	int n;
	string* temp = arg.get(n);
	if (temp == nullptr)
	{
		system(stringToChar(func));
		return;
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			func += " ";
			func += temp[j];
		}
		system(stringToChar(func));
		return;
	}
}

char * node::stringToChar(string str)
{
	int len = str.length();
	char * a = new char[len];
	for (int i = 0; i != len; i++)
	{
		a[i] = str[i];
	}
	return a;
}

//********************************************************************

args::args(){}

void args::add(string argToAdd)
{
	strings.push_back(argToAdd);
}

string * args::get(int &numberOfStrings)
{
	string * temp;
	int n = strings.size();
	if (!n)
	{
		return nullptr;
	}
	temp = new string[n];
	int i = 0;
	for (vector<string>::iterator a = strings.begin(); a != strings.end(); a++, i++)
	{
		temp[i] = *(a);
	}
	numberOfStrings = i+1;
	return temp;
}



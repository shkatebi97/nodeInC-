#include "Header.h"

node::node(string _path)
{
	path = _path;
}

void node::run(string _function, args arg)
{
	//cout << "run runed";
	string func;
	arg.evolve(_function);
	fstream fs;
	string newPath = path;
	string depend = "npm install ";
	int NOD;
	string * tmp = arg.get_D(NOD);
	//cout << "\nafter get";
	if (tmp == nullptr)
	{
		depend.clear();
	}
	else
	{
		//cout << "\nafter first if\n";
		for (int j = 0; j < NOD; j++)
		{
			//cout << NOD;
			//cout << tmp[j];
			depend += tmp[j];
			depend += " ";
		}
		depend += "-global";
	}
	//cout << "after add npm";
	newPath += "/temp.js";
	//string t = "cd ";
	//t += path;
	fs.open(newPath, ios::in || ios::out || ios::trunc);
	fs << _function;
	fs.close();
	func = "node ";
	func += newPath;
	int n;
	string* temp = arg.get(n);
	if (temp == nullptr)
	{
		//cout << depend;
		//system(stringToChar(t));
		system(stringToChar(depend));
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
		//system(stringToChar(t));
		system(stringToChar(depend));
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
	a[len] = NULL;
	return a;
}

//********************************************************************

void args::evolve(string func)
{
	int n = func.length();
	char end[] = "require";
	for (int  i = 0 , j = 0 ; i < n ; i++)
	{
		if (func[i] == end[j])
		{
			if ( j == 6 )
			{
				int k = i;
				while ( func[k] != '\'' && func[k] != '"' )
				{
					k++;
					//cout << func[k] <<" in while"<<endl;
				}
				string t = "";
				k++;
				for ( k ; func[k] != '\'' && func[k] != '"' ; k++)
				{
					t += func[k];
					//cout << func[k] << " in for" << endl;
				}
				bool ch = 1;
				for (vector<string>::iterator z = dependenci.begin() ; z != dependenci.end() ; z++ )
				{
					if (*(z) == t)
					{
						ch = 0;
						break;
					}
				}
				//cout << t;
				ch ? ( dependenci.push_back(t) ) : ch = 1;
				j = 0;
				i = k;
			}
			else
			{
				j++;
			}
		}
		else
		{
			j = 0;
		}
	}
}

args::args(){}

void args::add(string argToAdd)
{
	strings.push_back(argToAdd);
}

void args::add_D(string depend)
{
	dependenci.push_back(depend);
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
	numberOfStrings = i;
	return temp;
}

string * args::get_D(int & numberOfStrings)
{
	string * temp;
	int n = dependenci.size();
	if (!n)
	{
		return nullptr;
	}
	temp = new string[n];
	int i = 0;
	for (vector<string>::iterator a = dependenci.begin(); a != dependenci.end(); a++, i++)
	{
		temp[i] = *(a);
	}
	numberOfStrings = i;
	return temp;
}



/*
Student Name: Joseph Nelson
Student NetID: jgn86
Compiler Used: Visual Studio
Program Description:
Parses user input or a file and then uses it to configue the binary search tree.
*/




#include "BST.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;


bool getWord(stringstream& ss, string& word)
{
	while (getline(ss, word, ' '))
	{
		if (word != "") return true;
	}
	return false;
}

bool getInt(stringstream& ss, int& val)
{
	string word;
	while (getline(ss, word, ' '))
	{
		if (word == "") continue;
		try {
			val = stoi(word);
		}
		catch (...)
		{
			return false;
		}
		return true;
	}
	return false;
}

bool getDouble(stringstream& ss, double& val)
{
	string word;
	while (getline(ss, word, ' '))
	{
		if (word == "") continue;
		try {
			val = stod(word);
		}
		catch (...)
		{
			return false;
		}
		return true;
	}
	return false;
}

void processInput(istream& is, BST& x, Node* node, bool silent = false)
{

	string cmd = "", arg1 = "", arg2 = "", arg3 = "", p1 = "", p2 = "";
	int num;
	int prior = 0;
	ifstream fin;
	ofstream fout;
	bool flag;

	while (1)
	{
		flag = false;
		if (!silent) cout << ">>";
		if (!getline(is, cmd)) return;
		stringstream cmd_to_proc(cmd);
		getWord(cmd_to_proc, cmd);
		if (cmd == "exit")
		{
			exit(0);
		}
		if (cmd == "display")
		{
			if (getWord(cmd_to_proc, arg1))
			{
				if (arg1 == "in order")
				{
					x.inOrder(cout);
					cout << endl;
				}
				if (arg1 == "pre order")
				{
					x.preOrder(cout);
					cout << endl;
				}
				if (arg1 == "post order")
				{
					x.postOrder(cout);
					cout << endl;
				}
			}
			continue;
		}


		if (cmd == "load")
		{
			if (getWord(cmd_to_proc, arg1))
			{
				fin.open(arg1);
				if (fin.is_open())
				{
					processInput(fin, x, node, true);
				}
				else
				{
					cout << "failed to open file!" << endl;
				}
				fin.close();
			}
			continue;
		}
		if (cmd == "search")
		{
			if (!getInt(cmd_to_proc, num)) continue;

			if (x.search(num))
			{
				cout << "Found" << arg1;
			}
			else
			{
				cout << "Does not exist" << endl;
			}
		}
		if (cmd == "remove")
		{
			if (!getInt(cmd_to_proc, num)) continue;
			if (x.remove(num))
			{
				cout << "Removed " << arg1 << endl;
			}
			else
			{
				cout << "Does not exist" << endl;
			}
			continue;
		}

		if (cmd == "insert")
		{

			if (!getInt(cmd_to_proc, num))
			{
				if (x.insert(num))
				{
					cout << "Vertex " << arg1 << " added to graph" << endl;
				}
				else
				{
					cout << "That vertex already exists" << endl;
				}
				continue;


			}
		}
	}
}

		


int main()
{

	BST tree;
	Node* node;

	processInput(std::cin, tree, node);

	return 0;
}
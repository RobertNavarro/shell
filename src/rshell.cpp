
#include <iostream>
#include <string>
#include <unistd.h>

#include "../header/parser.h"
#include "../header/separate.h"

#include "../header/Token.h"
#include "../header/Tokenizer.h"
#include "../header/execute.h"
#include "../header/Tree.h"
#include "../header/rshellHelper.h"
#include <stack>
#include <queue> 
#include <vector>

using namespace std;

string printCommandPrompt();
void printVector(vector<string> vec);
void printtokens(vector<Token*> &vec);


int main()
{
				/*
				string userInput;
				cout << printCommandPrompt();
				getline(cin,userInput);

                vector<string> delimitedInput = parser(userInput);
                vector<string> separatedInput = separate(delimitedInput);
				//vector<Token*> tokendInput = tokenize(separate);
				printVector(delimitedInput);
				cout << "------END OF DELIMITED INPUT------" << endl;       //testing purposes
				printVector(separatedInput);
				 cout << "------END OF SEPARATED INPUT------" << endl;
                //printtokens(tokendInput);
				
				//cout << "Printing the result of the second mirror" << endl;
				//printVector(secondMirror);
				//cout << "-----End of the second mirror output-----" << endl;
				*/
				
	
	vector<Token*> tokendInput;
	while(true)
	{
		string userInput;
		cout << printCommandPrompt();
		getline(cin,userInput);
		int spaceCount = count(userInput.begin(), userInput.end(), ' ');
		if(userInput.size() !=0 && spaceCount != userInput.size())//stops user from entering nothing but newlines and entering in all spaces
		{
			vector<string> delimitedInput = parser(userInput);
			vector<string> separatedInput = separate(delimitedInput);
			
			
			vector<string> mirroredShunting = produceShunting(separatedInput);
			
			tokendInput = tokenize(mirroredShunting);
			queue<Token*> tokenQueue;
			for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
			{
				tokenQueue.push(tokendInput.at(i));
			}


			Tree* executiontree = new Tree();
			Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());
			
			executiontree->treeTraverse(executiontree->getRoot());
			
			for(int i = 0; i < tokendInput.size(); ++i)
			{
				delete tokendInput.at(i);
			}
			tokendInput.clear();
		}
	}
	
	return 0;

}


string printCommandPrompt()
{
	char* getlogin(void);
	char buf[FILENAME_MAX];
	char* directory = getcwd(buf, FILENAME_MAX);
	string stringDirectory(directory);		 
	string currentFolder = stringDirectory.substr(stringDirectory.find_last_of("/")+1, stringDirectory.size()-1);
	return "[" + string(getlogin()) + " " + currentFolder + "]$ ";
}
void printVector(vector<string> vec)
{
	for(unsigned int i = 0 ; i< vec.size(); i++)
	{
		cout << "[" + vec.at(i) + "]" << endl;
	}
}


void printtokens(vector<Token*> &vec)
{
	for (unsigned i = 0; i < vec.size(); i++)
	{
		if (vec.at(i)->isexe())//is pointer now
		{
			cout << "exe: " << vec.at(i)->getWholeToken() << endl;
			
		}
		else
		{
			cout << "conn: "<< vec.at(i)->getWholeToken() << endl;
		}
		
		if( i < vec.size() -1)
		{
			cout << ", ";
		}
	}
	cout << endl;
}
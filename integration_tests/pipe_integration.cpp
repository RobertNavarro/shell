#include "gtest/gtest.h"
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "../header/Tree.h"
#include "../header/parser.h"
#include "../header/separate.h"
#include "../header/rshellHelper.h"
#include <stack>
#include <queue> 
#include <vector>
#include <iostream>
#include <fstream>

TEST(Pipe_Integration, combinationtest) 
{

	vector<Token*> tokendInput;
   	string fakeUserInput = "cat testingInput | sort >> tempTestOuput && echo hi >> tempTestOuput";
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	vector<string> mirroredShunting = produceShunting(separatedInput);
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile << "D\nC\nB\nA";
	testFile.close();

	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());
	executiontree->treeTraverse(executiontree->getRoot());

	ifstream tempOutputFile("tempTestOuput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOuput";
	remove(outputFileToDelete);
	char inputFileToDelete[] = "testingInput";
	remove(inputFileToDelete);
	
	EXPECT_EQ(extractedOutput.at(0), "A");
	EXPECT_EQ(extractedOutput.at(1), "B");
	EXPECT_EQ(extractedOutput.at(2), "C");
	EXPECT_EQ(extractedOutput.at(3), "D");
	EXPECT_EQ(extractedOutput.at(4), "hi");
	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}

TEST(Pipe_Integration, combinationtestOR) 
{

	vector<Token*> tokendInput;
   	string fakeUserInput = "cat testingInput | sort >> tempTestOuput || echo hi >> tempTestOuput";
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	vector<string> mirroredShunting = produceShunting(separatedInput);
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile << "D\nC\nB\nA";
	testFile.close();

	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());
	executiontree->treeTraverse(executiontree->getRoot());

	ifstream tempOutputFile("tempTestOuput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOuput";
	remove(outputFileToDelete);
	char inputFileToDelete[] = "testingInput";
	remove(inputFileToDelete);
	
	EXPECT_EQ(extractedOutput.at(0), "A");
	EXPECT_EQ(extractedOutput.at(1), "B");
	EXPECT_EQ(extractedOutput.at(2), "C");
	EXPECT_EQ(extractedOutput.at(3), "D");
	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}

TEST(Pipe_Integration, orWithFakeFile) 
{

	vector<Token*> tokendInput;
   	string fakeUserInput = "cat fakeFile | sort >> tempTestOuput || echo hi >> tempTestOuput";
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	vector<string> mirroredShunting = produceShunting(separatedInput);
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile << "D\nC\nB\nA";
	testFile.close();

	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());
	executiontree->treeTraverse(executiontree->getRoot());

	ifstream tempOutputFile("tempTestOuput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOuput";
	remove(outputFileToDelete);
	char inputFileToDelete[] = "testingInput";
	remove(inputFileToDelete);
	
	if(extractedOutput.size()!=0)
	{
		EXPECT_EQ(extractedOutput.at(0), "A");
		EXPECT_EQ(extractedOutput.at(1), "B");
		EXPECT_EQ(extractedOutput.at(2), "C");
		EXPECT_EQ(extractedOutput.at(3), "D");
	}
	
	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}


TEST(Pipe_Integration, andWithFakeFile) 
{

	vector<Token*> tokendInput;
   	string fakeUserInput = "cat fakeFile | sort >> tempTestOuput && echo hi >> tempTestOuput";
    vector<string> parsedUserInput = parser(fakeUserInput);
	vector<string> separatedInput = separate(parsedUserInput);
	vector<string> mirroredShunting = produceShunting(separatedInput);
	tokendInput = tokenize(mirroredShunting);
	queue<Token*> tokenQueue;
	for(int i = 0; i < tokendInput.size(); ++i) //puts the tokenized input into a queue
	{
		tokenQueue.push(tokendInput.at(i));
	}
	vector<string> extractedOutput;
	
	ofstream testFile("testingInput");
	testFile << "D\nC\nB\nA";
	testFile.close();

	Tree* executiontree = new Tree();
	Node* root = executiontree->buildTree(tokenQueue, tokenQueue.size());
	executiontree->treeTraverse(executiontree->getRoot());

	ifstream tempOutputFile("tempTestOuput");
	string currentLine;
	while (getline (tempOutputFile, currentLine)) 
	{
		extractedOutput.push_back(currentLine);
	}
	
	char outputFileToDelete[] = "tempTestOuput";
	remove(outputFileToDelete);
	char inputFileToDelete[] = "testingInput";
	remove(inputFileToDelete);
	
	if(extractedOutput.size()!=0)
	{
		EXPECT_EQ(extractedOutput.at(0), "hi");
	}
	
	for(int i = 0; i < tokendInput.size(); ++i)
	{
		delete tokendInput.at(i);
	}
	tokendInput.clear();
}
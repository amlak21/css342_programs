#ifndef BANKER_H_
#define BANKER_H
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include"BSTree.h"
#include"transaction.h"
using namespace std;

class Banker
{
public:
	Banker();
	
	bool ReadTransactions(string file_name);
	void ProcessTransactions();
	void Display();

private:
	queue<Transaction> transaction_list_;
	BSTree account_list_;
};
#endif
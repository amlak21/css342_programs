#ifndef FUND_H_
#define FUND_H_
#include "transaction.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Fund
{
public:
	Fund();

	bool AddToFund(int amount);
	bool SubtractFromFund(int amount);
	bool CheckFundBalance(int amount);
	bool RecordFundTransaction(Transaction tra);
	void PrintFundHistory();
	bool PrintHistory();
	void set_fund_name(string fund_name);
	int balance() const;
	string fund_name() const;

private:
	string fund_name_;
	int balance_;
	vector<Transaction> history_;
};
#endif
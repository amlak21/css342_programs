#ifndef ACCOUNT_H_
#define ACCOUNT_h_
#include "transaction.h"
#include "fund.h"
#include <iostream>
#include <string>
using namespace std;

const int kClientFunds = 8; //number of funds in a given account
const int kMoneyMarket = 0;
const int kPrimeMoneyMarket = 1;
const int kLongTermBond = 2;
const int kShortTermBond = 3;

class Account
{
	friend ostream& operator << (ostream& stream, Account& acc);

public:
	Account();
	Account(string first_name, string last_name, int acc_id);


	void AddToAccount(int fund_num, int amount);
	bool SubstractAccountFund(int fund_num, int amount, Transaction tra);
	void RecordAccountTransaction(Transaction tra, int fund_num);
	void WithdrawFromLinkedAccFund(int primary_fund, int secondary_fund, int amount);
	void PrintAccountHistory();
	void PrintAccountFundHistory(int fund_num);
	void PrintError(int amount, string first_name, string last_name, int fund_num);
	string get_fund_name(int fund_num);
	int get_balance(int fund_num)const;

	int account_id() const;
	string first_name() const;
	string last_name()const;
	int get_fund_id()const;
	void set_fund_id(int fund_num);

private:
	string first_name_, last_name_;
	int account_id_;
	int fund_id_;
	Fund fund_arr_[kClientFunds];
};
#endif


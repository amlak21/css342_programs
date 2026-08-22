#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include <iostream>
#include <string>
using namespace std;

class Transaction
{
	friend ostream& operator<<(ostream& stream, const Transaction& tra);
public:
	//constructors
	Transaction();
	Transaction(char tra_type, int acc_id);
	Transaction(char tra_type, int acc_id, int fund_id);
	Transaction(char tra_type, int acc_id, int fund_id, int amount);
	Transaction(char tra_type, int acc_id, string first_name, string last_name);
	Transaction(char tra_type, int acc_id, int fund_id, int amount, string fail);
	Transaction(char tra_type, int acc_id, int fund_id, int transfer_acc_id, int transfer_fund_id, int amount);
	Transaction(char tra_type, int acc_id, int fund_id, int transfer_acc_id, int transfer_fund_id, int amount, string fail);
	
	//action
	bool IsFailed();

	//getters
	char transaction_type() const;
	string first_name() const;
	string last_name() const;
	string fail()const;
	int account_id() const;
	int fund_id() const;
	int transfer_account_id() const;
	int transfer_fund_id() const;
	int amount() const;


private:
	char transaction_type_;
	string first_name_, last_name_, fail_;
	int account_id_, fund_id_, transfer_account_id_, transfer_fund_id_, amount_;
};
#endif

#include "transaction.h"
Transaction::Transaction():transaction_type_(' '), first_name_(" "), last_name_(" "), fail_(""), account_id_(0), 
							fund_id_(0), transfer_account_id_(0), transfer_fund_id_(0), amount_(0)
{

}

Transaction::Transaction(char type, int acc_id)
{
	first_name_ = "";
	last_name_ = "";
	fail_ = "";
	fund_id_ = 0;
	transfer_account_id_ = 0; 
	transfer_fund_id_ = 0; 
	amount_ = 0;
	transaction_type_ = type;
	account_id_ = acc_id;
}

Transaction::Transaction(char type, int acc_id, int fund_id)
{
	first_name_ = "";
	last_name_ = "";
	fail_ = "";
	transfer_account_id_ = 0;
	transfer_fund_id_ = 0;
	amount_ = 0;
	transaction_type_ = type;
	account_id_ = acc_id;
	fund_id_ = fund_id;
}

Transaction::Transaction(char type, int acc_id, int fund_id, int amount)	
{
	first_name_ = "";
	last_name_ = "";
	fail_ = "";
	transfer_account_id_ = 0;
	transfer_fund_id_ = 0;
	transaction_type_ = type;
	account_id_ = acc_id;
	fund_id_ = fund_id;
	amount_ = amount;
}

Transaction::Transaction(char type, int acc_id, string first_name, string last_name)
{
	fund_id_ = 0;
	amount_ = 0;
	fail_ = "";
	transfer_account_id_ = 0;
	transfer_fund_id_ = 0;
	transaction_type_ = type;
	first_name_ = first_name;
	last_name_ = last_name;
	account_id_ = acc_id;
}

Transaction::Transaction(char type, int acc_id, int fund_num, int amount, string fail)
{
	first_name_ = "";
	last_name_ = "";
	transfer_account_id_ = 0;
	transfer_fund_id_ = 0;
	transaction_type_ = type;
	account_id_ = acc_id;
	fund_id_ = fund_num;
	fail_ = fail;
	amount_ = amount;
}

Transaction::Transaction(char type, int acc_id, int fund_num, int transfer_acc_id, int transfer_fund_id, int amount)
{
	first_name_ = " ";
	last_name_ = " ";
	fail_ = "";
	transaction_type_ = type;
	account_id_ = acc_id;
	fund_id_ = fund_num;
	amount_ = amount;
	transfer_account_id_ = transfer_acc_id;
	transfer_fund_id_ = transfer_fund_id;
}

Transaction::Transaction(char type, int acc_id, int fund_num, int transfer_acc_id, int transfer_fund_id, int amount, string fail)
{
	first_name_ = "";
	last_name_ = "";
	transaction_type_ = type;
	account_id_ = acc_id;
	fund_id_ = fund_num;
	amount_ = amount;
	transfer_account_id_ = transfer_acc_id;
	transfer_fund_id_ = transfer_fund_id;
	fail_ = fail;
}

char Transaction::transaction_type() const
{
	return transaction_type_;
}

string Transaction::first_name() const
{
	return first_name_;
}

string Transaction::last_name() const
{
	return last_name_;
}

string Transaction::fail()const
{
	return fail_;
}

int Transaction::account_id() const
{
	return account_id_;
}

int Transaction::amount() const
{
	return amount_;
}

int Transaction::fund_id() const
{
	return fund_id_;
}

int Transaction::transfer_account_id() const
{
	return transfer_account_id_;
}

int Transaction::transfer_fund_id() const
{
	return transfer_fund_id_;
}

bool Transaction::IsFailed()
{
	if (fail_.empty())
	{
		return true; 
	}
	return false;
}

ostream& operator<<(ostream& stream, const Transaction& tra)
{
	if (tra.fail_.empty()) 
	{
		if (tra.transaction_type() == 'D' || tra.transaction_type() == 'd' || tra.transaction_type() == 'W' || tra.transaction_type() == 'w')
		{
			stream << " " << tra.transaction_type() << " " << tra.account_id()<<" " << tra.fund_id() << " " << tra.amount() << endl;
		}
		else if (tra.transaction_type() == 'T' || tra.transaction_type() == 't')
		{
			stream << " " << tra.transaction_type() << " " << tra.account_id()<<" " << tra.fund_id() << " " << tra.transfer_account_id() <<" " << tra.transfer_fund_id()<<" " << tra.amount() << endl;
		}
	}

	else
	{
		if (tra.transaction_type() == 'D' || tra.transaction_type() == 'd' || tra.transaction_type() == 'W' || tra.transaction_type() == 'w')
		{
			stream << " " << tra.transaction_type() << " " << tra.account_id()<<" " << tra.fund_id() << " " << tra.amount() << " (FAILED)" << endl;
		}
		else if (tra.transaction_type() == 'T' || tra.transaction_type() == 't')
		{
			stream << " " << tra.transaction_type() << " " << tra.account_id()<<" " << tra.fund_id() << " " << tra.transfer_account_id() <<" " << tra.transfer_fund_id() << tra.amount() << "(FAILED)" << endl;
		}
	}
	return stream;

}

#include "fund.h"
Fund::Fund(): fund_name_(" "),balance_(0)
{
	
}

void Fund::set_fund_name(string fund_name)
{
	fund_name_ = fund_name;
}

int Fund::balance() const
{
	return balance_;
}

string Fund::fund_name() const
{
	return fund_name_;
}

bool Fund::AddToFund(int amount)
{
	balance_ += amount;
	return true;
}

bool Fund::SubtractFromFund(int amount)
{
	balance_ -= amount;
	return true;
}

bool Fund::CheckFundBalance(int amount)
{
	if (balance_ >= amount)
	{
		return true;
	}
	return false;
}


bool Fund::RecordFundTransaction(Transaction tra)
{
	history_.push_back(tra);
	return true;
}

bool Fund::PrintHistory() 
{
	if (history_.size() == 0)
	{
		return false;
	}
	else
	{
		cout << fund_name_ << ": $" << balance_ << endl;
		for (int i = 0; i < history_.size(); i++)
		{
			cout << " " << history_[i];
		}
		return true;
	}
}

void Fund::PrintFundHistory()
{
	for (int i = 0; i < history_.size(); i++)
	{
		cout << " " << history_[i];
	}
}

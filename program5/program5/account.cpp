#include "account.h"
Account::Account():first_name_(" "), last_name_(" "), account_id_(0)
{
}

Account::Account(string first_name, string last_name, int acc_id)
{
	first_name_ = first_name;
	last_name_ = last_name;
	account_id_ = acc_id;
	
	string fund_set[] = { "Money Market", "Prime Money Market","Long-Term Bond", "Short-Term Bond","500 Index Fund", "Capital Value Fund","Growth Equity Fund", "Growth Index Fund"};
	for (int i = 0; i < 8; i++) 
	{
		fund_arr_[i].set_fund_name(fund_set[i]);
	}
}

int Account::get_fund_id()const
{
	return fund_id_;
}

int Account::account_id() const
{
	return account_id_;
}

void Account::set_fund_id(int fund_num)
{
	fund_id_ = fund_num;
}

int Account::get_balance(int fund_num)const
{
	return fund_arr_[fund_num].balance();
}

string Account::get_fund_name(int fund_num)
{
	return fund_arr_[fund_num].fund_name();
}

string Account::first_name() const
{
	return first_name_;
}

string Account::last_name() const
{
	return last_name_;
}

void Account::AddToAccount(int fund_num, int amount)
{
	fund_arr_[fund_num].AddToFund(amount);
}

//to withdraw from linked funds of an account  
void Account::WithdrawFromLinkedAccFund(int primary_fund, int secondary_fund, int amount)
{
	//check for enough fund
	if (((fund_arr_[primary_fund].balance() + fund_arr_[secondary_fund].balance()) >= amount))
	{
		int avalaible_balance = fund_arr_[primary_fund].balance();

		fund_arr_[primary_fund].SubtractFromFund(avalaible_balance);

		//create transaction
		Transaction input_history('W', account_id(), primary_fund, avalaible_balance);

		//record transaction history
		fund_arr_[primary_fund].RecordFundTransaction(input_history);

		amount = amount - avalaible_balance;

		fund_arr_[secondary_fund].SubtractFromFund(amount); 
		Transaction input_history2('W', account_id(), secondary_fund, amount);
		fund_arr_[secondary_fund].RecordFundTransaction(input_history2);
	}
	else
	{
		int avalaible_balance = fund_arr_[primary_fund].balance();
		if (avalaible_balance > amount)
		{
			fund_arr_[primary_fund].SubtractFromFund(avalaible_balance);
			Transaction input_history('W', account_id(), primary_fund, avalaible_balance);
			fund_arr_[primary_fund].RecordFundTransaction(input_history);
			amount = amount - avalaible_balance;
		}

		if (fund_arr_[secondary_fund].CheckFundBalance(amount))
		{
			fund_arr_[secondary_fund].SubtractFromFund(amount);
			Transaction input_history('W', account_id(), secondary_fund, amount);
			fund_arr_[secondary_fund].RecordFundTransaction(input_history);
		}
		else
		{
			cerr << "ERROR: Not Enough Funds to withdraw " << amount << " " << "from "<< last_name()<<" "<< first_name() << " " << get_fund_name(secondary_fund) << endl;
			Transaction input_history('W', account_id(), secondary_fund, amount, "Failed");
			fund_arr_[secondary_fund].RecordFundTransaction(input_history);
		}
	}
}

//to withdraw from funds which has special linkage
bool Account::SubstractAccountFund(int fund_num, int amount, Transaction tra)
{
	//special linked funds 0, 1, 2, and 3
	if (fund_num == kMoneyMarket || fund_num == kPrimeMoneyMarket || fund_num == kLongTermBond || fund_num == kShortTermBond)
	{

		//linked fund 0 and 1
		if (fund_num == kMoneyMarket || fund_num == kPrimeMoneyMarket)
		{
			if (fund_arr_[fund_num].CheckFundBalance(amount))
			{
				fund_arr_[fund_num].SubtractFromFund(amount);
				fund_arr_[fund_num].RecordFundTransaction(tra);
				return true;
			}
			else if (((fund_arr_[kMoneyMarket].balance() + fund_arr_[kPrimeMoneyMarket].balance()) >= amount))
			{
				if (fund_num == kMoneyMarket)
				{
					WithdrawFromLinkedAccFund(kMoneyMarket, kPrimeMoneyMarket, amount);
					return true; 
				}
				else
				{
					WithdrawFromLinkedAccFund(kPrimeMoneyMarket, kMoneyMarket, amount);
					return true; 
				}
			}
			else
			{
				PrintError(amount, first_name(), last_name(), fund_num);
				if (fund_num == kMoneyMarket)
				{
					WithdrawFromLinkedAccFund(kMoneyMarket, kPrimeMoneyMarket, amount);
					return true; 
				}
				else
				{
					WithdrawFromLinkedAccFund(kPrimeMoneyMarket, kMoneyMarket, amount);
					return true; 
				}
				return false;
			}
		}

		//Linked fund 2 and 3
		else if (fund_num == kLongTermBond || fund_num == kShortTermBond)
		{
			if (fund_arr_[fund_num].CheckFundBalance(amount))
			{
				fund_arr_[fund_num].SubtractFromFund(amount);
				fund_arr_[fund_num].RecordFundTransaction(tra);
				return true;
			}
			else if (((fund_arr_[kLongTermBond].balance() + fund_arr_[kShortTermBond].balance()) >= amount))
			{
				if (fund_num == kLongTermBond)
				{
					WithdrawFromLinkedAccFund(kLongTermBond, kShortTermBond, amount);
					return true;
				}
				else
				{
					WithdrawFromLinkedAccFund(kShortTermBond, kLongTermBond, amount);
					return true; 
				}
			}
			else
			{
				PrintError(amount, first_name(), last_name(), fund_num);
				if (fund_num == kLongTermBond)
				{
					WithdrawFromLinkedAccFund(kLongTermBond, kShortTermBond, amount);
					return true;
				}
				else
				{
					WithdrawFromLinkedAccFund(kShortTermBond, kLongTermBond, amount);
					return true; 
				}
				return false;
			}
		}
	}
	else
	{
		if (fund_arr_[fund_num].CheckFundBalance(amount))
		{
			fund_arr_[fund_num].SubtractFromFund(amount);
			fund_arr_[fund_num].RecordFundTransaction(tra);
			return true;
		}
		else
		{
			PrintError(amount, first_name(), last_name(), fund_num);
			return false;
		}
		return false;
	}
    return true;
}

//print error when the withdral is not sucessful
void Account::PrintError(int amount, string first_name, string last_name, int fund_num)
{
	cerr << "ERROR: Not Enough Funds to withdraw " << amount << " " << "from "<< last_name << " " << first_name << " " << get_fund_name(fund_num) << endl;
	Transaction input_history('W', account_id(), fund_num, amount, "Failed");
	fund_arr_[fund_num].RecordFundTransaction(input_history);
}

void Account::RecordAccountTransaction(Transaction tra, int fund_num)
{
	fund_arr_[fund_num].RecordFundTransaction(tra);
}

//print all fund transaction history of an account
void Account::PrintAccountHistory()
{
	cout << "Transaction History for " << last_name_ << " " << first_name_ << " " << "By Fund." << endl;
	for (int i = 0; i < 8; i++)
	{
		fund_arr_[i].PrintHistory();
	}
}

//print all transaction history of a fund
void Account::PrintAccountFundHistory(int fund_id)
{
	cout << "Transaction History for " << last_name_ << " " << first_name_ << " " << get_fund_name(fund_id) << ": $" << get_balance(fund_id) << endl;
	fund_arr_[fund_id].PrintFundHistory();
}

ostream& operator<<(ostream& stream, Account& acc)
{
	stream  << acc.last_name()<<" " << acc.first_name() << " " << "Account ID: " << acc.account_id() << endl;
	for (int i = 0; i < 8; i++) 
	{
		stream << " " << acc.get_fund_name(i) << " :$" << acc.get_balance(i) << endl;
	}
	return stream;
}

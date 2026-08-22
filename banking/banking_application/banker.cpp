#include "banker.h"
Banker::Banker()
{
}

//read transactions and create a queue
bool Banker::ReadTransactions(string file_name)
{
	ifstream in_file; 
	in_file.open(file_name);
	
	if (!in_file)
	{
		cout << "Unable to open file!" << endl;
	}
	string temp;
	while (!in_file.eof())
	{
		getline(in_file, temp);
		
		if (temp.empty())
		{
			break;
		}

		istringstream parseLine(temp); 
		char tra_type;
		string  first_name, last_name;
		int acc_id, fund_id, amount, trasnfer_acc_id, transfer_fund_id;

		parseLine >> tra_type;

		if (tra_type == 'O')
		{
			parseLine >>acc_id>>first_name >> last_name;
			Transaction input_queue(tra_type, acc_id, first_name, last_name);
			transaction_list_.push(input_queue);
		}

		else if (tra_type == 'W' || tra_type == 'D')
		{
			parseLine >> acc_id >> fund_id>> amount;
			if(fund_id < 0 || fund_id > 7) 
			{
				cerr << "ERROR: Account "<<acc_id<<" Fund ID: "<<fund_id<<" Not Valid" << endl;
				return false;
			}

			Transaction input_queue(tra_type, acc_id, fund_id, amount);
			transaction_list_.push(input_queue);
		}

		else if (tra_type == 'T')
		{
			parseLine >> acc_id >>fund_id>> trasnfer_acc_id>> transfer_fund_id>> amount ;
			if(fund_id < 0 || fund_id > 7 || transfer_fund_id < 0 || transfer_fund_id > 7)
			{
				cerr << "ERROR: Transfer Account Fund ID Not Valid" << endl;
				return false;
			}
			
			Transaction input_queue(tra_type, acc_id, fund_id, trasnfer_acc_id, transfer_fund_id, amount);
			transaction_list_.push(input_queue);
		}

		else if (tra_type == 'A')
		{
			parseLine >> acc_id;
			Transaction input_queue(tra_type, acc_id);
			transaction_list_.push(input_queue);
		}

		else if(tra_type == 'F')
		{
			parseLine >> acc_id>>fund_id; 
			if(fund_id < 0 || fund_id > 7) 
			{
				cerr << "ERROR: Account "<<acc_id<<" Fund ID: "<<fund_id<<" Not Valid" << endl;
				return false;
			}
			Transaction input_queue(tra_type, acc_id, fund_id);
			transaction_list_.push(input_queue);
		}

		else
		{
			cout << "Error! Unable to read transaction!" << endl;
		}
	}
	in_file.close();
	return false;
}

//excutes transactions from the queue
void Banker::ProcessTransactions() 
{
	while (!transaction_list_.empty())
	{
		Transaction tran = transaction_list_.front();

		//Open account
		if (tran.transaction_type() == 'O')
		{
			Account* acc = new Account(tran.first_name(), tran.last_name(), tran.account_id());
			account_list_.Insert(acc);
		}

		//Deposit asset into fund
		else if (tran.transaction_type() == 'D')
		{
			int acc_id = tran.account_id();
			int fund_id = tran.fund_id();
			int amount = tran.amount();
			Account* acc;
			if (account_list_.Retrieve(acc_id, acc))
			{
				acc->AddToAccount(fund_id, amount);
				acc->RecordAccountTransaction(tran, fund_id);
			}
			else if (!account_list_.Retrieve(acc_id, acc))
			{
				cerr << "ERROR: Account " << acc_id << " not found. Depositing refused." << endl;
			}
		}

		//Withdraw asset from fund
		else if (tran.transaction_type() == 'W')
		{
			int acc_id = tran.account_id();
			int fund_id = tran.fund_id();
			int amount = tran.amount();
			Account* acc;
			if (account_list_.Retrieve(acc_id, acc))
			{
				acc->SubstractAccountFund(fund_id, amount, tran);
			}
			else if (!account_list_.Retrieve(acc_id, acc))
			{
				cerr << "ERROR: Account " << acc_id << " not found. Withdrawal refused." << endl;
			}
		}

		//Transfer asset between funds
		else if (tran.transaction_type() == 'T')
		{
			int acc_id = tran.account_id();
			int transfer_acc_id = tran.transfer_account_id();
			int fund_id = tran.fund_id();
			int transfer_fund_id = tran.transfer_fund_id();
			int amount = tran.amount();
			Account* receiver_acc, * donor_acc;
			
			if (account_list_.Retrieve(acc_id, receiver_acc) && account_list_.Retrieve(transfer_acc_id, donor_acc))
			{
				if (receiver_acc->SubstractAccountFund(fund_id, amount, tran))
				{
					donor_acc->AddToAccount(transfer_fund_id, amount);
					donor_acc->RecordAccountTransaction(tran, transfer_fund_id);
				}
				else
				{
					cerr << "ERROR: Not Enough Funds to Transer  " << amount << " " << "from " << donor_acc->account_id()<<" "<< fund_id << " to " << receiver_acc->account_id()<<" " << transfer_fund_id << endl;
					Transaction input_history('T', acc_id, fund_id, transfer_acc_id, transfer_fund_id, amount, "(Failed)");
					donor_acc->RecordAccountTransaction(input_history, transfer_fund_id);
				}
			}

			//if tranfering between non existent accounts
			else if(!account_list_.Retrieve(acc_id, receiver_acc) && !account_list_.Retrieve(transfer_acc_id, donor_acc))
			{
				cerr << "ERROR: Account " << acc_id << " and "<<transfer_acc_id<<" not found. Transferal refused." << endl;
			}

			else if(!account_list_.Retrieve(acc_id, receiver_acc))
			{
				cerr << "ERROR: Account " << acc_id << " not found. Transferal refused." << endl;
			}

			else if(!account_list_.Retrieve(transfer_acc_id, donor_acc))
			{
				cerr << "ERROR: Account " << transfer_acc_id << " not found. Transferal refused." << endl;
			}
		}

		//all Transaction history of an account
		else if (tran.transaction_type() == 'A')
		{
			Account* acc;
			int acc_id = tran.account_id();
			if (account_list_.Retrieve(acc_id, acc))
			{
				acc->PrintAccountHistory();
				cout << endl;
			}
			else if (!account_list_.Retrieve(acc_id, acc))
			{
				cerr << "ERROR: Account " << acc_id << " not found. Account History Not available." << endl;
			}
		}

		//all transaction history of a fund
		else if(tran.transaction_type() == 'F')
		{
			Account* acc;
			int acc_id = tran.account_id();
			int fund_id = tran.fund_id();
			if (account_list_.Retrieve(acc_id, acc))
			{
				acc->PrintAccountFundHistory(fund_id);
				cout << endl;
			}
			else if (!account_list_.Retrieve(acc_id, acc))
			{
				cerr << "ERROR: Account " << acc_id << " not found. Fund History Not available." << endl;
			}	
		}
		transaction_list_.pop();
	}
}

void Banker::Display()
{
	cout << endl;
	cout << "FINAL BALANCES:" << endl;
	account_list_.Display();
}

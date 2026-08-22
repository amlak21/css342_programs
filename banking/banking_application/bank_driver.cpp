#include "banker.h"

int main(int argc, char* argv[])
{
	string file_name;
	for (int i = 1; i < argc; i++)
	{
		file_name = argv[i];
	}
	
	Banker bank;
	bank.ReadTransactions(file_name);
	bank.ProcessTransactions();
	bank.Display();
	return 0;
}
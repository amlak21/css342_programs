
#include <iostream>
#include <string>
using namespace std;

unsigned long int Catalan(int n);

int main(int argc, char* argv[])
{
	int c = 0;
	for (int i = 0; i < argc; i++)	
	{
		if(argc >= 1)
		{
			c = stoi(argv[1]);
		}
	}
	cout<<Catalan(c) << endl;
}

unsigned long int Catalan(int n)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}
	unsigned long int answer = 0;
	for (int i = 0; i < n; i++)
	{
		answer += Catalan(i) * Catalan(n - i - 1);
	}
	return answer;
}
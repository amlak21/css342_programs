
#include "robot.h"

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (int i = 0; i < argc; i++)
	{
		if ((argc >= 2) && ((strcmp(argv[1], "greedy_robot ")) || (strcmp(argv[1], "Greedy_robot"))))
		{
			a = stoi(argv[2]);
			b = stoi(argv[3]);
			c = stoi(argv[4]);
			d = stoi(argv[5]);
			e = stoi(argv[6]);
		}
	}
	Robot r(a, b, c, d, e);
	//Robot r(1, 2, 3, 5, 2);
	//cout << "Enter pointes and maxdistance: ";
	//cin >> r;
	cout << r << endl;
	
}

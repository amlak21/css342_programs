#ifndef ROBOT_H_
#define ROBOT_H_
#include <iostream>
#include "string.h"
#include <string>
#include <vector>
using namespace std;

class Robot
{
public:
	Robot();
	Robot(int xr, int yr, int xt, int yt, int md);

	int x_robot()const;
	int y_robot()const;
	int x_treasure()const;
	int y_treausre()const;
	int max_distance()const;
	vector<string> path()const;
	void set_path(int xr, int yr, int xt, int yt, int md);

	void CountPath(int xr, int yr, char prev_pos, int steps, string curr_path);

	friend ostream& operator<<(ostream& stream, Robot& rob);
	friend istream& operator>>(istream& stream, Robot& rob);

private:
	int x_robot_;
	int y_robot_;
	int x_treasure_;
	int y_treasure_;
	int max_distance_;
	vector<string> path_;
};
#endif

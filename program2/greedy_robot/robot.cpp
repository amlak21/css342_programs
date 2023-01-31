#include "robot.h"

Robot::Robot() :x_robot_(0), y_robot_(0), x_treasure_(0), y_treasure_(0), max_distance_(0)
{
	
}
Robot::Robot(int xr, int yr, int xt, int yt, int md)
{
	if ((md <= 0) || (md > xt - xr) || (md > yt - yr))
	{
		max_distance_ = 1;
	}
	x_robot_ = xr;
	y_robot_ = yr;
	x_treasure_ = xt;
	y_treasure_ = yt;
	max_distance_ = md;
}

int Robot::x_robot()const
{
	return x_robot_;
}

int Robot::y_robot()const
{
	return y_robot_;
}

int Robot::x_treasure()const
{
	return x_treasure_;
}

int Robot::y_treausre()const
{
	return y_treasure_;
}

int Robot::max_distance()const
{
	return max_distance_;
}

vector<string> Robot::path()const
{
	return path_;
}

void Robot::set_path(int xr, int yr, int xt, int yt, int md)
{
	x_robot_ = xr;
	y_robot_ = yr;
	x_treasure_ = xt;
	y_treasure_ = yt;
	max_distance_ = md;
	if ((md <= 0) || (md > xt - xr) || (md > yt - yr))
	{
		max_distance_ = 1;
	}
}

void Robot::CountPath(int xr, int yr, char prev_pos, int steps, string curr_path)
{
	if (steps > max_distance_)
	{
		return;
	}
	if ((xr == x_treasure_) && (yr == y_treasure_))
	{
		path_.push_back(curr_path);
		return;
	}
	if (y_treasure_ < yr)
	{
		if (prev_pos == 'S')
		{
			CountPath(xr, yr - 1, 'S', steps + 1, curr_path + 'S');

		}
		else 
		{
			CountPath(xr, yr - 1, 'S', 1, curr_path + 'S');
		}
	}
	if (x_treasure_ < xr)
	{
		if (prev_pos == 'W')
		{
			CountPath(xr - 1, yr, 'W', steps + 1, curr_path + 'W');
		}
		else
		{
			CountPath(xr - 1, yr, 'W', 1, curr_path + 'W');
		}
	}
	if (y_treasure_ > yr)
	{
		if (prev_pos == 'N')
		{
			CountPath(xr, yr + 1, 'N', steps + 1, curr_path + 'N');
		}
		else
		{
			CountPath(xr, yr + 1, 'N', 1, curr_path + 'N');
		}
	}
	if (x_treasure_ > xr)
	{
		if (prev_pos == 'E')
		{
			CountPath(xr + 1, yr, 'E', steps + 1, curr_path + 'E');
		}
		else
		{
			CountPath(xr + 1, yr, 'E', 1, curr_path + 'E');
		}
	}
}

ostream& operator<<(ostream& stream, Robot& rob)
{
	string initial_path = "";
	rob.CountPath(rob.x_robot_, rob.y_robot_, 'S', 0, initial_path);

	for (int i = 0; i < rob.path_.size(); i++)
	{
		stream << rob.path_[i] << endl;
	}
	stream << "Number of paths: " << rob.path_.size() << endl;
	return stream;
}

istream& operator>>(istream& stream, Robot& rob)
{
	stream >> rob.x_robot_ >> rob.y_robot_ >> rob.x_treasure_ >> rob.y_treasure_ >> rob.max_distance_;
	return stream;
}
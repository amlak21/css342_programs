#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>
using namespace std;

class TimeSpan
{
public:
	//constructors
	TimeSpan();
	TimeSpan(double seconds);
	TimeSpan(double minutes, double seconds);
	TimeSpan(double hours, double minutes, double seconds);
	
	//getters & stters
	int hours()const;
	int minutes()const;
	int seconds()const;
	bool set_time_span(int hours, int minutes, int seconds);

	//actions
	void ReadTimeSpan(TimeSpan & ts);

	//operator overload
	TimeSpan operator-(const TimeSpan& ts) const;
	TimeSpan& operator-=(const TimeSpan& ts);
	TimeSpan operator+(const TimeSpan& ts) const;
	TimeSpan& operator+=(const TimeSpan& ts);
	TimeSpan operator-() const;

	bool operator==(const TimeSpan& rhs) const;
	bool operator!=(const TimeSpan& rhs) const;
	bool operator<(const TimeSpan& rhs) const;
	bool operator<=(const TimeSpan& rhs) const;
	bool operator>(const TimeSpan& rhs) const;
	bool operator>=(const TimeSpan& rhs) const;

	friend ostream& operator<<(ostream& stream, const TimeSpan& ts);
	friend istream& operator>>(istream& stream, TimeSpan& ts);

private:
	int hour_;
	int minute_;
	int second_;
};
#endif

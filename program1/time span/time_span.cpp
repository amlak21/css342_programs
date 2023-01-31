#include "time_span.h"

TimeSpan::TimeSpan()
{
	second_ = 0;
	minute_ = 0;
	hour_ = 0;
}

TimeSpan::TimeSpan(double seconds)
{
	if (60 < seconds || seconds < -60)
	{
		hour_ = 0;
		minute_ = 0 + ((int)(seconds) / 60);
		second_ = (int)(seconds) % 60;
	}
	else
	{
		hour_ = 0;
		minute_ = 0;
		second_ = ((int)(seconds)+60) % 60;
	}
}

TimeSpan::TimeSpan(double minutes, double seconds)
{
	if (60 < minutes || minutes < -60 || 60 < seconds || seconds < -60)
	{
		hour_ = 0 + ((int)(minutes) / 60);
		minute_ = (int)(minutes) % 60 + ((int)(seconds) / 60);
		second_ = (int)(seconds) % 60;
	}
	else
	{
		hour_ = 0;
		minute_ = ((int)minutes + 60) % 60;
		second_ = ((int)(seconds)+60) % 60;
	}
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
	if (60 < minutes || minutes < -60 || 60 < seconds || seconds < -60)
	{
		hour_ = (int)(hours)+((int)(minutes) / 60);
		minute_ = (int)(minutes) % 60 +((int)(seconds) / 60);
		second_ = (int)(seconds) % 60;
	}
	else
	{
		hour_ = (int)hours;
		minute_ = ((int)((hours - hour_) * 60 + 60 + int(minutes))) % 60;
		second_ = ((int)(seconds)+60) % 60;
	}
}

int TimeSpan::hours()const
{
	return hour_;
}

int TimeSpan::minutes()const
{
	return minute_;
}

int TimeSpan::seconds()const
{
	return second_;
}

bool TimeSpan::set_time_span(int hours, int minutes, int seconds)
{
	hour_ = hours;
	minute_ = minutes;
	second_ = seconds;
	return true;
}

void TimeSpan::ReadTimeSpan(TimeSpan & ts)
{
	cout << "Time span is " << ts.hour_ << " hours, " << ts.minute_ << " minutes, and " 
		<< ts.second_ << " seconds" << endl;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan& ts)
{
	int hours = (int)(hour_ + ts.hour_ + ((minute_ + ts.minute_) / 60));
	int minutes = (int)((minute_ + ts.minute_) % 60 + (second_ + ts.second_) / 60);
	int seconds = (int)((second_ + ts.second_) % 60);
	set_time_span(hours, minutes, seconds);

	return *this;
}

TimeSpan TimeSpan::operator+(const TimeSpan& ts) const
{
	TimeSpan result = *this;
	result += ts;
	return result;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& ts)
{
	
	int hours = (int)((hour_ - ts.hour_) + ((minute_ - ts.minute_) / 60));
	int minutes = (int)(((minute_ - ts.minute_) % 60 )+ (second_ - ts.second_) / 60);
	int seconds = (int)((second_ - ts.second_) % 60);
	set_time_span(hours, minutes, seconds);
	return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan& ts) const
{
	TimeSpan result = *this;
	result -= ts;
	return result;
}

bool TimeSpan::operator==(const TimeSpan& rhs) const
{
	return((hour_ == rhs.hour_) && (minute_ == rhs.minute_) && (second_ == rhs.second_));
}

bool TimeSpan::operator!=(const TimeSpan& rhs) const
{
	return !(*this == rhs);
}

bool TimeSpan::operator<(const TimeSpan& rhs) const
{
	return(((hour_) && (minute_) && (second_)) < ((rhs.hour_) && (rhs.minute_) && (rhs.second_)));
}

bool TimeSpan::operator<=(const TimeSpan& rhs) const
{
	return(((hour_) && (minute_) && (second_)) <= ((rhs.hour_) && (rhs.minute_) && (rhs.second_)));
}

bool TimeSpan::operator>(const TimeSpan& rhs) const
{
	return(((hour_) && (minute_) && (second_)) > ((rhs.hour_) && (rhs.minute_) && (rhs.second_)));
}

bool TimeSpan::operator>=(const TimeSpan& rhs) const
{
	return(((hour_) && (minute_) && (second_)) >= ((rhs.hour_) && (rhs.minute_) && (rhs.second_)));
}

TimeSpan TimeSpan::operator-() const
{
	TimeSpan temp;
	temp.hour_ = -hour_;
	temp.minute_ = -minute_;
	temp.second_ = -second_;
	return temp;
}

ostream& operator<<(ostream& stream, const TimeSpan& ts)
{
	stream << "Hours: " << ts.hour_ << ", Minutes: " << ts.minute_ << ", Seconds: " << ts.second_ << endl;
	return stream;
}

istream& operator>>(istream& stream, TimeSpan& ts)
{
	stream >>ts.hour_>>ts.minute_>>ts.second_; 
	return stream;
}



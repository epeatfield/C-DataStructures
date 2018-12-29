#include <iostream>
using namespace std;
/**
A simulated digital clock.
*/
class Clock
{
public:
	/**
	Sets the clock to 00:00.
	*/
	void reset();

	/**
	Advances this clock to the next minute.
	*/
	void pulse();

	/**
	Gets the hours of this clock.
	@return the hours (between 0 and 23)
	*/
	int get_hours() const;

	/**
	Gets the minutes of this clock.
	@return the minutes (between 0 and 59)
	*/
	int get_minutes() const;
private:
	int hours;
	int minutes;
};

void Clock::reset()
{
	hours = 0;
	minutes = 0;
}
void Clock::pulse()
{
	minutes = minutes + 1;
	if (minutes == 60)
	{
		hours++;
		minutes = 0;
	}
	if (hours == 24)
	{
		hours = 0;
	}
}
int Clock::get_hours() const
{
	return hours;
}
int Clock::get_minutes() const
{
	return minutes;
}

int main()
{
	Clock my_clock; my_clock.reset();

	for (int i = 0; i < 100; i++) { my_clock.pulse(); }
	cout << my_clock.get_hours() << endl;
	cout << "Expected: 1" << endl;
	cout << my_clock.get_minutes() << endl;
	cout << "Expected: 40" << endl;

	for (int i = 0; i < 70; i++) { my_clock.pulse(); }
	cout << my_clock.get_hours() << endl;
	cout << "Expected: 2" << endl;
	cout << my_clock.get_minutes() << endl;
	cout << "Expected: 50" << endl;

	for (int i = 0; i < 1270; i++) { my_clock.pulse(); }
	cout << my_clock.get_hours() << endl;
	cout << "Expected: 0" << endl;
	cout << my_clock.get_minutes() << endl;
	cout << "Expected: 0" << endl;

	return 0;
}

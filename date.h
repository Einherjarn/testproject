// File Date.h
// Definition file for the class Date
// which represents a simple date class
// IEA February 1997

#include "gtest/gtest.h"

#ifndef DATE_H
#define DATE_H
class Date
{
public:
	// Constructors
	// initialise to 1/1/1900
	Date();
	// initialise to dd/mm/yy
	Date(int dd,int mm,int yy);
	// member functions
	void print(); // prints date
	void next_day(); // sets date to next day
	// Accessor functions
	int get_day(); // returns day
	int get_month(); // returns month
	int get_year(); // returns year

	int days_in_month(int month);
	int days_between(int dd, int mm, int yy); // returns days between date date and input date
	int days_since_newyear(); // returns days since newyear and date date
private:
	int day;
	int month;
	int year;
	int leap_year(); // returns true if year is a leap
	// year. Required in next_day()
};
#endif
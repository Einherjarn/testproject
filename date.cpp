// File Date.cpp
// Implementation file for the Date class
// IEA February 1997
#include <iostream>
#include "Date.h"
// Constructor functions

Date::Date(int dd,int mm,int yy)
{
	day = dd;
	month = mm;
	year = yy;
}
Date::Date()
{
	day = 1;
	month = 1;
	year = 1900;
}

// Accessor functions
int Date::get_day()
{
	return day;
}
int Date::get_month()
{
	return month;
}
int Date::get_year()
{
	return year;
}
int Date::days_in_month(int month)
{
	int days_in_month;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: days_in_month = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: days_in_month = 30;
		break;
	case 2: if (leap_year())
		days_in_month = 29;
			else days_in_month = 28;
		break;
	}
	return days_in_month;
}
int Date::days_between(int dd, int mm, int yy)
{
	bool greater;
	if (yy > year) {
		greater = true;
	}
	else if (yy < year) {
		greater = false;
	}
	else {
		if (mm > month) {
			greater = true;
		}
		else if (mm < month) {
			greater = false;
		}
		else {
			if (dd > day) {
				greater = true;
			}
			else if (dd < day) {
				greater = false;
			}
			else {
				return 0;
			}
		}
	}
	
	if (greater) {
		int daysb = 0;
		for (int i = year; i < yy; i++) {
			daysb += 365;
		}
		for (int i = month; i < mm; i++) {
			daysb += days_in_month(i);
		}
		daysb += dd - day;
		return daysb;
	}
	else {
		int daysb = 0;
		for (int i = yy; i < year; i++) {
			daysb += 365;
		}
		for (int i = mm; i < month; i++) {
			daysb += days_in_month(i);
		}
		daysb += day - dd;
		return daysb;
	}
}
int Date::days_since_newyear()
{
	return days_between(1, 1, year);
}
// Other functions
void Date::print()
{
	std::cout << day << '/' << month << '/' << year;
}
void Date::next_day()
{
	day++;
	if (day > days_in_month(month))
	{
		day = 1;
		month++;
	if (month > 12)
	{
		month = 1;
		year++;
	}
	}
}
// Private function
int Date::leap_year()
{
	if (year % 400 == 0)
	return 1;
	else if (year % 100 == 0)
	return 0;
	else if (year % 4 == 0)
	return 1;
	else return 0;
}
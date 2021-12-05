#pragma once

#include <cmath>
#include "DateTime.h"


//equality check for integers
bool Equally(int a, int b) {
	if (a == b) return true;
	else return false;
}

//equality check for fractional number
bool Equally(double a, double b) {
	if (abs(a - b) < 0.00005) return true;
	else return false;
}

//equality check for string
bool Equally(string a, string b) {
	if (a == b) return true;
	return false;
}

//equality check for DateTime
bool Equally(DateTime a, DateTime b) {
	if (a.get_year() != b.get_year()) return false;
	if (a.get_month() != b.get_month()) return false;
	if (a.get_day() != b.get_day()) return false;
	if (a.get_hour() != b.get_hour()) return false;
	if (a.get_minute() != b.get_minute()) return false;
	if (a.get_second() != b.get_second()) return false;
	return true;
}
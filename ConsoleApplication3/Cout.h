#pragma once
#include <iostream>
#include <string>

#include "DateTime.h"


using std::cout;
using std::endl;
using std::string;

void Cout(int i) {
	cout << i << " ";
}

void Cout(double i) {
	cout << i << " ";
}

void Cout(string i) {
	cout << i << " ";
}

void Cout(DateTime D) {
	cout << D.get_year() << "\t";
	cout << D.get_month() << "\t";
	cout << D.get_day() << "\t";
	cout << D.get_hour() << "\t";
	cout << D.get_minute() << "\t";
	cout << D.get_second() << endl;
}
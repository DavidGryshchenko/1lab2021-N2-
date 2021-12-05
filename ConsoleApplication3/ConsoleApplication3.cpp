#include <iostream>

#include "iList.h"

#include "DateTime.h"


using std::cout;
using std::endl;


//to search by condition
template <typename T> bool b(T d)
{
	if (d > 50)return true;
	return false;
}



void testNumbers()
{
	cout << "______________________________testNumbers()_____________________________" << endl;

	iList<int> L(arr);
	L.fill_random(10);
	L.print();

	int kol = L.size();
	cout << "kol = " << kol << endl;

	cout << "L.find_by_index(4) = " << L.find_by_index(4) << endl;

	L.del_k(7);
	cout << "... del 7 el ..." << endl;

	L.print();

	kol = L.size();
	cout << "kol = " << kol << endl;

	int ind_by_value = L.find_by_value(9);
	cout << "ind_by_value(9) = " << ind_by_value << endl;

	int ind_by_if = L.find_by_if(b);
	cout << "ind_by_if = " << ind_by_if << endl;

	L.print();

	cout << endl;

	L.del_all();

}

void testDateTimeR()
{
	cout << "___________________________testDateTimeR__________________________________" << endl;

	iList<DateTime> L(cycl);
	L.fill_random(10);
	L.print();

	cout << endl;
}

void testDateTimeMy()
{
	cout << "___________________________testDateTimeMy__________________________________" << endl;

	DateTime D1(2018, 10, 19, 5, 6, 7);

	D1.cout_weekday();
	Cout(D1);

	DateTime D2(2018, 11, 6, 9, 0, 2);
	Cout(D2);

	//cout << "D1.count() = " << D1.count() << endl;
	//cout << "D2.count() = " << D2.count() << endl;

	int days = difference_days(D1, D2);

	D1.add_difference_days(days);

	cout << "days = " << days << endl;

	Cout(D1);

	iList<string> L(cycl);
	L.add_end("Monday");
	L.add_end("Tuesday");
	L.add_end("Wednesday");
	L.add_end("Thursday");
	L.add_end("Friday");
	L.add_end("Saturday");
	L.add_end("Sunday");

	cout << "Day of the week: " << L.find_by_index(D1.count()) << endl;

	cout << endl;

}

int main()
{
	srand(time(0));

	testNumbers();

	testDateTimeR();

	testDateTimeMy();

	system("pause");

	return 0;
}
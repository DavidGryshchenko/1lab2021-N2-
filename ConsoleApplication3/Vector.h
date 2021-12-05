#pragma once

#include <vector>
#include "vList.h"
#include "Cout.h"
#include "Equally.h"


using std::vector;

//vector of whatever type
template<typename T> class Vector :public vList<T>
{
private:
	vector<T> vec;

public:

	//size of the vector
	int size() { return (int)vec.size(); }

	//find by index
	T find_by_index(int k) {
		return vec[k];
	}

	//add an item to the end of the vector
	bool add_end(T d) {
		vec.push_back(d);
		return true;
	}

	//delete all elements of the vector
	void del_all() {
		vec.clear();
	}

	//delete k(th) element of the vector
	void del_k(int k) {
		vec.erase(vec.begin() + k);
	}


	//find by value
	int find_by_value(T d) {
		for (int i = 0; i < (int)vec.size(); i++)
		{
			if (Equally(d, vec[i]))
				return i;
		}
		return -1;
	}

	//find by if
	int find_by_if(bool(*f)(T)) {
		for (int i = 0; i < (int)vec.size(); i++)
		{
			if (f(vec[i])) return i;
		}
		return -1;
	}

	//print the entire array
	void print() {
		for (int i = 0; i < (int)vec.size(); i++)
			Cout(vec[i]);
		std::cout << std::endl;
	}

};
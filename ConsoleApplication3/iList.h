#pragma once


#include "Array.h"
#include "List.h"
#include "Vector.h"
#include "Cyclic.h"


#include "vList.h"

//#include "Random.h"
//#include "DateTime.h"


enum mode { arr, list, vec, cycl };

template<typename T> class iList :public vList<T>
{
private:
	vList<T>* p;
	T zn;

public:

	iList(int mode) {
		switch (mode) {
		case arr:	p = new Array<T>; break;
		case list:	p = new List<T>; break;
		case vec:	p = new Vector<T>; break;
		case cycl:  p = new Cyclic<T>; break;
		default: p = new Array<T>; break;
		}
	}

	bool add_end(T d) {
		return p->add_end(d);
	}

	int size() {
		return p->size();
	}

	void del_all() {
		return p->del_all();
	}

	void del_k(int k) {
		return p->del_k(k);
	}

	T find_by_index(int k) {
		return p->find_by_index(k);
	}

	int find_by_value(T d) {
		return p->find_by_value(d);
	}

	int find_by_if(bool(*f)(T)) {
		return p->find_by_if(f);
	}

	void print() {
		return p->print();
	}

	void fill_random(int n) {
		for (int i = 0; i < n; i++)
		{
			add_end(Random(zn));
		}
	}

};
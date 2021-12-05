#pragma once


#include "vList.h"
#include "Cout.h"
#include "Equally.h"


template<typename T>
class Cyclic :public vList<T>
{
	template<typename T> class Node {
	public:
		T v;
		Node* next;
	};

	int kol;

	Node<T>* beg;
	Node<T>* end;

public:

	Cyclic() {
		kol = 0;
		beg = NULL;
		end = NULL;
	}

	~Cyclic() {
		while (kol != 0)
		{
			Node* temp = beg->next;
			delete beg;
			beg = temp;
			kol--;
		}
	}


	//size of the CList
	int size() {
		return kol;
	}


	bool add_end(T d) {
		kol++;
		Node<T>* temp = new Node<T>;

		temp->next = beg;
		temp->v = d;

		if (beg != NULL)
		{
			end->next = temp;
			end = temp;
		}
		else beg = end = temp;

		return true;
	}

	//delete all elements of the list
	void del_all() {
		end->next = NULL;
		while (beg->next)
		{
			end = beg;
			beg = beg->next;
			delete end;
		}
		kol = 0;
		delete beg;
		beg = end = NULL;
	}

	//delete k(th) element of the list
	void del_k(int k) {
		Node<T>* tmp = beg;

		if (k >= kol || k < 0) return;
		kol--;
		if (k == 0)
		{
			beg = beg->next;
			delete tmp;
			return;
		}
		else
		{
			for (int i = 1; i < k; i++) {
				tmp = tmp->next;
			}
			Node<T>* tmp2 = tmp->next;
			if (k == kol) tmp->next = NULL;
			else tmp->next = tmp->next->next;
			delete tmp2;

		}


	}

	//find by index
	T find_by_index(int k) {
		Node<T>* tmp = beg;

		for (int i = 0; i < k; i++)
		{
			tmp = tmp->next;
		}
		return tmp->v;
	}

	//find by value
	int find_by_value(T d) {
		int j = 0;
		Node<T>* tmp = beg;

		while (tmp)
		{
			if (Equally(tmp->v, d)) return j;
			tmp = tmp->next;
			if (j > kol) return -1;
			j++;
		}
		return -1;
	}

	//find by if
	int find_by_if(bool(*f)(T)) {
		Node<T>* tmp = beg;

		for (int i = 0; i < kol; i++)
		{

			if (f(tmp->v)) return i;
			tmp = tmp->next;
		}
		return -1;
	}

	//print the entire list
	void print() {
		Node<T>* tmp = beg;

		for (int i = 0; i < kol; i++)
		{
			Cout(tmp->v);
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}


};
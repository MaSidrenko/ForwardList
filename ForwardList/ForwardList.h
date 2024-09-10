#pragma once
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimeter "\n|--------------------------------------------------|\n"

template<typename T>class List
{
protected:
	class Element
	{
	protected:
		T Data;			//«начение элемента
		Element* pNext;//”казатель на следующий элемент
		static int count;
	public:
		Element(T Data, Element* pNext = nullptr);
		~Element();
		friend class Iterator;
		friend class List;
		friend class Stack;
	};
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "ItConstructor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "ItDestructor:\t" << this << endl;
		}
		//		Operators:
		Iterator& operator++();
		bool operator!=(const Iterator& other)const;
		T operator*();
	};
	Element* Head;
	unsigned int size;
public:
	Iterator begin();
	Iterator end();
	//		Constructor:
	List();
	List(const std::initializer_list<T>& il);
	List(const List<T>& other);
	List(List<T>&& other)noexcept;
	~List();
	//		Operators:
	List& operator=(const List<T>& other);
	List& operator=(List<T>&& other);
	//		Adding elements:
	void push_front(T Data);

	void push_back(T Data);
	void insert(T Data, int Index);
	//			Removibg elements:
	void pop_front();
	void pop_back();
	void erese(int Index);
	//		Methods:
	void revrese();
	void print()const;
};



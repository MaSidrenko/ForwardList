#pragma once
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimeter "\n|-----------------------------------------|\n"



template<typename T>class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List;
	}*Head, * Tail;
	size_t size;
	class Const_BaseIterator
	{
	protected:
		Element* Temp;
	public:
		Const_BaseIterator(Element* Temp = nullptr) : Temp(Temp) {}
		~Const_BaseIterator() {}
		//				Comparison operators:
		bool operator==(const Const_BaseIterator& other)const;
		bool operator!=(const Const_BaseIterator& other)const;
		//			Dereference operators:
		const T& operator*()const;

	};
public:
	class Const_Iterator : public Const_BaseIterator
	{
	public:
		Const_Iterator(Element* Temp = nullptr) :Const_BaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "It_Constructor:\t" << this << endl;
#endif // DEBUG

		}
		~Const_Iterator()
		{
#ifdef DEBUG
			cout << "It_Destructor:\t" << this << endl;
#endif // DEBUG

		}
		Const_Iterator& operator++();
		Const_Iterator operator++(int);
		Const_Iterator& operator--();
		Const_Iterator operator--(int);
	};
	class Const_ReverseIterator : public Const_BaseIterator
	{
	public:
		Const_ReverseIterator(Element* Temp = nullptr) : Const_BaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "RIt_Constructor:\t" << this << endl;
#endif // DEBUG

		}
		~Const_ReverseIterator()
		{
#ifdef DEBUG
			cout << "RIt_Destructor:\t" << this << endl;
#endif // DEBUG
		}
		//				Incremento/Decremento:
		Const_ReverseIterator& operator++();
		Const_ReverseIterator operator++(int);
		Const_ReverseIterator& operator--();
		Const_ReverseIterator operator--(int);
	};
	class Iterator : public Const_Iterator
	{
	public:
		Iterator(Element* Temp = nullptr) :Const_Iterator(Temp) {}
		~Iterator() {}
		T& operator*();
	};
	class Reverse_Iterator : public Const_ReverseIterator
	{
	public:
		Reverse_Iterator(Element* Temp = nullptr) :Const_ReverseIterator(Temp) {}
		~Reverse_Iterator() {}
		T& operator*();
	};
	Const_Iterator begin()const;
	Iterator begin();
	Const_Iterator end()const;
	Iterator end();
	Const_ReverseIterator r_begin()const;
	Const_ReverseIterator r_end()const;
	Reverse_Iterator r_begin();
	Reverse_Iterator r_end();

	//			Constractors:
	List();
	List(const std::initializer_list<T>& il);
	List(const List<T>& other);
	~List();

	//		operators:
	List<T>& operator=(const List<T>& other);

	//			Adding Elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(T Data, int Index);
	//			Removing Elements:
	void pop_front();
	void pop_back();
	void erase(int Index);
	//			Methods:
	void print()const;
	void reverse_print()const;
};

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right);
template<typename T>void Grow(List<T>& list);
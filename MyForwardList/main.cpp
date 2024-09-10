#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

class Element
{
	int Data;
	Element* pNext;
public:
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		cout << "E_Constructor:\t" << this << endl;
	}	
	~Element()
	{
		cout << "E_Destructor:\t" << this << endl;
	}
	friend class ForwardList;
	friend class Iterator;
};

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp) : Temp(Temp)
	{
		cout << "I_Constructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "I_Destructor:\t" << this << endl;
	}
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}
	int operator*()
	{
		return Temp->Data;
	}
};

class ForwardList
{
	Element* Head;
	unsigned int size;
public:
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ForwardList()
	{
		Head = nullptr;
		size = 0;
		cout << "FL_Constructor:\t" << this << endl;
	}
	ForwardList(const std::initializer_list<int>& il): ForwardList()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		*this = other;
		cout << "Copy_Constrator:\t" << this << endl;
	}
	ForwardList(const ForwardList&& other) : Head(Head), size(size)
	{

	}
	~ForwardList()
	{
		while(Head)pop_front();
		cout << "FL_Destructor:\t" << this << endl;
	}
	ForwardList operator=(ForwardList& other)
	{

	}
	void push_front(int Data)
	{
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
		size++;
	}
	void insert(int Data,int index)
	{
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data, Temp->pNext);
		size++;
	}
	void pop_front()
	{
		if (Head == nullptr)return;
		Element* erased = Head;
		Head = Head->pNext;
		delete erased;
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		Element* erased = Head;
		while (erased->pNext->pNext)
		{
			erased = erased->pNext;
		}
		delete erased->pNext;
		erased->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (Head == nullptr)return;
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* erased = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete erased;
		size--;
	}
	void print()
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Количество жлементов списка: " << size << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	ForwardList List;
	int n;
	cout << "Введите количество добавляемых элементов: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		//List.push_front(rand() % 100);
		List.push_back(rand() % 100);
	}
	List.print();
	List.pop_front();
	List.print();
	List.pop_back();
	List.print();
}
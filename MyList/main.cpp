#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimeter "\n|--------------------------------------------|\n"

class Element
{
	Element* pNext;
	Element* pPrev;
	int Data;
public:
	Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) : Data(Data), pNext(pNext), pPrev(pPrev)
	{
		cout << "E_Constructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "E_Destructor:\t" << this << endl;
	}
	friend class NodeList;
};

class NodeList
{
	unsigned int size;
	Element* Head;
	Element* Tail;
public:
	NodeList()
	{
		Head = nullptr;
		Tail = nullptr;
		size = 0;
		cout << "L_Constractor:\t" << this << endl;
	}
	~NodeList()
	{
		cout << "L_Destractor:\t" << this << endl;
	}
	//		Adding Elements:
	void push_front(int Data)
	{
		if(Head == nullptr && Tail == nullptr)
		{
		
		}
		else {
			Element* New = new Element(Data);
			New->pNext = Head;
			Head->pPrev = New;
			Head = New;
		}
	}
	void push_back(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = nullptr;
		Tail = New;
	}
	//		Removing elements:
	void pop_front()
	{
		if (Head == nullptr)return;
		Element* Eres = Head;
		Head = Head->pNext;
		delete Eres;
		size--;
	}
	//			Methods:
	void print()const
	{
		if (Head) 
		{
			for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			{
				cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			}
			cout << endl;
		}
		if (Tail) 
		{
			for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
			{
				cout << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
			}
			cout << endl;
		}
	}

};


void main()
{
	setlocale(LC_ALL, "");
	NodeList list;
	int n;
	cout << "Введите число добавляемых значений:\t"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
}
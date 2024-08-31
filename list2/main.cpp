#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimeter "\n|-----------------------------------------|\n"


template<typename T>
class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr) : Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "E_Constractor:\t" << this << endl;
		}
		~Element()
		{
			cout << "E_Destrutor:\t" << this << endl;
		}
		friend class List;
	}*Head, *Tail;
	size_t size;
	class Const_BaseIterator
	{
	protected:
		Element* Temp;
	public:
		Const_BaseIterator(Element* Temp =  nullptr): Temp(Temp) {}
		~Const_BaseIterator() {}
		//				Comparison operators:
		bool operator==(const Const_BaseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Const_BaseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		//			Dereference operators:
		const T& operator*()const
		{
			return Temp->Data;
		}
	
	};
public:
	class Const_Iterator: public Const_BaseIterator
	{
	public:
		Const_Iterator(Element* Temp = nullptr):Const_BaseIterator(Temp) 
		{
			cout << "It_Constructor:\t" << this << endl;
		}
		~Const_Iterator()
		{
			cout << "It_Destructor:\t" << this << endl;
		}
		Const_Iterator& operator++()
		{
			Const_BaseIterator::Temp = Const_BaseIterator::Temp->pNext;
			return *this;
		}
		Const_Iterator operator++(int)
		{
			Const_Iterator old = *this;
			Const_BaseIterator::Temp = Const_BaseIterator::Temp->pNext;
			return old;
		}
		Const_Iterator& operator--()
		{
			Const_BaseIterator::Temp = Const_BaseIterator::Temp->pPrev;
			return *this;
		}
		Const_Iterator operator--(int)
		{
			Const_Iterator old = *this;
			Const_BaseIterator::Temp = Const_BaseIterator::Temp->pPrev;
			return old;
		}
	};
	class Const_ReverseIterator: public Const_BaseIterator
	{
	public:
		Const_ReverseIterator(Element* Temp = nullptr) : Const_BaseIterator(Temp)
		{
			cout << "RIt_Constructor:\t" << this << endl;
		}
		~Const_ReverseIterator()
		{
			cout << "RIt_Destructor:\t" << this << endl;

		}
		//				Incremento/Decremento:
		Const_ReverseIterator& operator++()
		{
			Const_BaseIterator::Temp = Const_BaseIterator::Temp->pPrev;
			return *this;
		}
		Const_ReverseIterator operator++(int)
		{
			Const_ReverseIterator old = *this;
			Const_BaseIterator::Temp = Const_BaseIterator::Temp->pPrev;
			return old;
		}
		Const_ReverseIterator& operator--()
		{
			Const_BaseIterator::Temp = Const_BaseIterator::Temp->pNext;
			return *this;
		}
		Const_ReverseIterator operator--(int)
		{
			Const_ReverseIterator old = *this;
			Const_BaseIterator::Temp = Const_BaseIterator::Temp->pNext;
			return old;
		}
	};
	class Iterator : public Const_Iterator
	{
	public:
		Iterator(Element* Temp = nullptr):Const_Iterator(Temp){}
		~Iterator() {}
	T& operator*()
	{
		return Const_BaseIterator::Temp->Data;
	}
	};	
	class Reverse_Iterator : public Const_ReverseIterator
	{
	public:
		Reverse_Iterator(Element* Temp = nullptr):Const_ReverseIterator(Temp){}
		~Reverse_Iterator() {}
	T& operator*()
	{
		return Const_BaseIterator::Temp->Data;
	}
	};
	Const_Iterator begin()const
	{
		return Head;
	}
	Iterator begin()
	{
		return Head;
	}
	Const_Iterator end()const
	{
		return nullptr;
	}
	Iterator end()
	{
		return nullptr;
	}
	Const_ReverseIterator r_begin()const
	{
		return Tail;
	}
	Const_ReverseIterator r_end()const
	{
		return nullptr;
	}
	Reverse_Iterator r_begin()
	{
		return Tail;
	}
	Reverse_Iterator r_end()
	{
		return nullptr;
	}

	//			Constractors:
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "L_Constractor:\t" << this << endl;
	}
	List(const std::initializer_list<T>& il): List()
	{
		for (T const* it = il.begin(); it != il.end(); ++it)
		{
			push_back(*it);
		}
	}
	List(const List<T>& other): List()
	{
		*this = other;
		cout << "CopyConstructor: " << this << endl;
	}
	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
		cout << "L_Destructor:\t" << this << endl;
	}

	//		operators:
	List<T>& operator=(const List<T>& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
		cout << "CopyAssignment:\t " << this << endl;
		return *this;
	}

	//			Adding Elements:
	void push_front(T Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);	
		}else
		{
			Head = Head->pPrev = new Element(Data, Head);
			//New->pNext = Head;
			//Head->pPrev = New;
			//Head = New;
		}
		size++;
	}
	void push_back(T Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
		}else
		{
			Tail = Tail->pNext = new Element(Data,nullptr ,Tail);
			//New->pPrev = Tail;
			////Tail->pNext = New;
			//Tail = New;
		}
		size++;
	}
	void insert(T Data, int Index)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			push_front(Data);
		}
		Element* Temp = nullptr;
		if (Index < size / 2) 
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = Index; i < size - 1; i++)Temp = Temp->pPrev;
		}
		Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
		//New->pNext= Temp;
		//New->pPrev = Temp->pPrev;
		//Temp->pPrev->pNext = New;
		//Temp->pPrev = New;
		size++;
	}
	//			Removing Elements:
	void pop_front()
	{
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
		}
		else
		{
			Head = Head->pNext;
			delete Head->pPrev;
			Head->pPrev = nullptr;
		}
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			delete Tail;
			Head = Tail = nullptr;
		}else
		{
			Tail = Tail->pPrev;
			delete Tail->pNext;
			Tail->pNext = nullptr;
		}
		size--;
	}
	void erase(int Index)
	{
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			pop_front();
		}
		Element* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		}else
		{
			Temp = Tail;
			for (int i = Index; i < size - 1; i++)Temp = Temp->pPrev;
		}
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
		size--;
	}
	//			Methods:
	void print()const
	{
		cout << delimeter << endl;
		cout << "Head:\t" << Head << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
			cout << "Tail:\t" << Tail << endl;
			cout << "Количество элементов списка: " << size << endl;
		cout << delimeter << endl;
	}
	void reverse_print()const
	{
		cout << delimeter << endl;
		cout << "Tail:\t" << Tail << endl;
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Количество элементов списка: " << size << endl;
		cout << "Head:\t" << Head << endl;
		cout << delimeter << endl;
	}
};
template<typename T>
List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> buffer = left;		//CopyConstructor;
	for (typename List<T>::Const_Iterator it = right.begin(); it != right.end(); ++it)
	{
		buffer.push_back(*it);
		//*it *= 10;
	}
	return buffer;
}
template<typename T>void Grow(List<T>& list)
{
	for (typename List<T>::Iterator it = list.begin(); it != list.end(); ++it)
	{
		*it *= 10;
	}
}

//#define BASE_CHECK
//#define ITERATOR_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите количество элементов: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}

	list.print();
	list.reverse_print();

	//list.pop_front();
	//list.print();
	//list.reverse_print();

	list.pop_back();
	list.print();
	list.reverse_print();
	int index;
	int Data;
	cout << "Введите индекс:\t"; cin >> index;
	cout << "Введите добавляемое значение:\t "; cin >> Data;
	list.insert(Data, index);
	list.print();
	list.reverse_print();
	list.erase(index);
	list.print();
	list.reverse_print();
#endif // BASE_CHECK

#ifdef ITERATOR_CHECK
	List list = { 3,5,8,13,21 };
	list.print();
	list.reverse_print();
	//for (int i : list) cout << i << tab; cout << endl;
	for (List::ReverseIterator it = list.r_begin(); it != list.r_end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // ITERATOR_CHECK

	List<int> list1 = { 3, 5, 8, 13, 21 };
	List<int> list2 = {34, 55, 89};
	List<int> list3 = list1 + list2;
	list3.print();
	list3.reverse_print();
	for (int i : list1)cout << i << tab; cout << endl;
	for (int i : list2)cout << i << tab; cout << endl;
	for (int i : list3)cout << i << tab; cout << endl; cout << delimeter;
	Grow(list3);
	for (int i : list3)cout << i << tab; cout << endl; cout << delimeter;
}
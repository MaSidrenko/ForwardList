#include"List.h"
template<typename T>List<T>::Element::Element(T Data, Element* pNext, Element* pPrev) : Data(Data), pNext(pNext), pPrev(pPrev)
{
#ifdef DEBUG
	cout << "E_Constractor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>List<T>::Element::~Element()
{
#ifdef DEBUG
	cout << "E_Destrutor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>bool List<T>::Const_BaseIterator::operator==(const Const_BaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>bool List<T>::Const_BaseIterator::operator!=(const Const_BaseIterator& other)const
{
	return this->Temp != other.Temp;
}
//			Dereference operators:
template<typename T> const T& List<T>::Const_BaseIterator::operator*()const 
{
	return Temp->Data;
}
template<typename T>typename List<T>::Const_Iterator& List<T>::Const_Iterator::operator++()
{
	Const_BaseIterator::Temp = Const_BaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::Const_Iterator List<T>::Const_Iterator::operator++(int)
{
	Const_Iterator old = *this;
	Const_BaseIterator::Temp = Const_BaseIterator::Temp->pNext;
	return old;
}
template<typename T>typename List<T>::Const_Iterator& List<T>::Const_Iterator::operator--()
{
	Const_BaseIterator::Temp = Const_BaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::Const_Iterator List<T>::Const_Iterator::operator--(int)
{
	Const_Iterator old = *this;
	Const_BaseIterator::Temp = Const_BaseIterator::Temp->pPrev;
	return old;
}
template<typename T>typename List<T>::Const_ReverseIterator& List<T>::Const_ReverseIterator::operator++()
{
	Const_BaseIterator::Temp = Const_BaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::Const_ReverseIterator List<T>::Const_ReverseIterator::operator++(int)
{
	Const_ReverseIterator old = *this;
	Const_BaseIterator::Temp = Const_BaseIterator::Temp->pPrev;
	return old;
}
template<typename T>typename List<T>::Const_ReverseIterator& List<T>::Const_ReverseIterator::operator--()
{
	Const_BaseIterator::Temp = Const_BaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::Const_ReverseIterator List<T>::Const_ReverseIterator::operator--(int)
{
	Const_ReverseIterator old = *this;
	Const_BaseIterator::Temp = Const_BaseIterator::Temp->pNext;
	return old;
}
template<typename T>T& List<T>::Iterator::operator*()
{
	return Const_BaseIterator::Temp->Data;
}
template<typename T>T& List<T>::Reverse_Iterator::operator*()
{
	return Const_BaseIterator::Temp->Data;
}
////////////////////////////////////////////////////////////////////////
/////////////////			list members			////////////////////
template<typename T>typename List<T>::Const_Iterator List<T>::begin()const
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename List<T>::Const_Iterator List<T>::end()const
{
	return nullptr;
}
template<typename T>typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template<typename T>typename List<T>::Const_ReverseIterator List<T>::r_begin()const
{
	return Tail;
}
template<typename T>typename List<T>::Const_ReverseIterator List<T>::r_end()const
{
	return nullptr;
}
template<typename T>typename List<T>::Reverse_Iterator List<T>::r_begin()
{
	return Tail;
}
template<typename T>typename List<T>::Reverse_Iterator List<T>::r_end()
{
	return nullptr;
}

//			Constractors:
template<typename T> List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "L_Constractor:\t" << this << endl;
}
template<typename T> List<T>::List(const std::initializer_list<T>& il) : List()
{
	for (T const* it = il.begin(); it != il.end(); ++it)
	{
		push_back(*it);
	}
}
template<typename T> List<T>::List(const List<T>& other) : List()
{
	*this = other;
	cout << "CopyConstructor: " << this << endl;
}
template<typename T> List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
	cout << "L_Destructor:\t" << this << endl;
}

//		operators:
template<typename T> List<T>& List<T>::operator=(const List<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
	cout << "CopyAssignment:\t " << this << endl;
	return *this;
}

//			Adding Elements:
template<typename T> void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
	}
	else
	{
		Head = Head->pPrev = new Element(Data, Head);
		//New->pNext = Head;
		//Head->pPrev = New;
		//Head = New;
	}
	size++;
}
template<typename T> void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
	}
	else
	{
		Tail = Tail->pNext = new Element(Data, nullptr, Tail);
		//New->pPrev = Tail;
		////Tail->pNext = New;
		//Tail = New;
	}
	size++;
}
template<typename T> void List<T>::insert(T Data, int Index)
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
template<typename T> void List<T>::pop_front()
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
template<typename T> void List<T>::pop_back()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Tail;
		Head = Tail = nullptr;
	}
	else
	{
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
	}
	size--;
}
template<typename T> void List<T>::erase(int Index)
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
	}
	else
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
template<typename T> void List<T>::print()const
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
template<typename T>void List<T>::reverse_print()const
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
/////////////////			list members			////////////////////
////////////////////////////////////////////////////////////////////////

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right)
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
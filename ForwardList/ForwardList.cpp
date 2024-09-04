#include"ForwardList.h"

template<typename T>List<T>::Element::Element(T Data, Element *pNext) :Data(Data), pNext(pNext)
{
	count++;

	cout << "EConstractor:\t" << this << endl;
}
template<typename T>List<T>::Element::~Element()
{
	count--;
	cout << "EDestructor:\t" << this << endl;
}
template<typename T>typename List<T>::Iterator::Iterator& List<T>::Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
template<typename T>bool List<T>::Iterator::operator!=(const Iterator& other)const
{
	return this->Temp != other.Temp;
}

template<typename T>T List<T>::Iterator::operator*()
{
	return Temp->Data;
}
template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
//		Constructor:
template<typename T>List<T>::List()
{
	Head = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>List<T>::List(const std::initializer_list<T>& il) :List()
{
	cout << typeid(il.begin()).name() << endl;;
	for (T const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
}
template<typename T>List<T>::List(const List& other) :List()
{
	//for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
	*this = other;
	cout << "LCopyConstrator: " << this << endl;
}
template<typename T>List<T>::List(List&& other)noexcept :Head(Head), size(size)
{
	other.Head = nullptr;
	other.size = 0;
	cout << "LMoveConstrator: " << this << endl;
}
template<typename T>List<T>::~List()
{
	while (Head)
	{
		pop_front();
	}
	pop_front();
	cout << "LDestructor:\t" << this << endl;
}
//		Operators:
template<typename T>typename List<T>::List& List<T>::operator=(const List& other)
{
	if (this == &other)return *this;
	while (Head)
	{
		pop_front();
	}
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_front(Temp->Data);
	revrese();
	//push_back(Temp->Data);
	cout << "LCopyAssigment: " << this << endl;
	return *this;
}
template<typename T>typename List<T>::List& List<T>::operator=(List&& other)
{
	if (this == &other)return *this;
	delete[] this->Head;
	while (Head)pop_front();
	this->Head = other.Head;
	this->size = other.size;

	other.Head = nullptr;
	other.size = 0;
	cout << "LMoveAssigment: " << this << endl;
	return *this;
}
//		Adding elements:
template<typename T>void List<T>::push_front(T Data)
{
	////1. Создаём новый элемент:
	//Element* New = new Element(Data);
	////2. Включаем новый элемент в список:
	//New->pNext = Head;
	////3. Переводим голову на новый элемент:
	//Head = New;

	Head = new Element(Data, Head);
	size++;
}

template<typename T>void List<T>::push_back(T Data)
{
	if (Head == nullptr)return push_front(Data);
	//1. Доходим до конца списка: 
	Element* Temp = Head;
	while (Temp->pNext)
	{
		Temp = Temp->pNext;
	}

	//2. Создаём новый элемент:
	Temp->pNext = new Element(Data);

	//3. Включаем новый элемент в список:
	size++;
}
template<typename T>void List<T>::insert(T Data, int Index)
{
	if (Index > Head->count)return;
	if (Index == 0)return push_front(Data);
	//1. Доходим до нужного элемента:
	Element* Temp = Head;
	for (int i = 0; i < Index - 1; i++)
	{
		Temp = Temp->pNext;
	}

	//2. Создаем новый элемент
	Temp->pNext = new Element(Data, Temp->pNext);

	//3. Включаем в список:
	//New->pNext = Temp->pNext;
	//Temp->pNext = New;
	size++;
}
//			Removibg elements:
template<typename T>void List<T>::pop_front()
{
	if (Head == nullptr)return;
	Element* erased = Head;
	Head = Head->pNext;
	delete erased;
	size--;
}
template<typename T>void List<T>::pop_back()
{
	if (Head == nullptr || Head->pNext == nullptr)return pop_front();
	Element* Temp = Head;
	while (Temp->pNext->pNext)
	{
		Temp = Temp->pNext;
	}
	delete Temp->pNext;
	Temp->pNext = nullptr;
	size--;
}
template<typename T>void List<T>::erese(int Index)
{
	if (Index >= size)return;
	if (Index == 0)return pop_front();
	Element* Temp = Head;
	for (int i = 0; i < Index - 1; i++)
	{
		Temp = Temp->pNext;
	}
	Element* erased = Temp->pNext;

	Temp->pNext = Temp->pNext->pNext;

	delete erased;

	size--;
}
//		Methods:
template<typename T>void List<T>::revrese()
{
	List buffer;
	while (Head)
	{
		buffer.push_front(Head->Data);
		pop_front();
	}
	this->Head = buffer.Head;
	this->size = buffer.size;
	buffer.Head = nullptr;

}
template<typename T>void List<T>::print()const
{
	cout << tab << "Head:\t" << Head << endl;
	/*Element* Temp = Head;	//Temp - это итератор.
	//Итератор - это указатель, при помощи которого можно перебирать элементы стрктуры данных
	while (Temp)
	{
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		Temp = Temp->pNext; //Переход на следующий элемент
	}*/
	for (List::Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	//cout << "Общие количество элементов списка: " << Head->count << endl;
	cout << "Общие количество элементов списка: " << List<T>::Element::count << endl;
	cout << "Количество элементов списка: " << size << endl;
}
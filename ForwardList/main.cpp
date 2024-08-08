#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimeter "\n|--------------------------------------------------|\n"
class Element
{

	int Data;		//Значение элемента
	Element* pNext;	//Указатель на следующий элемент
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstractor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

int Element::count;

class ForwardList
{
	Element* Head;
	unsigned int size;
public:
	ForwardList()
	{
		Head = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//		Adding elements:
	void push_front(int Data)
	{
		//1. Создаём новый элемент:
		Element* New = new Element(Data);

		//2. Включаем новый элемент в список:
		New->pNext = Head;

		//3. Переводим голову на новый элемент:
		Head = New;
		size++;
	}

	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		//1. Доходим до конца списка: 
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}

		//2. Создаём новый элемент:
		Element* New = new Element(Data);

		//3. Включаем новый элемент в список:
		Temp->pNext = New;
		size++;
	}
	void insert(int Data, int Index)
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
		Element* New = new Element(Data);

		//3. Включаем в список:
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}
	//			Removibg elements:
	void pop_front()
	{
		Element* erased = Head;
		Head = Head->pNext;
		delete erased;
		size--;
	}
	void pop_back()
	{

		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void erese(int Index)
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
	void print()const
	{
		cout << tab << "Head:\t" << Head << endl;
		Element* Temp = Head;	//Temp- это итератор.
		//Итератор - это указатель, при помощи которого можно перебирать элементы стрктуры данных
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; //Переход на следующий элемент
		}
		//cout << "Общие количество элементов списка: " << Head->count << endl;
		cout << "Общие количество элементов списка: " << Element::count << endl;
		cout << "Количество элементов списка: " << size << endl;
	}
};

#define BASE_CHECK
//#define COUNT_CHECK
void main()
{
	setlocale(LC_ALL, "");
	//Element elenent(5);
	int n;
	int index;
#ifdef BASE_CHECK
	cout << "Введите количество элементов: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	//cout << delimeter << endl;
	//list.print();
	//list.push_back(123);
	//list.print();
	cout << delimeter << endl;
	list.pop_front();
	list.print();
	cout << delimeter << endl;
	list.pop_back();
	list.print();
	cout << delimeter << endl;
	cout << "Введите индекс нового элемента: "; cin >> index;
	list.insert(rand() % 100, index);
	list.print();
	cout << delimeter << endl;
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erese(index);
	list.print();
#endif // BASE_CHECK

#ifdef COUNT_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1.print();

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();
#endif // COUNT_CHECK


}
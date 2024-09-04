//#include"ForwardList.h"
#include"ForwardList.cpp"
template<typename T>int List<T>::Element::count = 0;
//#define BASE_CHECK
//#define COUNT_CHECK
//#define PERFORMANCE_CHECK
//#define RANGE_BASED_FOR_ARRAY



void main()
{
	setlocale(LC_ALL, "");
	//Element elenent(5);
	int n;
	int index;
#ifdef BASE_CHECK
	cout << "Введите количество элементов: "; cin >> n;
	List<int> list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		//list.push_back(rand() % 100);
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

#ifdef PERFORMANCE_CHECK

	cout << "Введите количество элементов: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//if (i % (1024 * 1024)==0)cout << i << tab;
		list.push_front(rand() % 100);
		//list.push_back(rand() % 100);
	}
	cout << "List filled" << endl;
	//list.print();


	cout << "Making copy" << endl;
	ForwardList list2 = list;
	//ForwardList list2;
	//list2.print();
	cout << "Copy DONE" << endl;
#endif // PERFORMANCE_CHECK

#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3, 5 ,8, 13, 21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << *(arr + i) << tab;
	}
	cout << endl;

	//Range-based for
	//Range (диапозон) в данном контексте понимается как контейнер.
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
	for (int i = 0; i < arr[i]; i++)
	{
		cout << *(arr + i) << tab;
	}
#endif // RANGE_BASED_FOR_ARRAY

	List<std::string> list = { "Vasya", "Petkin"};
	list.print();
	for (std::string i : list)
	{
		cout << i << tab;
	}
	cout << endl;
}
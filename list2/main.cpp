#include"List2.cpp"

//#define BASE_CHECK
//#define ITERATOR_CHECK
//#define INT_CHECK
//#define DOUBLE_CHECK
#define STRING_CHECK

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

#ifdef INT_CHECK
	List<int> list1 = { 3, 5, 8, 13, 21 };
	List<int> list2 = { 34, 55, 89 };
	List<int> list3 = list1 + list2;
	list3.print();
	list3.reverse_print();
	for (int i : list1)cout << i << tab; cout << endl;
	for (int i : list2)cout << i << tab; cout << endl;
	for (int i : list3)cout << i << tab; cout << endl; cout << delimeter;
	Grow(list3);
	for (int i : list3)cout << i << tab; cout << endl; cout << delimeter;
#endif // INT_CHECK

#ifdef DOUBLE_CHECK
	List<double>list_d1 = { 3.14, 3.2, 5.6 };
	List<double>list_d2 = { 2.7, 9.8, 3.5 };
	List<double>list_d3 = list_d1 + list_d2;
	list_d3.print();
	list_d3.reverse_print();
	for (double i : list_d1)cout << i << tab; cout << endl;
	for (double i : list_d2)cout << i << tab; cout << endl;
	for (double i : list_d3)cout << i << tab; cout << endl; cout << delimeter;
	Grow(list_d3);
	for (double i : list_d3)cout << i << tab; cout << endl; cout << delimeter;
#endif // DOUBLE_CHECK

#ifdef STRING_CHECK
	List<std::string> list_c1 = { "Vasya " };
	List<std::string> list_c2 = { "Sidorov" };
	List<std::string> list_c3 = list_c1 + list_c2;
	list_c3.print();
	list_c3.reverse_print();
	for (std::string i : list_c1)cout << i << tab; cout << endl;
	for (std::string i : list_c2)cout << i << tab; cout << endl; cout << delimeter;
	for (std::string i : list_c3)cout << i << tab; cout << endl; cout << delimeter;
#endif // STRING_CHECK

}
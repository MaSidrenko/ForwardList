#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	//int arr[] = { 3, 5, 8, 12, 21 };
	//cout << arr << endl;
	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	cout << *(arr + i) << tab;
	//}
	//cout << endl;
	int size = 5;
	int* arr = new int[size];
	int n;
	cout << "Количество добавляемых значений: "; cin >> n;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (100 - 50) + 100;
	}
		int* buffer = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[size++] = n;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	delete[] arr;
}

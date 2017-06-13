#include<fstream>
#include "List.h"
#include "BST.h"
#include <iostream>
#include "MergeSort.h"
using namespace std;
using namespace list;

void superset()
{
	// Открываем файл.
	ifstream fin("superset.txt");

	// Считываем количество множеств.
	int set_count;
	fin >> set_count;

	// Заводим массив для множеств.
	Node<int> ** sets= new Node<int>*[set_count];

	// Считываем множества из файла.
	for (int i = 0; i < set_count; i++)
	{
		// Инициализируем множество.
		sets[i] = create<int>();
		// Считываем количество элементов.
		int k;
		fin >> k;
		// Заполняем множества элементами из файла.
		for (int j = 0; j < k; j++)
		{
			// Считываем очередной элемент.
			int tmp;
			fin >> tmp;
			// Добавляем элемент к множеству.
			add(sets[i], tmp);
		}
		// Разворачиваем множество (т.к. элементы добавлялись в начало списков).
		reverse(sets[i]);
	}
	fin.close();

	// Выводим множества на экран.
	for (int i = 0; i < set_count; i++)
		print(cout, sets[i]);

	cout << endl;

	// Удаляем из множества все элементы последующих множеств.
	for (int i = 0; i < set_count - 1; i++)
	{
		for (int j = i + 1; j < set_count; j++)
		{
			remove_all(sets[i], sets[j]);
		}
	}

	// Вычисляем и выводим на экран количество пустых множеств.
	int empty_sets = 0;
	for (int i = 0; i < set_count; i++)
		if (list::is_empty(sets[i]))
			empty_sets++;
	cout << "kol of empty sets=" << empty_sets << endl;

	// Выводим на экран содержимое множеств.
	for (int i = 0; i < set_count; i++)
		print(cout,sets[i]);

	// Очищаем память, выделенную под множества и массив множеств.
	for (int i = 0; i < set_count; i++)
		clear(sets[i]);
	delete[]sets;
}

void bst()
{
	BST::TreeNode<int>* root = BST::create<int>();
	ifstream fin("bst.txt");
	int k;
	while (fin>>k)
	{
		BST::add(root, k);
	}
	fin.close();

	BST::print_BF(cout,root);
	BST::clear(root);
}

void merge_sort_test()
{
	int a[10] = { 3,1,5,7,2,4,0,6,9,8 };
	merge_sort::merge_sort(a, 10);

	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	cout << endl;
}


int main()
{	
	//superset();

	//bst();

	//merge_sort_test();

	return 0;
}
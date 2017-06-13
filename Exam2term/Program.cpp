#include<fstream>
#include "List.h"
#include "BST.h"
#include <iostream>
#include "MergeSort.h"
using namespace std;
using namespace list;

void superset()
{
	// ��������� ����.
	ifstream fin("superset.txt");

	// ��������� ���������� ��������.
	int set_count;
	fin >> set_count;

	// ������� ������ ��� ��������.
	Node<int> ** sets= new Node<int>*[set_count];

	// ��������� ��������� �� �����.
	for (int i = 0; i < set_count; i++)
	{
		// �������������� ���������.
		sets[i] = create<int>();
		// ��������� ���������� ���������.
		int k;
		fin >> k;
		// ��������� ��������� ���������� �� �����.
		for (int j = 0; j < k; j++)
		{
			// ��������� ��������� �������.
			int tmp;
			fin >> tmp;
			// ��������� ������� � ���������.
			add(sets[i], tmp);
		}
		// ������������� ��������� (�.�. �������� ����������� � ������ �������).
		reverse(sets[i]);
	}
	fin.close();

	// ������� ��������� �� �����.
	for (int i = 0; i < set_count; i++)
		print(cout, sets[i]);

	cout << endl;

	// ������� �� ��������� ��� �������� ����������� ��������.
	for (int i = 0; i < set_count - 1; i++)
	{
		for (int j = i + 1; j < set_count; j++)
		{
			remove_all(sets[i], sets[j]);
		}
	}

	// ��������� � ������� �� ����� ���������� ������ ��������.
	int empty_sets = 0;
	for (int i = 0; i < set_count; i++)
		if (list::is_empty(sets[i]))
			empty_sets++;
	cout << "kol of empty sets=" << empty_sets << endl;

	// ������� �� ����� ���������� ��������.
	for (int i = 0; i < set_count; i++)
		print(cout,sets[i]);

	// ������� ������, ���������� ��� ��������� � ������ ��������.
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
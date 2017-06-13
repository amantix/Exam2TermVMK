#pragma once
namespace list
{
	template<typename T>
	struct Node
	{
		T info;
		Node * next;
	};

	template<typename T>
	Node<T>* create()
	{
		return nullptr;
	}

	template<typename T>
	bool is_empty(Node<T>* list)
	{
		return list == nullptr;
	}

	template<typename T>
	bool is_element(Node<T>* list, T item)
	{
		for (Node<T>* i = list; i != nullptr; i = i->next)
		{
			if (i->info == item)
				return true;
		}
		return false;
	}

	

	template<typename T>
	void add(Node<T>*& list,T item)
	{
		if (is_element(list, item)) return;
		Node<T>* n = new Node<T>;
		n->info = item;
		n->next = list;
		list = n;
	}

	template<typename T>
	void reverse(Node<T>*&list)
	{
		Node<T>*tmp = create<T>();
		while (!is_empty(list))
		{
			Node<T>*n = list;
			list = list->next;
			n->next = tmp;
			tmp = n;
		}
		list = tmp;
	}


	template<typename T>
	void del(Node<T>*& list, T item)
	{
		if (!is_empty(list) && list->info == item)
		{
			Node<T>*tmp = list;
			list = list->next;
			delete tmp;
		}
		else
		{
			for (Node<T>*i = list; i != nullptr; i = i->next)
			{
				if (i->next != nullptr&&i->next->info == item)
				{
					Node<T>*tmp = i->next;
					i->next = tmp->next;
					delete tmp;
					break;
				}
			}
		}
	}

	template<typename T>
	int count(Node<T>*list)
	{
		int counter = 0;
		for (Node<T>*i; i != nullptr; i = i->next)
			counter++;
		return counter;
	}

	template<typename T>
	void remove_all(Node<T>*&list, Node<T>*another)
	{
		for (Node<int>*p = another; p != nullptr; p = p->next)
		{
			del(list, p->info);
		}
	}

	template<typename T>
	void clear(Node<T>*&list)
	{
		while (list != nullptr)
		{
			Node<T>* tmp = list;
			list = list->next;
			delete tmp;
		}
	}

	template<typename T>
	void print(std::ostream& out, Node<T>*list)
	{
		if (!is_empty(list))
		{
			for (Node<T>*i = list; i != nullptr; i = i->next)
				out << i->info << ' ';
			out << std::endl;
		}
	}
}
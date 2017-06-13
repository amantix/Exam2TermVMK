#pragma once
namespace queue
{
	template<typename T>
	struct QueueNode
	{
		T info;
		QueueNode* next;
	};

	template<typename T>
	QueueNode<T>* Create()
	{
		return nullptr;
	}

	template<typename T>
	bool Empty(QueueNode<T>*queue)
	{
		return queue == nullptr;
	}

	template<typename T>
	void EnQueue(QueueNode<T>*&queue, T item)
	{
		QueueNode<T>*node = new QueueNode<T>;
		node->info = item;
		node->next = nullptr;
		if (queue == nullptr)
			queue = node;
		else
		{
			QueueNode<T>*p = queue;
			while (p->next!=nullptr)
			{
				p = p->next;
			}
			p->next = node;
		}
	}

	// ѕредполагаетс€ что очередь не пуста
	// иначе не пон€тно что нужно возвращать.
	template<typename T>
	T DeQueue(QueueNode<T>*&queue)
	{
		QueueNode<T>*n = queue;
		queue = queue->next;
		T tmp = n->info;
		delete n;
		return tmp;
	}

	template<typename T>
	void Clear(QueueNode<T>*&queue)
	{
		while (queue!=nullptr)
		{
			QueueNode<T>*tmp = queue;
			queue = queue->next;
			delete tmp;
		}
	}
}
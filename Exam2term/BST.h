#pragma once
#include <ostream>
#include "Queue.h"

namespace BST
{
	template<typename T>
	struct TreeNode
	{
		T info;
		TreeNode* left;
		TreeNode* right;
	};

	template<typename T>
	TreeNode<T>* create()
	{
		return nullptr;
	}

	template<typename T>
	void add(TreeNode<T>*& root, T item)
	{
		TreeNode<T>*tmp = new TreeNode<T>;
		tmp->info = item;
		tmp->left = tmp->right = nullptr;

		if (root == nullptr)
			root = tmp;
		else
		{
			TreeNode<T>* n = root;
			while (n!=nullptr)
			{
				if (item > n->info)
				{
					if(n->right!=nullptr)
						n = n->right;
					else
					{
						n->right = tmp;
						break;
					}
				}
				else
				{
					if (n->left != nullptr)
						n = n->left;
					else
					{
						n->left = tmp;
						break;
					}
				}
			}
		}
	}

	template<typename T>
	void add_rec(TreeNode<T>*&root, T item)
	{
		if (root == nullptr)
		{
			root = new TreeNode<T>;
			root->info = item;
			root->left = root->right = nullptr;
		}
		else if (item > root->info)
			add_rec(root->right, item);
		else
			add_rec(root->left, item);
	}

	template<typename T>
	void print_BF(std::ostream&out,TreeNode<T>*root)
	{
		using namespace queue;
		using namespace std;
		QueueNode<pair<TreeNode<T>*,int>>* queue = queue::Create<pair<TreeNode<T>*,int>>();
		if(root!=nullptr)
			EnQueue(queue, make_pair(root,0));
		int level = 0;
		while (!Empty(queue))
		{
			pair<TreeNode<T>*,int> tmp= DeQueue(queue);
			if (tmp.second > level)
			{
				out << endl;
				level++;
			}
			out << tmp.first->info << ' ';
			if(tmp.first->left!=nullptr)
				EnQueue(queue, make_pair(tmp.first->left,tmp.second+1));
			if(tmp.first->right!=nullptr)
				EnQueue(queue, make_pair(tmp.first->right,tmp.second+1));
		}
		out << endl;
		Clear(queue);
	}

	template<typename T>
	void clear(TreeNode<T>*& root)
	{
		if (root != nullptr)
		{
			TreeNode<T>*tmp = root;
			clear(root->left);
			clear(root->right);
			delete tmp;
		}
	}
}

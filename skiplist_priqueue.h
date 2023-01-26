#ifndef SKIPLIST_PRIQUEUE
#define SKIPLIST_PRIQUEUE

#include <bits/stdc++.h>

// Class to implement node
template <typename T>
class list_node
{
public:
	const T key;
	const int level;
	list_node<T> **forward;

	list_node(const T key, int level) : key(key), level(level)
	{
		// Allocate memory to forward
		forward = new list_node<T> *[level + 1];
		memset(forward, 0, sizeof(list_node<T> *) * (level + 1));
	}
};

// Class for Skip list
template <typename T>
class skip_list_priqueue
{
private:
	// Key type
	typedef T key_type;
	// Maximum level for this skip list
	const int maxlevel;
	// P is the fraction of the nodes with level
	// i pointers also having level i+1 pointers
	const float proportion;
	// current level of skip list
	int level;
	// pointer to header node
	list_node<key_type> *const header;
	// ramdomize the level
	int random_level();
	// create node
	list_node<key_type> *create_node(key_type, int);
	// insert node
	void insert(key_type);
	// erase node
	void erase(key_type);
	// total num
	size_t total_num = 0;

public:
	skip_list_priqueue(int = 64, float = 0.5);

	size_t size(void) const
	{
		return total_num;
	}

	bool empty(void) const
	{
		return total_num == 0;
	}

	void push(const key_type key)
	{
		insert(key);
		total_num++;
	}

	void pop(void)
	{
		assert(!empty());
		erase(header->forward[0]->key);
		total_num--;
	}

	const key_type &top(void) const
	{
		assert(!empty());
		return header->forward[0]->key;
	}

	void displayList();
};

template <typename key_type>
skip_list_priqueue<key_type>::skip_list_priqueue(int maxlevel, float proportion) : maxlevel(maxlevel), proportion(proportion), level(0), header(new list_node<key_type>({}, maxlevel)){};

// create random level for node
template <typename key_type>
int skip_list_priqueue<key_type>::random_level()
{
	float r = (float)rand() / RAND_MAX;
	int lvl = 0;
	while (r < proportion && lvl < maxlevel)
	{
		lvl++;
		r = (float)rand() / RAND_MAX;
	}
	return lvl;
};

// create new node
template <typename key_type>
list_node<key_type> *skip_list_priqueue<key_type>::create_node(key_type key, int level)
{
	list_node<key_type> *node = new list_node<key_type>(key, level);
	return node;
};

// insert key
template <typename key_type>
void skip_list_priqueue<key_type>::insert(key_type key)
{
	list_node<key_type> *current = header;

	list_node<key_type> *update[maxlevel + 1];
	memset(update, 0, sizeof(list_node<key_type> *) * (maxlevel + 1));

#pragma omp parallel for
	for (int i = level; i >= 0; i--)
	{
		while (current->forward[i] != nullptr && current->forward[i]->key < key)
		{
			current = current->forward[i];
		}
		update[i] = current; // set the correct node to update
	}

	current = current->forward[0];

	if (current == nullptr || current->key != key)
	{

		int rlevel = random_level();

		if (rlevel > level)
		{
			for (int i = level + 1; i < rlevel + 1; i++)
			{
				update[i] = header; // set up new levels
			}
			level = rlevel; // Update the list current level
		}

		list_node<key_type> *node = create_node(key, rlevel);

#pragma omp parallel for
		for (int i = 0; i <= rlevel; i++)
		{
			node->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = node;
		}
	}
};

template <typename key_type>
void skip_list_priqueue<key_type>::erase(key_type key)
{
	list_node<key_type> *current = header;
	list_node<key_type> *update[maxlevel + 1];
	memset(update, 0, sizeof(list_node<key_type> *) * (maxlevel + 1));

#pragma omp parallel for
	for (int i = level; i >= 0; i--)
	{
		while (current->forward[i] != nullptr && current->forward[i]->key < key)
			current = current->forward[i];
		update[i] = current;
	}

	current = current->forward[0];

	if (current != nullptr && current->key == key)
	{

#pragma omp parallel for
		for (int i = 0; i <= level; i++)
		{
			if (update[i]->forward[i] != current)
				break;

			update[i]->forward[i] = current->forward[i];
		}

		while (level > 0 && header->forward[level] == nullptr)
		{
			level--;
		}
		delete current;
	}
}

// Display list
template <typename key_type>
void skip_list_priqueue<key_type>::displayList()
{
	std::cout << "\n*****Skip List*****" << std::endl;
	for (int i = 0; i <= level; i++)
	{
		list_node<key_type> *node = header->forward[i];
		std::cout << "Level " << i << ": ";
		while (node != NULL)
		{
			std::cout << node->key << " ";
			node = node->forward[i];
		}
		std::cout << std::endl;
	}
};

#endif //SKIPLIST_PRIQUEUE
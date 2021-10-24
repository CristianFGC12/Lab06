#pragma once
#include "Comparador.h"
#include"CompararNombre.h"

template <typename T>
class List
{
	struct Node
	{
		T* item;
		Node* next;

		Node(T* item)
		{
			this->item = item;
			this->next = nullptr;
		}
	};

	Node* head;
	Node* tail;

	int size = 0;

public:
	int getSize()
	{
		return this->size;
	}

	bool isEmpty()
	{
		return this->size == 0;
	}

	void add(T* item)
	{
		Node* node = new Node(item);

		if(this->isEmpty())
		{
			this->head = this->tail = node;
		}
		else
		{
			this->tail->next = node;
			this->tail = this->tail->next;
		}

		this->size++;
	}

	T* get(int index)
	{
		if (index >= this->size || index < 0)
		{
			return nullptr;
		}

		Node* iterator = this->head;

		int i = 0;
		while (i < index)
		{
			iterator = iterator->next;
			i++;
		}

		return iterator->item;
	}
	T*remove(int index)
	{
		if (index >= this->size || index < 0)
		{
			return nullptr;
		}

		Node** iterator = &this->head;
		Node* previous = nullptr;

		int i = 0;
		while (i < index)
		{
			previous = *iterator;
			iterator = &(*iterator)->next;
			i++;
		}

		T* item = (*iterator)->item;

		*iterator = (*iterator)->next;
		this->size--;

		if (this->size == index)
		{
			this->tail = previous;
		}

		return item;
	}
	List<T>* BubbleSort(Comparador<T>* comparador, Comparador<T>* comparando)
	{
		Node** i = &(this->head);

		while (*i != nullptr)
		{
			Node** j = &(*i)->next;
			while (*j != nullptr)
			{
				T** itemA = &(*i)->item;
				T** itemB = &(*j)->item;
				if (comparador->comparar(**itemA,**itemB) > 0)
				{
					T* aux = *itemA;
					*itemA = *itemB;
					*itemB = aux;
				}
				else if(comparador->comparar(**itemA, **itemB) == 0)
				{
					if (comparando->comparar(**itemA, **itemB) > 0)
					{
						T* aux = *itemA;
						*itemA = *itemB;
						*itemB = aux;
					}
				}
				j = &(*j)->next;
			}
			i = &(*i)->next;
		}
		return this;
	}
	List<T>* Quicksort(Comparador<T>* comparador, Comparador<T>* comparando)
	{

	}
	void Intercambio(T* a, T* b)
	{
		T Temp = *a;
		*a = *b;
		*b = Temp;
	}
	List<T>* selectionSort(Comparador<T>* comparado,Comparador<T>* comparando)
	{
		Node* temp = &(*this->head);

		// Traverse the List
		while (temp != nullptr) {
			Node* min = temp;
			Node* r = temp->next;

			// Traverse the unsorted sublist
			while (r != nullptr) {
				T** itemA = &(min)->item;
				T** itemB = &(r)->item;
				if (comparado->comparar(**itemA, **itemB) > 0)
					min = r;
					if (comparado->comparar(**itemA, **itemB) == 0)
					{
						if (comparando->comparar(**itemA, **itemB) > 0)
						{
							T* aux = *itemA;
							*itemA = *itemB;
							*itemB = aux;
						}
					}
				r = r->next;
			}

			// Swap Data
			T* x = temp->item;
			temp->item = min->item;
			min->item = x;
			temp = temp->next;
		}
		return this;
	}
	void Shell(T valores[], int n)
	{
		for (int gap = n / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < n; i++)
			{
				int Temp = valores[i];
				int j;
				for (j = i; j >= gap && valores[j - gap] > Temp; j -= gap)
					valores[j] = valores[j - gap];
				valores[j] = Temp;
			}
		}
	}

};


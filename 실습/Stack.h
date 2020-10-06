#include "LinkedList.h"

template <class T>
class Stack : public LinkedList<T> {
	public:
		virtual bool Delete(T &element);
};

template <class T>
bool Stack<T>::Delete(T &element) {
	if(this->first == 0) return false;

	Node<T> *tmp = this->first;
	this->first = this->first->link;

	element = tmp->data;
	delete tmp;

	this->current_size--;

	return true;
}

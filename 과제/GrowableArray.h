#include "Array.h"

template <class T>
class GrowableArray : public Array<T> {
	public:
		GrowableArray(int);
		~GrowableArray();

		T& operator[](int);
		T operator[](int)const;
};

template <class T>
GrowableArray<T>::GrowableArray(int size):Array<T>(size) {
}

template <class T>
GrowableArray<T>::~GrowableArray() {
}

template <class T>
T& GrowableArray<T>::operator[](int i) {
	int size = Array<T>::length();
	if(i >= size) {
		int j;
		T *temp = new T[size*2];
		for(j = 0; j < size; j++) {
			temp[j] = this->data[j];
		}

		for(; j < size*2; j++) {
			temp[j] = 0;
		}

		this->data = temp;
		this->len = size*2;
	//	delete(temp);
	}
	Array<T>::operator[](i);
}

template <class T>
T GrowableArray<T>::operator[](int i) const {
	int size = Array<T>::length();
	if(i >= size) {
		int j;
		T *temp = new T[size*2];
		for(j = 0; j < size; j++) {
			temp[j] = this->data[j];
		}
		for(; j < size*2; j++) {
			temp[j] = 0;
		}
		this->data = temp;
		this->len = size*2;
	//	delete(temp);
	}
	Array<T>::operator[](i);
}

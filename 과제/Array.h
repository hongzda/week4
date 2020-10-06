#include <iostream>
using namespace std;

#ifndef __ARRAY__
#define __ARRAY__

template <class T>
class Array {
	protected:
		T *data;
		int len;
	public:
		Array(int size);
		~Array() {delete(data);}

		int length() const {return len;}

		T& operator[](int i);
		T operator[](int i)const;

		void print() {
			int i;
			cout << "[";
			for(i = 0; i < len; i++) {
				cout << " " <<  data[i];
			}
			cout << "]" << endl;
		}
};

template <class T>
Array<T>::Array(int size) {
	if(size <= 0) {
		cout << "Error: size must be greater than zero" << endl;
	}
	data = new T[size];
	len = size;
}

template <class T>
T& Array<T>::operator[](int i) {
	static T tmp;
	if(i < 0 || i >= len) {
		cout << "Array bound error!" << endl;
		return tmp;
	}
	else return data[i];
}

template <class T>
T Array<T>::operator[](int i) const {
	if(i < 0 || i >= len) {
		cout << "Array bound error!" << endl;
		return 0;
	}
	else return data[i];
}

#endif

#ifndef PTRARRAY_H
#define PTRARRAY_H

const int ARRAY_START_SIZE = 100;

template<typename T>
class PtrArray{
public:
	PtrArray();
	~PtrArray();
	void Add(T&);
	void RemoveAt(int);
	T *operator[](int);
	T *Get(int);
	int GetSize();
	void EmptyArray();
private:
	T **data;
	int size;
	int max_size;
};

#include "PtrArray.template"

#endif
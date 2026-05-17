#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0)
{
	_copy(other);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{		delete[] _array;
		_copy(other);
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfRangeException();
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfRangeException();
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>void Array<T>::_copy(const Array& other)
{
	_size = other._size;
	_array = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

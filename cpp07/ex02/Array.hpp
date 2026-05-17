#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T> class Array
{
	private:
		T* _array;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();

		Array& operator=(const Array& other);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const;

	private:
		void _copy(const Array& other);

	class OutOfRangeException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{	return "Index out of range"; }
	};
};

#endif

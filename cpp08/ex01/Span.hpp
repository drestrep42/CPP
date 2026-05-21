#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>

class Span
{
	private:
		std::vector<int> _numbers;
		unsigned int _maxSize;

	public:
		Span();
		Span(unsigned int n);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int n);

		int shortestSpan();
		int longestSpan();
		
		template <class it>
        void addMultipleNumbers(it first, it last) {
            typedef typename std::iterator_traits<it>::difference_type diff_t;
        	diff_t d = std::distance(first, last);
        	if (d < 0)
        	    throw std::runtime_error("Invalid range");
        	std::vector<int>::size_type need = static_cast<std::vector<int>::size_type>(d);
        	std::vector<int>::size_type max = static_cast<std::vector<int>::size_type>(_maxSize);
        	if (_numbers.size() + need > max)
        	    throw std::runtime_error("Adding these numbers would exceed Span capacity");
        	_numbers.insert(_numbers.end(), first, last);
        }

};

#endif

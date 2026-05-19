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
			while (first != last) {
				if (_numbers.size() == _maxSize)
					throw std::runtime_error("Adding these numbers would exceed Span capacity");
				_numbers.insert(_numbers.end(), first, last);
				first++;
			}
		}

};

#endif

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
		~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		void addMultipleNumbers(const std::vector<int>& numbers);
};

#endif

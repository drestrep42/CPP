#include "Span.hpp"

Span::Span() : _maxSize(0) {
	std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _maxSize(n) {
	std::cout << "Parameterized constructor called" << std::endl;
}

Span::~Span() {
	std::cout << "Destructor called" << std::endl;
}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
	{
		throw std::runtime_error("Span is full");
	}
	_numbers.push_back(n);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
	{
		throw std::runtime_error("Not enough numbers");
	}
	std::vector<int> copy = _numbers;
	std::sort(copy.begin(), copy.end());

	int minSpan = copy[1] - copy[0];

	for (size_t i = 1; i < copy.size(); ++i) {
		int span = copy[i] - copy[i - 1];
		if (span < minSpan)
			minSpan = span;
	}

	return (minSpan);
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
	{
		throw std::runtime_error("Not enough numbers");
	}
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

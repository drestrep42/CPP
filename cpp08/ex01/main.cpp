#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(20);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << std::endl;
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	sp.addNumber(42);

	return 0;
}

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/* int main() {

	Span sp(8001);
	std::srand(std::time(NULL));
	int v[10000];
	// std::vector<int> v(10000);

	for (int i = 0; i < 10000; ++i) {
		int a = rand() % 100000;
		v[i] = a;
	}

	sp.addMultipleNumbers(v, v + 8000);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;



	return 0;
} */

int main()
{
	Span sp = Span(10);
	std::srand(std::time(NULL));

	sp.addNumber(8);
	sp.addNumber(3);
	sp.addNumber(20);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << std::endl;
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	try {
		sp.addNumber(42);
	} catch(const std::exception& e) {
		std::cerr << "Error adding number: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	Span sp2 = Span(10001);

	std::vector<int> v(100000);

	for (int i = 0; i < 100000; ++i) {
		int a = rand() % 2000000;
		v[i] = a;
	}

	
	try {
		sp2.addMultipleNumbers(v.begin(), v.begin() + 10000);
	} catch (const std::exception& e) {
		std::cerr << "Error adding multiple numbers: " << e.what() << std::endl;
	}
	std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
	std::cout << std::endl;
	return 0;
}

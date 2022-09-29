#include "Span.hpp"
#include <exception>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	{
		std::cout << "==== SIMPLE TEST : Add range ====" << std::endl;
		int	value[] = { 1, 285, 32, 49, 512 };
		std::vector<int> vec(value, &value[5]);
		Span sp = Span(5);

		try {
			sp.addRange(vec.begin(), vec.end());
		
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		std::cout << "==== SIMPLE TEST #2 ====" << std::endl;
		Span sp = Span(5);

		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		std::cout << "==== BIG TEST: 10 000 values ====" << std::endl;

		Span sp = Span(10000);
		for (int i = 0; i < 10000; i++) {
			try {
				sp.addNumber(rand() % 5000000);
			} catch (std::exception &e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "==== BIG TEST: 500 000 values ====" << std::endl;

		Span sp = Span(500000);
		for (int i = 0; i < 500000; i++) {					
			try {
				sp.addNumber(rand() % 5000000);
			} catch (std::exception &e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "==== ONE NUMBER ====" << std::endl;
		Span sp = Span(1);
		try {
			sp.addNumber(255);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	return 0;
}

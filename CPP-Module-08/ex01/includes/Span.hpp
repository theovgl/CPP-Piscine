#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <numeric>
# include <algorithm>

class Span
{
	public:
		Span(void);
		Span(unsigned int max);
		~Span();

		void	addNumber(int toAdd);
		int		shortestSpan();
		int		longestSpan();
		void	addRange(std::vector<int>::iterator, std::vector<int>::iterator);

	private:
		unsigned int		_max;
		std::vector<int>	_array;
};

#endif

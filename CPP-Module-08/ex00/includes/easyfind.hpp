#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator res = std::find(container.begin(), container.end(), value);
	
	if(res == container.end())
		throw std::exception();
	return res;
}

#endif

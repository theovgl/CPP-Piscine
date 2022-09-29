#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>

template<typename T>
void iter(T* array, unsigned int size, void (*f)(const T&))
{
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}

template<typename T>
void iter(T* array, unsigned int size, void (*f)(T&))
{
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}

#endif

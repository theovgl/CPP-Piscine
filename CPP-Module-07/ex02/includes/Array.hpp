#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array {
	public:
		Array<T>(void):
			_array(NULL),
			_size(0)
		{
		}

		Array<T>(unsigned int n)
		{
			this->_array = new T[n];
			this->_size = n;
		}

		Array (Array<T> const &rhs)
		{
			this->_size = rhs._size;
			this->_array = new T[_size];
			for (size_t i = 0; i < rhs._size; i++)
			{
				_array[i] = rhs._array[i];
			}
		}

		Array<T>& operator= (Array<T> const &rhs)
		{
			if (this->_array != NULL)
				delete []_array;
			this->_size = rhs._size;
			this->_array = new T[_size];
			for (size_t i = 0; i < rhs._size; i++)
			{
				_array[i] = rhs._array[i];
			}
			return (*this);
		}

		~Array<T>(void) {
			if (this->_array != NULL)
				delete []_array;
		}

		T	&operator[](unsigned int const i) const
		{
			if (i < 0|| i >= this->_size)
			{
				throw std::out_of_range("Error: out of range");
			}
			return (this->_array[i]);
		}

		unsigned int size(void) {
			return this->_size;
		}

	private:
		unsigned int	_size;
		T				*_array;
};

#endif

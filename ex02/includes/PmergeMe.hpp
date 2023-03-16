#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <cstdlib>
# include <iostream>
# include <list>
# include <vector>
# include <iterator>
# include <ctime>
# include <typeinfo>
# include <iomanip>
# include <cstring>

template<class Container>
class PmergeMe
{
	public:
		// === TYPES ===
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		// === CONSTRUCTOR / DESTRUCTOR===
		PmergeMe<Container>()
		{
			_find_type();
		}

		~PmergeMe<Container>()
		{}

		// === MEMBERS FUNCTIONS ===
		void fill_container(const char** input)
		{
			for (size_t i = 1; input[i]; i++) {
				if (_check_input_error(input[i]) == false) {
					throw BadCharacter();
				}
				_container.push_back( std::atoi(input[i]) );
			}
		}

		void print(bool sorted) const
		{
			const_iterator it = _container.begin();

			if (!sorted)
				std::cout << "Before:";
			else
				std::cout << "After:";
			for (; it != _container.end(); ++it) {
				std::cout << " " << *it;
			}
			std::cout << std::endl;
		}

		void print_time() const
		{
			std::cout 
				<< "Time to process a range of "
				<< _container.size()
				<< " elements with std::"
				<< _type_name << " : "
				<< _time_elapsed << " us"
				<< std::endl;
		}

		void compute()
		{
			clock_t start_time = clock();

			_container = _merge_insert_sort(_container);
			clock_t end_time = clock();
			_time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000000.00;
		}

		// === EXCEPTIONS ===
		class BadCharacter : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: bad character";
				}
		};

	private:
		float		_exec_time;
		Container	_container;
		std::string	_type_name;
		double		_time_elapsed;

		bool		_check_input_error(const char *to_check)
		{
			for (size_t i = 0; to_check[i]; i++) {
				if( !isdigit(to_check[i]) )
					return false;
			}
			return true;
		}

		void		_find_type()
		{
			const char* type_name = typeid(_container).name();
			
			if (strstr(type_name, "vector") != NULL) {
				_type_name = "vector";
			} else if (strstr(type_name, "list") != NULL) {
				_type_name = "list";
			} else if (strstr(type_name, "deque") != NULL) {
				_type_name = "deque";
			}
		}

		Container	_merge_insert_sort(Container input)
		{
			if (input.size() <= 1)
				return input;

			iterator middle_it = input.begin();
			std::advance(middle_it, input.size() / 2);
			Container	left(input.begin(), middle_it);
			Container	right(middle_it, input.end());
			Container	ret;

			if (left.size() <= 10)
				left = _insertion_sort(left);
			else
				left = _merge_insert_sort(left);

			if (right.size() <= 10)
				right = _insertion_sort(right);
			else
				right = _merge_insert_sort(right);

			return _merge(left, right);
		}

		Container	_merge(Container left, Container right)
		{
			Container ret;

			while (left.size() > 0 || right.size() > 0) {
				if (left.size() > 0 && right.size() > 0) {
					if (left.front() <= right.front()) {
						ret.push_back(left.front());
						left.erase(left.begin());
					}
					else {
						ret.push_back(right.front());
						right.erase(right.begin());
					}
				} else if (left.size() > 0) {
					ret.push_back(left.front());
					left.erase(left.begin());
				} else if (right.size() > 0) {
					ret.push_back(right.front());
					right.erase(right.begin());
				}
			}
			return ret;
		}

		Container	_insertion_sort(Container input)
		{
			for (iterator it = input.begin(); it != input.end(); it++) {
				iterator it2 = it;
				while (it2 != input.begin() && *it2 < *(--it2)) {
					std::swap(*++it2, *(--it2));
				}
			}
			return input;
		}
};

#endif

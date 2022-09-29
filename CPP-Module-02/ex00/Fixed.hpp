#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int _nb;
		static const int _bits;

	public:
		Fixed(void); // Default constructor
		Fixed(Fixed const & src); // Copy constructor
		~Fixed(void); // Destructor
		Fixed& operator=(Fixed const & rhs); // Affectation operator

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif

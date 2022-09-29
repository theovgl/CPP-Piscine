#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>
class Fixed
{
	private:
		int _nb;
		static const int _bits;

	public:
		Fixed(void); // Default constructor
		Fixed(const int);
		Fixed(const float);
		Fixed(Fixed const & src); // Copy constructor
		~Fixed(void); // Destructor
		Fixed& operator=(Fixed const & rhs); // Affectation operator

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream& operator<<(std::ostream & output, Fixed const & rhs);

#endif

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

		// Comparaison
		bool operator>(Fixed const & rhs);
		bool operator<(Fixed const & rhs);
		bool operator>=(Fixed const & rhs);
		bool operator<=(Fixed const & rhs);
		bool operator==(Fixed const & rhs);
		bool operator!=(Fixed const & rhs);

		// Arithmétique
		Fixed operator+(Fixed const & rhs);
		Fixed operator-(Fixed const & rhs);
		Fixed operator*(Fixed const & rhs);
		Fixed operator/(Fixed const & rhs);

		// Incrémentation / Décrémentation
		Fixed& operator++(void); // Prefix
		Fixed operator++(int); // Postfix
		Fixed& operator--(void); // Prefix
		Fixed operator--(int); // Postfix

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;

		static Fixed & min(Fixed & nb1, Fixed & nb2);
		static Fixed const & min(Fixed const & nb1, Fixed const & nb2);
		static Fixed & max(Fixed & nb1, Fixed & nb2);
		static Fixed const & max(Fixed const & nb1, Fixed const & nb2);
};

std::ostream& operator<<(std::ostream & output, Fixed const & rhs);

#endif

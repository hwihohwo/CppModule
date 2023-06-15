#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class ostream;

class Fixed
{
	private:
		int num;
		static const int bit_width = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed& operator = (const Fixed& obj);
		~Fixed();
		Fixed(const int num);
		Fixed(const float num);
		float toFloat( void ) const;
		int toInt( void ) const;
		static int ft_pow_(const int num, const int pow);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		static int getBitWidth(void);
};

std::ostream& operator <<(std::ostream&, const Fixed&);

#endif
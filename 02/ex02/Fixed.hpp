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
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();

		Fixed& operator = (const Fixed& obj);
		bool operator > (const Fixed& obj);
		bool operator < (const Fixed& obj);
		bool operator >= (const Fixed& obj);
		bool operator <= (const Fixed& obj);
		bool operator == (const Fixed& obj);
		bool operator != (const Fixed& obj);
		Fixed operator + (const Fixed& obj);
		Fixed operator - (const Fixed& obj);
		Fixed operator * (const Fixed& obj);
		Fixed operator / (const Fixed& obj);
		Fixed& operator ++();
		Fixed operator ++(int);
		Fixed& operator --();
		Fixed operator --(int);

		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		static int ft_pow_(const int num, const int pow);
		static int getBitWidth(void);
		static Fixed& min(Fixed& num1, Fixed& num2);
		static const Fixed& min(const Fixed& num1, const Fixed& num2);
		static Fixed& max(Fixed& num1, Fixed& num2);
		static const Fixed& max(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator <<(std::ostream&, const Fixed&);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:24:41 by imontero          #+#    #+#             */
/*   Updated: 2023/12/17 22:07:48 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fract = 8;
			
	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed(void);
		
		Fixed	(const Fixed &copy);
		
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const val);
		
		Fixed &	operator =(Fixed const &inst2);
		
		//comparison operators
		bool	operator >(const	Fixed &inst2);
		bool	operator <(const	Fixed &inst2);
		bool	operator >=(const	Fixed &inst2);
		bool	operator <=(const	Fixed &inst2);
		bool	operator ==(const	Fixed &inst2);
		bool	operator !=(const	Fixed &inst2);

		//arithmetic operators
		Fixed	operator +(const Fixed& inst2) const;
		Fixed	operator -(const Fixed& inst2) const;
		Fixed	operator *(const Fixed& inst2) const;
		Fixed	operator /(const Fixed& inst2) const;

		//increment / decrement operators
		Fixed&	operator++();		// pre-increment
		Fixed	operator++(int);	// post-increment
		Fixed&	operator--();		// pre-decrement
		Fixed	operator--(int);	// post-decrement

		// max/min overloaded methods
		static const Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
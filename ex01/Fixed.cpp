/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:22:29 by imontero          #+#    #+#             */
/*   Updated: 2023/12/17 21:14:06 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called with 0" << std::endl;
}

/* 
	int constructor 
	not used an intialization list for clarity
	initialize the fixed instance with an int
	left shift _fract (8 bits)  
	same as multipling by 2^8
*/
Fixed::Fixed(const int i)
{
	this->_value = i << this->_fract;
	std::cout << "Int constructor called" << std::endl;
}

/*
	float constructor
	not used an intialization list for clarity
	initialize the fixed instance with a float
	left shift _fract (8 bits)  
	same as multipling by 2^8
*/
Fixed::Fixed(const float f)
{
	this->_value = static_cast<int>(roundf(f * (1 << this->_fract)));
	std::cout << "Float constructor called" << std::endl;
}

//Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed &inst)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = inst;
}

//Assignation operator overload
Fixed &	Fixed::operator=(Fixed const &inst)
{
	std::cout << "Assigment operator called" << std::endl;
	this->_value = inst.getRawBits();
	return (*this);
}

/* 
	opposite to what the float contructor does
	converts the fixed to int (divides by 2^8)
*/
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << this->_fract));
}

/* 
	opposite to what the int contructor does
	converts the fixed to int (divides by 2^8)
*/
int		Fixed::toInt(void) const
{
	return (this->_value >> this->_fract);
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const val)
{
	this->_value = val;
}

std::ostream & operator <<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
    return (os);
}




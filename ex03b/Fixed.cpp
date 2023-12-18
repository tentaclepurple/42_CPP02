/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:22:29 by imontero          #+#    #+#             */
/*   Updated: 2023/12/18 13:37:20 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(void): _value(0)
{
	//std::cout << "Default constructor called with 0" << std::endl;
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
	setRawBits(i * (1 << this->_fract));
	//this->_value = i << this->_fract;
	//std::cout << "Int constructor called " << this->_value << std::endl;
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
	setRawBits(roundf(f * (1 << this->_fract)));
	//this->_value = static_cast<int>(roundf(f * (1 << this->_fract)));
	//std::cout << "Float constructor called " << this->_value << std::endl;
}

//Destructor
Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed &inst)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = inst;
}

//Assignation operator overload
Fixed &	Fixed::operator=(const Fixed  &inst)
{
	//std::cout << "Assigment operator called" << std::endl;
	//setRawBits(inst.getRawBits());
	/*if (this != &inst)
		this->_value = inst.getRawBits();*/
	this->_value = inst.getRawBits();
	return (*this);
}

/* 
	opposite to what the float contructor does
	converts the fixed to int (divides by 2^8)
*/
float	Fixed::toFloat(void) const
{
	return (roundf(getRawBits()) / (1 << this->_fract));
	//return (static_cast<float>(this->_value) / (1 << this->_fract));
}

/* 
	opposite to what the int contructor does
	converts the fixed to int (divides by 2^8)
*/
int		Fixed::toInt(void) const
{
	return (this->_value / (1 << this->_fract));
	//return (this->_value >> this->_fract);
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const val)
{
	this->_value = val;
}

//comparison operators
bool	Fixed::operator >(const	Fixed &inst2)
{
	return (this->toFloat() > inst2.toFloat());
}

bool	Fixed::operator <(const	Fixed &inst2)
{
	return (this->toFloat() < inst2.toFloat());
}

bool	Fixed::operator >=(const	Fixed &inst2)
{
	return (this->toFloat() >= inst2.toFloat());
}

bool	Fixed::operator <=(const	Fixed &inst2)
{
	return (this->toFloat() <= inst2.toFloat());
}

bool	Fixed::operator ==(const	Fixed &inst2)
{
	return (this->toFloat() == inst2.toFloat());
}

bool	Fixed::operator !=(const	Fixed &inst2)
{
	return (this->toFloat() != inst2.toFloat());
}

//arithmetic operators

Fixed	Fixed::operator +(const Fixed& inst2) const
{
	/*Fixed	temp;

	temp.setRawBits((this->getRawBits() + inst2.getRawBits()) / (1 << this->_fract));
	return (temp);*/
	return (this->toFloat() + inst2.toFloat());
}

Fixed	Fixed::operator -(const Fixed& inst2) const
{
	/*Fixed	temp;

	temp.setRawBits((this->getRawBits() - inst2.getRawBits()) / (1 << this->_fract));
	return (temp);*/
	return (this->toFloat() - inst2.toFloat());
}

Fixed	Fixed::operator *(const Fixed& inst2) const
{
	/*Fixed	temp;

	temp.setRawBits((this->getRawBits() * inst2.getRawBits()) / (1 << this->_fract));
	return (temp);*/
	return (this->toFloat() * inst2.toFloat());
}

Fixed	Fixed::operator /(const Fixed& inst2) const
{
	/*Fixed	temp;

	temp.setRawBits((roundf(this->getRawBits()) / inst2.getRawBits()) * (1 << this->_fract));
	return (temp);*/
	return (this->toFloat() / inst2.toFloat());
}

//increment / decrement operators

/* 
	1 increments the _value
	2 returns a reference to the actual object
	after the increment
*/
Fixed &	Fixed::operator ++()		// pre-increment
{
	++this->_value;
	return (*this);
}

/* 
	1 create a copy of the actual object (via copy constructor)
	2 increments the value of the actual object
	3 returns a the copy of object that hasn´t been incremented
*/
Fixed	Fixed::operator ++(int)
{
	Fixed	tmp(*this);				//post-increment
	
	++this->_value;
	return (tmp);
}

Fixed &	Fixed::operator --()		// pre-decrement
{
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator --(int)
{
	Fixed	tmp(*this);				//post-decrement
	
	--this->_value;
	return (tmp);
}

// max/min overloaded static methods

/* 
	ternary operator
	is a less than b? 
	if so return a
	otherwise return b
*/
const Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

//insertion operator overload
std::ostream & operator <<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
    return (os);
}




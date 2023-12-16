/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:22:29 by imontero          #+#    #+#             */
/*   Updated: 2023/12/16 11:36:04 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called with 0" << std::endl;
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
	std::cout << "Assigment operator called from " << this->_value;
	std::cout << " to " << inst.getRawBits() << std::endl;
	this->_value = inst.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	std::cout << this->_value << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const val)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = val;
}





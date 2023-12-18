/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:30:50 by imontero          #+#    #+#             */
/*   Updated: 2023/12/18 13:58:01 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(0), y(0){}

Point::Point(float const value1, float const value2): x(value1), y(value2) {};


Point::Point(const Point& other): x(other.getPosX()), y(other.getPosY()){};

Point &Point::operator=(Point const &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    return *this;
};

Point::~Point(void)
{
    //std::cout << "Destructor called" << std::endl;
};

Fixed Point::getPosX(void) const {
    return x;
}

Fixed Point::getPosY(void) const {
    return y;
}

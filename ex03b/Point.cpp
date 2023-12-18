/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:30:50 by imontero          #+#    #+#             */
/*   Updated: 2023/12/18 13:40:08 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}

Point::~Point(void)
{
}

Point::Point(const Point &inst): _x(inst.getX()), _y(inst.getY())
{
	*this = inst;
}

Point & Point::operator =(const Point &inst2)
{
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

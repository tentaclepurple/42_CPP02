/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:31:03 by imontero          #+#    #+#             */
/*   Updated: 2023/12/18 13:39:34 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <string>

class Point
{
	private:
		const Fixed	 _x;
		const Fixed	 _y;

	public:
		Point(void);
		Point(const float x, const float y);
		~Point(void);
		
		Point (const Point &copy);
		
		Point & operator = (const Point &inst2);
		
		Fixed	getX(void) const;
		Fixed	getY(void) const;
		
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
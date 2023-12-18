/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:10:53 by imontero          #+#    #+#             */
/*   Updated: 2023/12/18 12:54:49 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
	Returns true if the point is inside the triangle false if its outside
	or if point is in vertex or edge
	
*/
/*bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed u, v, w;

    // barycentric coordinates
    Fixed D = (b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY());

    u = ((point.getY() - c.getY()) * (b.getX() - c.getX()) + (c.getX() - point.getX()) * (b.getY() - c.getY())) / D;
    v = ((point.getY() - a.getY()) * (c.getX() - a.getX()) + (a.getX() - point.getX()) * (c.getY() - a.getY())) / D;
    w = Fixed(1) - u - v;

    // Verifies if the point is inside the triangle
    if (u >= 0 && u <= 1 && v >= 0 && v <= 1 && w >= 0 && w <= 1) {
        // Verifies if the point is vertex or edge
        if (u == 0 || u == 1 || v == 0 || v == 1 || w == 0 || w == 1) {
            return (false);
        }
        return (true);
    }
    return (false);
}*/

/*Fixed	getArea( Point const point, Point const a, Point const b, Point const c )
{
	(void)point;
	Fixed const ret ( (Fixed)(0.5f * (-(b.getY().toFloat()) * c.getX().toFloat() + a.getY().toFloat() * (-(b.getX().toFloat()) + c.getX().toFloat()) + a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + b.getX().toFloat() * c.getY().toFloat())));
	std::cout << "area ret: " << ret << std::endl;
	return (ret);
}

Fixed	getS( Fixed area, Point const point, Point const a, Point const c )
{
	Fixed	ret ( (Fixed) 1.00f /( Fixed (2) * area) * (a.getY() * c.getX() - a.getX() * c.getY() + (c.getY() - \
	a.getY()) * point.getX() + (a.getX() - c.getX()) * point.getY()));
	std::cout << "s ret: " << ret << std::endl;
	return (ret);
}

Fixed	getT( Fixed area, Point const point, Point const a, Point const b )
{
	Fixed	ret( (Fixed) 1.00f /( Fixed (2) * area) * (a.getX() * b.getY() - a.getY() * b.getX() + (a.getY() - \
	b.getY()) * point.getX() + (b.getX() - a.getX()) * point.getY()));
	std::cout << "t ret: " << ret << std::endl;
	return (ret);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed area = getArea( point, a, b, c );
	Fixed s = getS( area, point, a, c );
	Fixed t = getT( area, point, a, b );
	Fixed temp = ( Fixed(1) - s - t);

//	std::cout << "area: " << area << "	s: " << s << "	t: " << t << std::endl;

	if (((Fixed (0) < s ) && ( s < Fixed(1))) && ((Fixed(0) < t ) && ( t < Fixed(1))) && ((Fixed(0) < temp ) && (temp < Fixed(1))))
		return (true);
	return (false);
}*/

bool bsp( const Point  a, const Point  b, const Point  c, const Point  point)
{
    Point d((b.getX() - a.getX()), (b.getY() - a.getY()));
    Point e(c.getX() - a.getX(), c.getY() - a.getY());
    float w1 = (e.getX() * (a.getY() - point.getY()) + e.getY() * (point.getX() - a.getX())) / (d.getX() * e.getY() - d.getY() * e.getX());
    float w2 = (point.getY() - a.getY() - (w1 * d.getY())) / e.getY();

   return ((w1 > 0.0) && (w2 > 0.0) && ((w1 + w2) < 1.0));
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:10:53 by imontero          #+#    #+#             */
/*   Updated: 2023/12/18 14:02:21 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
	Returns true if the point is inside the triangle false if its outside
	or if point is in vertex or edge
	
*/

bool bsp( const Point  a, const Point  b, const Point  c, const Point  point)
{
    Point d((b.getPosX() - a.getPosX()), (b.getPosY() - a.getPosY()));
    Point e(c.getPosX() - a.getPosX(), c.getPosY() - a.getPosY());
    float w1 = (e.getPosX() * (a.getPosY() - point.getPosY()) + e.getPosY() * (point.getPosX() - a.getPosX())) / (d.getPosX() * e.getPosY() - d.getPosY() * e.getPosX());
    float w2 = (point.getPosY() - a.getPosY() - (w1 * d.getPosY().toFloat())) / e.getPosY().toFloat();

   return ((w1 > 0.0) && (w2 > 0.0) && ((w1 + w2) < 1.0));
}
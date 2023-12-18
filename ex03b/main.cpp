/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:03:12 by imontero          #+#    #+#             */
/*   Updated: 2023/12/18 13:09:29 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

void	printResult(int bsp)
{
	if (bsp == 0)
		std::cout  << "It's out of the triangle!"  <<  std::endl;
	else
		std::cout << "It's inside of the triangle!" << std::endl;
}

int	main()
{
	std::cout <<  "=== TEST1 ===" << std::endl;
	Point	a( 0 , 0 );
	Point	b( 5, 0 );
	Point	c( 0, 5 );
	Point	point( 1, 1);
	printResult(bsp(a, b, c, point));
	
	std::cout << (b.getY() - b.getY()) * (b.getX() - b.getX()) + (b.getX() - b.getX()) * (b.getY() - b.getY())  << std::endl;
	std::cout << b.getY() << std::endl;
	
	//Fixed D = (b.getY() - b.getY()) * (b.getX() - b.getX()) + (b.getX() - b.getX()) * (b.getY() - b.getY());
	//std::cout << D.getRawBits() << std::endl;


/*	std::cout << "=== TEST2 ==="  << std::endl;
	Point	d( 1, 2 );
	Point	e( -2, 6 );
	Point	f( 8, 10 );
	Point	point2( 8, 10 );

	printResult(bsp(d, e, f, point2));

	std::cout << "=== TEST3 ===" <<std::endl;
	Point	x( 1, 2 );
	Point	y( 5, 6 );
	Point	z( 8, 1 );
	Point	point3( -5, -5 );

	printResult(bsp(x, y, z, point3));

	return 0;*/
	

	//std::cout <<  << std::endl;

	std::cout << b.getX() << std::endl;
	std::cout << b.getY() << std::endl;

	return (0);
}

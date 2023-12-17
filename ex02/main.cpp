/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:03:12 by imontero          #+#    #+#             */
/*   Updated: 2023/12/18 00:47:37 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "----------------" << std::endl;
	std::cout << Fixed( 5.05f ) << std::endl;
	std::cout << Fixed( 2 ) << std::endl;
	std::cout << Fixed( 5.05f ) / Fixed( 0 ) << std::endl;
	
	std::cout << "----------------" << std::endl;
	std::cout << a << std::endl;
	
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << b.toFloat() << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}

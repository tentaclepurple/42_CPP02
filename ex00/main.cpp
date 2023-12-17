/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:03:12 by imontero          #+#    #+#             */
/*   Updated: 2023/12/17 00:07:27 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	std::cout << "\nFixed a;" << std::endl;
	Fixed a;
	
	std::cout << "\n---------------\n" << std::endl;
	
	std::cout << "\nFixed b( a );" << std::endl;
	Fixed b( a );
	std::cout << "\n---------------\n" << std::endl;

	std::cout << "\nFixed c;" << std::endl;
	Fixed c;
	
	std::cout << "\n---------------\n" << std::endl;
	
	std::cout << "\nc = b;" << std::endl;
	c = b;
	
	std::cout << "\n---------------\n" << std::endl;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	std::cout << "\n---------------\n" << std::endl;
return 0;
}

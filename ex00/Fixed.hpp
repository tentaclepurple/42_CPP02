/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:24:41 by imontero          #+#    #+#             */
/*   Updated: 2023/12/15 17:05:43 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fract = 8;
			
	public:
		Fixed(void);
		~Fixed(void);
		
		Fixed	(const Fixed &copy);
		Fixed &	operator=(Fixed const &inst2);
		
		int		getRawBits(void) const;
		void	setRawBits(int const val);
};

#endif
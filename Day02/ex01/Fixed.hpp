/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:30:21 by dmahlake          #+#    #+#             */
/*   Updated: 2018/06/07 17:09:22 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _pointVal;
		static int const _bitsNum = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const & ptr);
		Fixed(int const ptr_value);
		Fixed(float const ptr_value);
		float toFloat(void)const;
		int toInt(void)const;
		int getRawBits(void)const;
		void setRawBits(int const raw);
		Fixed & operator=( Fixed const & ref );
};

std::ostream & operator<<(std::ostream & o, Fixed const & ref);

#endif

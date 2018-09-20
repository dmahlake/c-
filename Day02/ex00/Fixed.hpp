/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 10:02:14 by dmahlake          #+#    #+#             */
/*   Updated: 2018/06/07 12:02:24 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
	private:
		int _ptr_value;
		static int const num = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const & ptr);
		Fixed & operator=(Fixed const & ref);
		int getRawBits(void)const;
		void setRawBits(int const raw);
};

#endif

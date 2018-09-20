/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 10:02:25 by dmahlake          #+#    #+#             */
/*   Updated: 2018/06/07 12:02:29 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_ptr_value = 0;
}

Fixed::Fixed( Fixed const & ptr )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ptr;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( Fixed const & ref )
{
	std::cout << "Assignation operator called" << std::endl;
	this->_ptr_value = ref.getRawBits();
	return *this;
}

}

int Fixed::getRawBits( void )const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_ptr_value;
}

void Fixed::setRawBits( int const raw )
{
	this->_ptr_value = raw;
}

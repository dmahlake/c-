/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:30:32 by dmahlake          #+#    #+#             */
/*   Updated: 2018/06/07 18:33:15 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_pointVal = 0;
}

Fixed::Fixed( Fixed const & ptr )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = ptr;
}
Fixed::Fixed(int const ptr_fix)
{
	std::cout << "Int constuctor called" << std::endl;
	this->_pointVal = ptr_fix << this->_bitsNum;
}

Fixed::Fixed(float const ptr_fix2)
{
	std::cout << "Float constructor called" << std::endl;
	this->_pointVal = (int)roundf(ptr_fix2 * (1 << this->_bitsNum));
}
    
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
    
Fixed & Fixed::operator=( Fixed const & ref )
{
    std::cout << "Assignation operator called" << std::endl;
    this->_pointVal = ref.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    return this->_pointVal;
}

void Fixed::setRawBits( int const raw )
{
    this->_pointVal = raw;
}

float Fixed::toFloat(void) const
{
	return(((float)this->_pointVal) / (1 << this->_bitsNum));
}

int Fixed::toInt(void) const
{
	return(this->_pointVal >>  this->_bitsNum);
}

bool Fixed::operator<( Fixed const & ref ) const
{	
	if (this->_pointval < ref._pointVal)
	{
		return true;
	}
	return false;
}

bool Fixed::operator>( Fixed const & ref ) const
{
	if (this->_pointVal > ref._pointVal)
	{
		return true;
	}
	return false;
}

bool Fixed::operator>=( Fixed const & ref ) const
{
	if (this->_pointVal >= ref._pointVal)
	{
		return true;
	}
	return false;
}

bool Fixed::operator<=( Fixed const & ref ) const
{
	if (this->_pointVal <= ref._pointVal)
	{
		return true;
	}
	return false;
}

bool Fixed::operator==( Fixed const & ref ) const
{
	if (this->_pointVal == ref._pointVal)
	{
		return true;
	}
	return false;
}

bool Fixed::operator!=( Fixed const & ref ) const
{
	if (this->_pointVal != ref._pointVal)
	{
		return true;
	}
	return false;
}

Fixed & Fixed::operator=( Fixed const & ref ) const
{
	if (this != &ref)
		this->_pointVal.ref;
	return *this;
}

Fixed & Fixed::operator+(Fixed const & ref ) const
{
	Fixed	*total = new Fixed();
	total->_pointVal = this->_pointVal + ref._pointVal;
	return (*total);
}

Fixed & Fixed::operator-(Fixed const & ref ) const
{
	Fixed *decre = new Fixed();
	decre->_pointVal = this->pointVal + ref.pointVal;
	return (*decre);
}

Fixed & Fixed::operator*(Fixed const & ref) const
{
	return (*new Fixed(this->toFloat() * ref.toFloat()));
}

Fixed & Fixed::operator/( Fixed const & ref ) const
{
	return (*new Fixed(this->toFloat() / ref.toFloat()));
}

Fixed &FIXED::operator++(void)
{
	this->pointVal++;
	return (*this);
}

Fixed &Fixed::operator++(int)
{
	Fixed *tyk = new Fixed(*this);
	operator++();
	return (*tyk);
}

Fixed &Fixed::operator--(void)
{
	this->pointVal--;
	return (*this);
}

Fixed & Fixed::operator--(int)
{
	return operator--();
}

std::ostream & operator<<(std::ostream & o, Fixed const & ref)
{
	o << ref.toFloat();
	return (o);
}

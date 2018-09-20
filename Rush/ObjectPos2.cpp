/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectPos2.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <fthwala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:44 by fthwala           #+#    #+#             */
/*   Updated: 2018/06/10 16:56:44 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObjectPos.hpp"

ObjectPos2::ObjectPos2() : y(0), x(0) {}

ObjectPos2::ObjectPos2(unsigned int y, unsigned int x) : y(y), x(x) {}

ObjectPos2::ObjectPos2(ObjectPos2 const & src) {
	*this = src;
}

ObjectPos2 & ObjectPos2::operator=(ObjectPos2 const & rhs) {
	if (this != &rhs) {
		y = rhs.y;
		x = rhs.x;
	}
	return *this;
}

ObjectPos2::~ObjectPos2() {}

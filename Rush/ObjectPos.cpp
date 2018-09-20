/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectPos.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <fthwala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:44 by fthwala           #+#    #+#             */
/*   Updated: 2018/06/10 16:56:28 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObjectPos.hpp"

ObjectPos::ObjectPos() : y(0), x(0) {}

ObjectPos::ObjectPos(int y, int x) : y(y), x(x) {}

ObjectPos::ObjectPos(ObjectPos const & src) {
	*this = src;
}

ObjectPos & ObjectPos::operator=(ObjectPos const & rhs) {
	if (this != &rhs) {
		y = rhs.y;
		x = rhs.x;
	}
	return *this;
}

ObjectPos::~ObjectPos() {}

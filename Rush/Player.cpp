/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <fthwala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:44 by fthwala           #+#    #+#             */
/*   Updated: 2018/06/10 16:56:52 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() : disp_char('o') {}

Player::Player(int y, int x) : pos(y, x), disp_char('>') {}

Player::Player(int y, int x, char c) : pos(y, x), disp_char(c) {}

Player::Player(Player const & src) {
	*this = src;
}

Player & Player::operator=(Player const & rhs) {
	if (this != &rhs) {
		disp_char = rhs.disp_char;
		pos = rhs.pos;
	}
	return *this;
}

Player::~Player() {}

void	Missiles::update() {
	for (size_t i = 0; i < object_count; i++) {
		if (object_set[i].isActive()) {
			if (object_set[i].getPos().x == field_bounds.width - 2)
				object_set[i].deactivate();
			object_set[i].updateToRight();
		}
	}
}

void	Missiles::activate(int p_x, int p_y) {	
	for (size_t i = 0; i < object_count; i++) {
		if (!object_set[i].isActive()) {
			object_set[i].activate(p_x, p_y);
			break;
		}
	}
}


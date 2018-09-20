/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObjectField.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <fthwala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:44 by fthwala           #+#    #+#             */
/*   Updated: 2018/06/10 16:55:55 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"

GameObjectField::GameObjectField() {
	object_count = 42;
	object_set = new GameObject[object_count];

}

GameObjectField::GameObjectField(GameObjectField const & src) {
	*this = src;
}

GameObjectField & GameObjectField::operator=(GameObjectField const & rhs) {
	if(this != &rhs) {
		this->field_bounds = rhs.getFieldBounds();
		this->object_set = rhs.getData();
		this->object_count = rhs.getCount();
	}
	return *this;
}

GameObjectField::~GameObjectField() {
	delete [] object_set;
}

size_t GameObjectField::update() {
	size_t score_mod = 0;
	//Update all active objects
	for (size_t i = 0; i < object_count; i++) {
	 if (object_set[i].isActive()) {
		 // + 2 for boarder
		 if (object_set[i].getPos().x < field_bounds.x + 2) {
			 object_set[i].deactivate();
			 score_mod++;
		 } else {
		 object_set[i].updateToLeft();
		 }
	 }
	}

	//Find inactive objects, activate them.
	if (arc4random() % 2 == 1) // wave sparcity
	{
		for (size_t i = 0; i < object_count; i++) {
			if (!object_set[i].isActive()) {
				if (arc4random() % 10 == 1) { // unit sparcity

					
					// Spawn @ at the far right
					object_set[i].activate(
					 (field_bounds.width - 2),
					 (arc4random() % (field_bounds.height - 4)) + 3);
				}
			}
		} //If we don't have inactive objects, so be it...
	}

	return score_mod;
}

void GameObjectField::setBounds(Rect r) {
	field_bounds = r;
}


//Reworked to avoid vector
size_t GameObjectField::getCount() const {
	return object_count;
}

GameObject* GameObjectField::getData() const {
	return object_set;
}

Rect GameObjectField::getFieldBounds() const {
	return field_bounds;
}

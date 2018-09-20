/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <fthwala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:44 by fthwala           #+#    #+#             */
/*   Updated: 2018/06/10 16:54:26 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

# include "ObjectPos.hpp"

#include <iostream>
#include <unistd.h>

class GameObject {

	public:
		GameObject();
		GameObject(GameObject const & src);
		GameObject & operator=(GameObject const & rhs);
		~GameObject();

		void	updateToLeft();
		void	updateToRight();
		void	activate(int nx, int ny);
		void	deactivate();
		bool	isActive() const; // gets active state 

		ObjectPos	getPos() const;
		void	setPos(ObjectPos const src);

	protected:
		char	object;
		ObjectPos	pos; /* instance of ObjectPos class */
		bool	active;
};

class GameObjectField
{
	public:
		GameObjectField();
		GameObjectField(GameObjectField const & src);
		GameObjectField & operator=(GameObjectField const & rhs);
		~GameObjectField();

		size_t			update();
		void			setBounds(Rect r);

		GameObject*		getData() const;
		size_t			getCount() const;
		Rect			getFieldBounds() const;

	protected:
		Rect			field_bounds;
		GameObject*		object_set;
		size_t			object_count;
};

#endif

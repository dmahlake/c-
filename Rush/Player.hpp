/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <fthwala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:44 by fthwala           #+#    #+#             */
/*   Updated: 2018/06/10 16:57:02 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "ObjectPos.hpp"
#include "GameObject.hpp"

class Player {
	public:
		ObjectPos		pos;
		char		disp_char;
		// Missiles	bullet;

		Player();
		Player(int y, int x);
		Player(int y, int x, char c);
		Player(Player const & src);
		Player & operator=(Player const & rhs);
		~Player();
};

class Missiles : public GameObjectField
{
	public:
		void	update();
		void	activate(int p_x, int p_y);
};


#endif

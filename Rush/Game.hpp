/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <fthwala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:44 by fthwala           #+#    #+#             */
/*   Updated: 2018/06/10 18:23:24 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <ncurses.h>
# include <string>
# include <ctime>

// # include "GameObjectField.hpp" // contains GameObject.hpp and Rect.hpp and Player.hpp
# include "Player.hpp" // has GameObjectField.hpp

class Game
{
	public:
		
		WINDOW*						main_window;
		WINDOW*						game_window;

		size_t						tick;
		size_t						score;
		std::time_t					start;

		Player						p1;
		GameObjectField				stars;
		Missiles					missiles;

		Game();
		Game(Game const & src);
		Game & operator=(Game const & rhs);
		~Game();

		int							run();
		void						init();
		bool						collisionHandler();	// returns true if collision is detected?
		void						shootStar();
		void						trailCleaner();
		void						print();
		void						controlHandler(int maxx, int maxy);
		int							gameOver(); // if collision detected puts Game Over screen

};

#endif

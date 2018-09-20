/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <fthwala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:44 by fthwala           #+#    #+#             */
/*   Updated: 2018/06/10 18:20:12 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

int main(void) {
 int run;
 Game *game = new Game;

 run = game->run();

 while (run == 1) {
 	delete game;
 	game = new Game();
 	run = game->run();
 }
 
 delete game;
 return (0);
}

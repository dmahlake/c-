/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <fthwala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:44 by fthwala           #+#    #+#             */
/*   Updated: 2018/06/10 18:40:39 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "GameObject.hpp"

Game::Game( void ) : main_window(initscr()), p1(13, 5) {  // init() and init player 1 
	cbreak();
	noecho();
	clear();
	refresh();

	tick = 0;
	score = 0;

	keypad(main_window, true); //interpret action keys, not escape sequences.
	nodelay(main_window, true); //disable wgetch blocking.
	curs_set(0); //make cursor invisible.

	/* the frame or boundary box */
	box(main_window, 0, 0);
}

Game::Game( Game const & src ) {
	*this = src;
}

Game & Game::operator=( Game const & rhs ) {
	if ( this != &rhs ) {
		this->main_window = rhs.main_window;
	}
	return *this;
}

Game::~Game( void ) {
	endwin();  /* End game */
}

bool	Game::collisionHandler() {
	int star_x, star_y;
	for (size_t i = 0; i < stars.getCount(); i++) {
		if (stars.getData()[i].isActive()) {
			star_x = stars.getData()[i].getPos().x;
			star_y = stars.getData()[i].getPos().y;
			if (star_x == p1.pos.x && star_y == p1.pos.y) {
				return true;
			}
		}
	}
	return false;
}

void	Game::shootStar() {
	int star_x, star_y;
	int	bull_x, bull_y;
	for (size_t i = 0; i < stars.getCount(); i++) {
		if (stars.getData()[i].isActive()) {
			star_x = stars.getData()[i].getPos().x;
			star_y = stars.getData()[i].getPos().y;
			for (size_t j = 0; j < missiles.getCount(); j++) {
				bull_x = missiles.getData()[j].getPos().x;
				bull_y = missiles.getData()[j].getPos().y;
				//Questionable checking...
				if ((star_x - 1 == bull_x && star_y == bull_y) 
					|| (star_x  == bull_x + 1 && star_y == bull_y)
					|| (star_x  == bull_x && star_y == bull_y)) {
					stars.getData()[i].deactivate();
					if (score < 1000)
						missiles.getData()[j].deactivate();
					// Give score for destroying @'s
					score += 10;
				}
			}
		}
	}
}

/* Game over is outputed to the destructer */
int	Game::gameOver() {
	int in_char;
	int maxy, maxx;
	getmaxyx(main_window, maxy, maxx);

	in_char = wgetch(main_window);
	attron(A_BOLD);
	// wbkgd(main_window, COLOR_PAIR(2));
	mvaddch(p1.pos.y, p1.pos.x, '>');

	move((maxy - 2), (2));
	printw("GAME OVER Press 'q' - quit or 'r' - restart ");

	while(1) {

		in_char = wgetch(main_window);
		if (in_char == 'q')
			return 0;
		if (in_char == 'r')
			return 1;
	}
}

void	Game::trailCleaner() {
	int star_x, star_y;
	for (size_t i = 0; i < stars.getCount(); i++) {
		if (stars.getData()[i].isActive()) {
			star_x = stars.getData()[i].getPos().x;
			star_y = stars.getData()[i].getPos().y;
			mvaddch(star_y, star_x, ' ');
		}
	}

	/* missiles */
	for (size_t i = 0; i < missiles.getCount(); i++) {
		if (missiles.getData()[i].isActive()) {
			star_x = missiles.getData()[i].getPos().x;
			star_y = missiles.getData()[i].getPos().y;
			if (star_x != p1.pos.x || star_y != p1.pos.y)
			 mvaddch(star_y, star_x, ' ');
		}
	}
}

void	Game::print() {
	int star_x, star_y;
	for (size_t i = 0; i < stars.getCount(); i++) {
		if (stars.getData()[i].isActive()) {
			star_x = stars.getData()[i].getPos().x;
			star_y = stars.getData()[i].getPos().y;
			mvaddch(star_y, star_x, '{');
		}
	}

	for (size_t i = 0; i < missiles.getCount(); i++) {
		if (missiles.getData()[i].isActive()) {
			star_x = missiles.getData()[i].getPos().x;
			star_y = missiles.getData()[i].getPos().y;
			if (star_x != p1.pos.x || star_y != p1.pos.y)
			{
				if (score > 1000)
					mvaddch(star_y, star_x, '=');	
				else
					mvaddch(star_y, star_x, '*');
			}
		}
	}
	//Show score!
	move (1, 2);
	attron(A_BOLD);
	addstr("POINTS: ");
	move (1, 9);
	std::string text = std::to_string(score);
	for (size_t i = 0; i < text.size(); i++) {
		addch(text[i]);
		refresh();
	}

	//Time
	move (2, 2);
	attron(A_BOLD);
	addstr("TIME: ");
	move (2, 9);
	std::string time = std::to_string(static_cast<long int>(std::difftime(std::time(NULL), start)));
	for (size_t i = 0; i < time.size(); i++) {
		addch(time[i]);
		refresh();
	}
	attroff(A_BOLD);
}

void Game::controlHandler(int maxx, int maxy) {
	int in_char;
	in_char = wgetch(main_window);

	mvaddch(p1.pos.y, p1.pos.x, ' ');

	if (in_char == 'q' || in_char == 27)
	{
		endwin();
		std::exit(0);
	}
	else if (in_char == ' ')
		missiles.activate(p1.pos.x, p1.pos.y);
	else if ((in_char == KEY_UP) && p1.pos.y > 3)
		p1.pos.y--;
	else if ((in_char == KEY_DOWN) && p1.pos.y < maxy - 2)
		p1.pos.y++;
	else if ((in_char == KEY_LEFT) && p1.pos.x > 1)
		p1.pos.x--;
	else if ((in_char == KEY_RIGHT) && p1.pos.x < maxx - 2)
		p1.pos.x++;
}


int	Game::run() {

	int maxy, maxx;  /* Window coordinates */
	int star_x, star_y;

	getmaxyx(main_window, maxy, maxx); /* Get Window coordinates */

	// init rect with 0,0 origin and width and height
	Rect draw_box(4, 0, maxy, maxx);
	stars.setBounds(draw_box);
	missiles.setBounds(draw_box);

	//stars.getData()[13].activate(32,13);

	//Start time
	start = std::time(NULL);

	//Player 

	while(42)
	{
		tick++;
	 	// Collision detection here
		if (collisionHandler() == true)
			return gameOver();

		shootStar();
		trailCleaner(); // Cleaning up trails for chars

		size_t score_mod;

		if (tick > 42) {
			score_mod = stars.update();
			if (score_mod <= score)
				score -= score_mod;
		}
		
		missiles.update();

		print();

		controlHandler(maxx, maxy);

		mvaddch(p1.pos.y, p1.pos.x, p1.disp_char);

		if (tick < 3000)
			usleep(42000 - tick * 10);

		refresh();
	}
	return 0;
}


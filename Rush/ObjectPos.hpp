/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectPos.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthwala <fthwala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:50:44 by fthwala           #+#    #+#             */
/*   Updated: 2018/06/10 16:56:35 by fthwala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTPOS_H
# define OBJECTPOS_H

class ObjectPos {
	public:
		int	y;
		int	x;

		ObjectPos();
		ObjectPos(int y, int x);
		ObjectPos(ObjectPos const & src);
		ObjectPos & operator=(ObjectPos const & rhs);
		~ObjectPos();
};

class ObjectPos2 {
	public:
		unsigned int	y;
		unsigned int	x;

		ObjectPos2();
		ObjectPos2(unsigned int y, unsigned int x);
		ObjectPos2(ObjectPos2 const & src);
		ObjectPos2 & operator=(ObjectPos2 const & rhs);
		~ObjectPos2();
};

class Rect {
	public:
		int y;
		int x;
		int height; // max Y
		int width;  // max X

		Rect(); // sets all to 0
		Rect(int height, int width); // sets y and x to 0
		Rect(int y, int x, int height, int width); // can have a different origin point
		Rect(Rect const & src);
		Rect & operator=(Rect const & rhs);
		~Rect();
};

#endif
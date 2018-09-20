/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:15:22 by dmahlake          #+#    #+#             */
/*   Updated: 2018/06/13 15:28:07 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include <ctype.h>
#include <limits>
#include <float.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <cstring>

int		main (int argc, char** argv) {
	std::string str;
	if (argc != 2) {
		std::cout << "Error convert to a string";
		return (0);
	}
	str = argv[1];
    int checkfloat = str.find("f");
	int checkdouble = str.find(".");
	long int 	checkint = atol(str.c_str());
	double 		myfloat = atof(str.c_str());
	if (strcmp(str.c_str(), "nan") == 0 || strcmp(str.c_str(), "nanf") == 0 ) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return (0);
	}
	if (strcmp(str.c_str(), "+nan") == 0 || strcmp(str.c_str(), "+nanf") == 0 ) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
		return (0);
	}
	if (strcmp(str.c_str(), "-nan") == 0 || strcmp(str.c_str(), "-nanf") == 0 ) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
		return (0);
	}
	if (str.length() == 1 && !isdigit(str.at(0)) && isprint(str.at(0))) {
		std::cout << "char: " << "'" << str.at(0) << "'\n";
		std::cout << "int: " << static_cast<int>(str.at(0)) << std::endl;
		std::cout << "float: " << static_cast<float>(str.at(0)) << "f\n";
		std::cout << "double: " << static_cast<double>(str.at(0)) << std::endl;
		return (0);
	}
	

	if (checkint != 0 && checkint <= INT_MAX && checkint >= INT_MIN) {
		if ( isprint(checkint) )
			std::cout << "char: "<< "'" << static_cast<char> (checkint) << "'\n";
		else
			std::cout << "char: " << " Non displayable\n";
		std::cout << "int: " << checkint << std::endl;
		if ( fmod ( static_cast<double>(checkint), 1 ) == 0 ) {
			std::cout << std::setprecision(str.length()) << "float: " << static_cast<float>(checkint) << ".0f\n";
			std::cout << std::setprecision(str.length()) << "double: " << static_cast<double>(checkint) << ".0\n";
		}
		else {
			std::cout << std::setprecision(str.length()) << "float: " << static_cast<float>(checkint) << ".f\n";
			std::cout << std::setprecision(str.length()) << "double: " << static_cast<double>(checkint) << std::endl;
		}
	}
	else if (checkfloat != 0 && myfloat <= FLT_MAX && myfloat >= FLT_MIN) {
		float flot = static_cast<float>(myfloat);
		if (isprint(flot))
			std::cout << "char: " << "'" << static_cast<char> (flot) << "'\n";
		else
			std::cout << "char: " << " Non displayable\n";
		if (flot < INT_MAX)
			std::cout << "int: " << static_cast<int>(flot) << std::endl;
		else
			std::cout << "int: impossible\n";
		if (fmod(flot, 1) == 0) {
			std::cout << std::setprecision(str.length()) << "float: " << flot << ".0f\n";
			std::cout << std::setprecision(str.length()) << "double: " << static_cast<double>(flot) << ".0\n";
		}
		else {
			std::cout << std::setprecision(str.length()) <<  "flotloat: " << flot << "f" << std::endl;
			std::cout << std::setprecision(str.length()) <<  "double: " << static_cast<double>(flot) << std::endl;
		}
	}
	else if (checkdouble != 0 && myfloat <= DBL_MAX && myfloat >= -DBL_MAX) {
		double myDub = static_cast<double>(myfloat);
		if (isprint(myDub))
			std::cout << "char: " << "'" << static_cast<char> ( myDub ) << "'\n";
		else
			std::cout << "char: " << " Non displayable\n";
		if (myDub < INT_MAX)
			std::cout << "int: " << static_cast<int>(myDub) << std::endl;
		else
			std::cout << "int: impossible\n";
		if (myDub < FLT_MAX) {
			if (fmod(myDub, 1) == 0)
				std::cout << std::setprecision(str.length()) <<  "float: " << static_cast<float>(myDub) << ".0f\n";
		}
		else
			std::cout << "float: impossible\n";
		if (fmod( myDub, 1) == 0)
			std::cout << std::setprecision(str.length()) <<  "double: " << myDub << ".0\n";
		else
			std::cout << std::setprecision(str.length()) <<  "double: " << myDub << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (0);
	}
}

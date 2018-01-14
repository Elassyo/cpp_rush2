//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#ifndef CPP_RUSH2_TEDDY_HPP
	#define CPP_RUSH2_TEDDY_HPP

	#include "Toy.hpp"

class Teddy : public Toy {
public :
	Teddy(std::string name);

	Object *clone() const;

	void isTaken();
};

#endif //CPP_RUSH2_TEDDY_HPP

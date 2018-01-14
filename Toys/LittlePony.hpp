//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#ifndef CPP_RUSH2_LITTLEPONY_HPP
	#define CPP_RUSH2_LITTLEPONY_HPP

	#include "Toy.hpp"

class LittlePony : public Toy {
public :
	LittlePony(std::string name);

	Object *clone() const;

	void isTaken();
};

#endif //CPP_RUSH2_LITTLEPONY_HPP

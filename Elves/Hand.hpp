//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#ifndef CPP_RUSH2_HAND_HPP
#define CPP_RUSH2_HAND_HPP

	#include "../RollingCarpet/ConveyorBelt.hpp"

class Hand {
public :
	Hand();
	~Hand();

	void pushInButton(ConveyorBelt *conveyorBelt, Object *object);
	void pushOutButton(ConveyorBelt *conveyorBelt);
};

#endif //CPP_RUSH2_HAND_HPP

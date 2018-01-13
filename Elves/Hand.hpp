//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#ifndef CPP_RUSH2_HAND_HPP
#define CPP_RUSH2_HAND_HPP

#include "ConveyorBelt.hpp"

class Hand
{
public :
	Hand();
	~Hand();

	void pushInButton(ConveyorBelt *conveyorBelt, Object *object);
	void pushOutButton(ConveyorBelt *conveyorBelt);

};


#endif //CPP_RUSH2_HAND_HPP

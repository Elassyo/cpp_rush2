//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#include "Hand.hpp"

Hand::Hand()
{
}

Hand::~Hand()
{
}

void Hand::pushInButton(ConveyorBelt *conveyorBelt, Object *object)
{
	if (!conveyorBelt) {
		std::cout << "Hand : You're trying to press a button that does"
		          << "not exist (ConveyorBelt is null)" << std::endl;
		return;
	}
	conveyorBelt->pressIn(object);
}

void Hand::pushOutButton(ConveyorBelt *conveyorBelt)
{
	if (!conveyorBelt) {
		std::cout << "Hand : You're trying to press a button that does"
		          << "not exist (ConveyorBelt is null)" << std::endl;
		return;
	}
	conveyorBelt->pressOut();
}

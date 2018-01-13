//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
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

//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#include <iostream>
#include "LittlePony.hpp"

LittlePony::LittlePony(std::string name) :
	Toy(name, "LittlePony")
{
}

void LittlePony::isTaken()
{
	std::cout << "yo man" << std::endl;
}

Object *LittlePony::clone() const
{
	return (new LittlePony(this->name));
}

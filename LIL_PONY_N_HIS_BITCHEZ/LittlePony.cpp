//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#include <iostream>
#include "LittlePony.hpp"

LittlePony::LittlePony(std::string name) : Toy(name, "LittlePony")
{
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken()
{
	std::cout << "yo man" << std::endl;
}
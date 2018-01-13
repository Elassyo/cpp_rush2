//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#include <iostream>
#include "Teddy.hpp"

Teddy::Teddy(std::string name) : Toy(name, "Teddy")
{
}

Teddy::~Teddy()
{
}

void Teddy::isTaken()
{
	std::cout << "gra hu" << std::endl;
}

//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#include <iostream>
#include "Teddy.hpp"

Teddy::Teddy(std::string name) :
	Toy(name, "Teddy")
{
}

Teddy::~Teddy()
{
}

void Teddy::isTaken()
{
	std::cout << "gra hu" << std::endl;
}

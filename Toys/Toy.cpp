//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#include "Toy.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"

Toy::Toy(std::string _name, std::string className) : Object(className), name(_name)
{
}

Toy::~Toy()
{
}

void Toy::isTaken()
{
	if (Object::getClassName() == "Teddy")
		((Teddy *)this)->Teddy::isTaken();
	if (Object::getClassName() == "LittlePony")
		((LittlePony *)this)->LittlePony::isTaken();
}

std::string Toy::getName() const
{
	return (name);
}
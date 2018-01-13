//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#include "Object.hpp"
#include "../Elves/Toy.hpp"

Object::Object(std::string _className) : className(_className)
{
}

Object::~Object()
{
}

const std::string &Object::getClassName() const
{
	return (className);
}
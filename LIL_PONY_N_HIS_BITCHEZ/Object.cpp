//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#include "Object.hpp"

Object::Object(std::string _name, std::string _className) : name(_name), className(_className)
{
}

Object::~Object()
{
}

std::string Object::getClassName()
{
	return (className);
}

std::string Object::getName()
{
	return (name);
}
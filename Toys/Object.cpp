//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#include "Object.hpp"

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
/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Box.cpp
*/

#include "Box.hpp"

Box::Box() :
	Wrap("Box")
{
}

void Box::closeMe()
{
	this->_isOpen = false;
}

/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Wrap.cpp
*/

#include "Wrap.hpp"

Wrap::Wrap(const std::string &className) : Object(className)
{
	std::cout << "whistles while working" << std::endl;
}

bool Wrap::wrapMeThat(Object &object)
{
	if (!this->_object && this->_isOpen) {
		std::cout << "tuuuut tuuut tuut" << std::endl;
		this->_object = &object;
		return (true);
	}
	if (this->_object)
		std::cerr << className << " : ERROR : "
		          << " : This wrap already contains an object !"
		          << std::endl;
	if (!this->_isOpen && this->getClassName() == "Box")
		std::cerr << className << " : ERROR : "
		          << " : This wrap is closed !" << std::endl;
	return (false);
}

Object *Wrap::openMe()
{
	Object *tmp = this->_object;
	if (!this->_object && this->_isOpen) {
		std::cerr << className << " : ERROR : "
		          << " : This wrap does not contain any object and"
		          << " is already open !" << std::endl;
		return (NULL);
	}
	this->_isOpen = true;
	this->_object = NULL;
	return (tmp);
}

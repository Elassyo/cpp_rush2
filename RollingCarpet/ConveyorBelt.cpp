/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** ConveyorBelt.cpp
*/

#include "ConveyorBelt.hpp"

Object *ConveyorBelt::takeObject()
{
	if (!this->_item) {
		std::cerr << this->_className << " : ERROR : "
		          << " : There is no object to be taken !"
		          << std::endl;
		return (nullptr);
	}
	Object *tmp = this->_item;
	this->_item = nullptr;
	return (tmp);
}

void ConveyorBelt::putObject(Object *object)
{
	if (this->_item) {
		std::cerr << this->_className << " : ERROR : "
		          << "There is already an object here !"
		          << std::endl;
		return ;
	}
	this->_item = object;
}

void ConveyorBelt::pressIn(Object *object)
{
	this->putObject(object);
}

void ConveyorBelt::pressOut()
{
	if (!this->_item) {
		std::cerr << this->_className << " : ERROR : "
		          << " : There is no object to be sent to Santa !"
		          << std::endl;
		return;
	}
	this->_item->serialize("object");
	delete(this->_item);
	this->_item = nullptr;
}

IConveyorBelt *ConveyorBelt::createConveyorBelt()
{
	return (new ConveyorBelt());
}

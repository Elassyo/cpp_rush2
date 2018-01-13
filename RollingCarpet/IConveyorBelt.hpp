/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** ConveyorBelt.hpp
*/

#ifndef CPP_RUSH2_ICONVEYORBELT_HPP
#define CPP_RUSH2_ICONVEYORBELT_HPP

#include <iostream>
#include "../Toys/Object.hpp"

class IConveyorBelt
{
public:
	virtual Object *takeObject() = 0;
	virtual void putObject(Object *) = 0;
	virtual void pressIn(Object *object) = 0;
	virtual void pressOut() = 0;
	virtual IConveyorBelt *createConveyorBelt() = 0;
	Object *_item = NULL;

private:
	std::string _className;
};

#endif //CPP_RUSH2_ICONVEYORBELT_HPP

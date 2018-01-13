/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** ConveyorBelt.hpp
*/

#ifndef CPP_RUSH2_CONVEYORBELT_HPP
#define CPP_RUSH2_CONVEYORBELT_HPP

#include <iostream
#include "../BoxStory/Object.hpp"

class ConveyorBelt {
public:
	Object *takeObject();
	void putObject(Object *);
	Object *_item = NULL;

private:
	std::string _className = "ConveyorBelt";
};


#endif //CPP_RUSH2_CONVEYORBELT_HPP

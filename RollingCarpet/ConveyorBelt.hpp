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
#include "IConveyorBelt.hpp"

class ConveyorBelt : public IConveyorBelt
{
public:
	Object *takeObject() override;
	void putObject(Object *) override;
	Object *_item = NULL;
	void pressIn(Object *object) override;
	void pressOut() override;
	IConveyorBelt *createConveyorBelt() override;

private:
	std::string _className = "ConveyorBelt";
};


#endif //CPP_RUSH2_CONVEYORBELT_HPP

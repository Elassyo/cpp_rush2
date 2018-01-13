/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Table.hpp
*/

#ifndef CPP_RUSH2_ITABLE_HPP
#define CPP_RUSH2_ITABLE_HPP

#include <iostream>
#include <vector>
#include "../BoxStory/Object.hpp"

class ITable
{
public:
	virtual Object *takeObject(unsigned int) = 0;
	virtual void putObject(Object *) = 0;
	virtual ~Table() = 0;
	virtual ITable *createTable() = 0;
	std::vector<Object *> _items;

private:
	std::string _className;
};

#endif //CPP_RUSH2_ITABLE_HPP

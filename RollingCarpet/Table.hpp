/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Table.hpp
*/

#ifndef CPP_RUSH2_TABLE_HPP
#define CPP_RUSH2_TABLE_HPP

#include <iostream>
#include <vector>
#include "../BoxStory/Object.hpp"

class Table
{
public:
	Object *takeObject(unsigned int);
	void putObject(Object *);
	virtual ~Table();

private:
	std::vector<Object *> _items;
	std::string _className = "Table";
};

#endif //CPP_RUSH2_TABLE_HPP

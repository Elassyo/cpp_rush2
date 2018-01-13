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
	#include "ITable.hpp"
	#include "../Object.hpp"

class Table : public ITable {
public:
	Object *takeObject(unsigned int) override;
	void putObject(Object *) override;
	virtual ~Table();
	ITable *createTable() override;
	std::vector<Object *> _items;

private:
	std::string _className = "Table";
};

#endif //CPP_RUSH2_TABLE_HPP

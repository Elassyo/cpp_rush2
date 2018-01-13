/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Table.cpp
*/

#include "Table.hpp"
#include "../Toys/Toy.hpp"

Table::~Table()
{
	this->_items.erase(this->_items.begin(), this->_items.end());
}

Object *Table::takeObject(unsigned int idx)
{
	Object *tmp;
	if (idx >= this->_items.size()) {
		std::cerr << _className << " : The object you're trying to take"
			" is in another castle !" << std::endl;
		return (NULL);
	}
	if (_items[idx]->getClassName() == "Teddy" || _items[idx]->getClassName() == "LittlePony")
		((Toy *)_items[idx])->isTaken();
	tmp = this->_items.at(idx);
	this->_items.erase(this->_items.begin() + idx);
	return (tmp);
}

void Table::putObject(Object *object)
{
	this->_items.push_back(object);
	if (this->_items.size() >= 11) {
		std::cerr << _className << " : Oh no ! The table collapses !" <<
			std::endl;
		delete (this);
		return;
	}
}

ITable *Table::createTable()
{
	return (new Table());
}

/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** ObjectDB class implementation
*/

#include "Object.hpp"

#include <iostream>

ObjectDB::~ObjectDB()
{
	std::map<std::string,const Object *>::const_iterator it;
	for (it = this->_db.begin(); it != this->_db.end(); it++)
		delete it->second;
}

void ObjectDB::addClass(const Object *obj)
{
	if (!obj)
		return;
	this->_db[obj->getClassName()] = obj;
}

Object *ObjectDB::instantiate(const std::string className) const
{
	std::map<std::string,const Object *>::const_iterator it =
		this->_db.find(className);
	Object *res = NULL;
	if (it != this->_db.end())
		res = it->second->clone();
	return (res);
}

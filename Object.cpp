//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#include "Object.hpp"

Object::Object(std::string _className) : className(_className)
{
}

Object::~Object()
{
}

const std::string &Object::getClassName() const
{
	return (className);
}

Xml::XmlElementNode *Object::serialize(const std::string name) const
{
	Xml::XmlElementNode *node = new Xml::XmlElementNode(name);
	node->addNode("className", this->className);
	return (node);
}

void Object::deserialize(const ObjectDB *, const Xml::XmlElementNode *)
{
}

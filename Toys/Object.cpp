//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
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

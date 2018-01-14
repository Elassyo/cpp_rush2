/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Wrap.cpp
*/

#include "Wrap.hpp"

Wrap::Wrap(const std::string &className) :
	Object(className)
{
}

bool Wrap::wrapMeThat(Object &object)
{
	if (!this->_object && this->_isOpen) {
		std::cout << "tuuuut tuuut tuut" << std::endl;
		this->_object = &object;
		return (true);
	}
	if (this->_object)
		std::cerr << className << " : ERROR : This wrap already"
			" contains an object !"<< std::endl;
	if (!this->_isOpen && this->getClassName() == "Box")
		std::cerr << className << " : ERROR : This wrap is closed !" <<
			std::endl;
	return (false);
}

Object *Wrap::openMe()
{
	this->_isOpen = true;
	if (!this->_object) {
		return (nullptr);
	}
	return (this->_object);
}

Xml::XmlElementNode *Wrap::serialize(const std::string name) const
{
	Xml::XmlElementNode *res = Object::serialize(name);
	res->addNode("open", this->_isOpen ? "true" : "false");
	if (this->_object) {
		Xml::XmlElementNode *contentNode =
			_object->serialize("object");
		res->addNode(contentNode);
	}
	return (res);

}

bool Wrap::deserialize(const ObjectDB *db, const Xml::XmlElementNode *node)
{
	const Xml::XmlElementNode *open = node->getChildNode("open");
	const Xml::XmlElementNode *object = node->getChildNode("object");
	if (!open)
		return false;
	if (open->innerText() == "true")
		this->_isOpen = true;
	else if (open->innerText() == "false")
		this->_isOpen = false;
	if (object)
		this->_object = object->deserialize(db);
	else
		this->object = nullptr;
	return (this->_object ? true : false);
}

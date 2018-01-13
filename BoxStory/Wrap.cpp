/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Wrap.cpp
*/

#include "Wrap.hpp"

Wrap::Wrap(const std::string &className) : Object(className)
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
		std::cerr << className << " : ERROR : This wrap already contains an object !"
		          << std::endl;
	if (!this->_isOpen && this->getClassName() == "Box")
		std::cerr << className << " : ERROR : This wrap is closed !" << std::endl;
	return (false);
}

Object *Wrap::openMe()
{
	this->_isOpen = true;
	if (!this->_object) {
		std::cerr << className << " : ERROR"
		          << " : This wrap does not contain any object !"
		          << std::endl;
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

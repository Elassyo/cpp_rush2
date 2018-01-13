/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlException class implementation
*/

#include "XmlException.hpp"

Xml::XmlException::XmlException(const std::string message) :
	_message(message)
{
}

std::string Xml::XmlException::getMessage() const
{
	return (this->_message);
}

std::ostream &operator<<(std::ostream &os, const Xml::XmlException &ex)
{
	os << "XmlException: " << ex.getMessage();
	return (os);
}

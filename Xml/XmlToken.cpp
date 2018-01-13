/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlToken class implementation
*/

#include "XmlToken.hpp"

Xml::XmlToken::XmlToken(TokenType type, const std::string value,
	unsigned int pos) :
	_type(type), _value(value), _pos(pos)
{
}

Xml::XmlToken::XmlToken(const XmlToken &other) :
	_type(other._type), _value(other._value), _pos(other._pos)
{
}

Xml::XmlToken &Xml::XmlToken::operator=(const XmlToken &other)
{
	this->_type = other._type;
	this->_value = other._value;
	this->_pos = other._pos;
	return (*this);
}

Xml::XmlToken::TokenType Xml::XmlToken::getType() const
{
	return (this->_type);
}

std::string Xml::XmlToken::getValue() const
{
	return (this->_value);
}

unsigned int Xml::XmlToken::getPosition() const
{
	return (this->_pos);
}

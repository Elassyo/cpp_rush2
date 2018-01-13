/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlToken class implementation
*/

#include "XmlToken.hpp"

Xml::XmlToken::XmlToken(TokenType type, const std::string value) :
	_type(type), _value(value)
{
}

const std::string Xml::XmlToken::getValue() const
{
	return (this->_value);
}

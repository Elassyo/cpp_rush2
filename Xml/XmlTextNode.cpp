/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlTextNode class implementation
*/

#include "XmlTextNode.hpp"

Xml::XmlTextNode::XmlTextNode(const std::string value) :
	Xml::XmlNode(Xml::XmlNode::TEXT), _value(value)
{
}

const std::string Xml::XmlTextNode::getValue() const
{
	return (this->_value);
}

const Xml::XmlNode *Xml::XmlTextNode::clone() const
{
	return (new XmlTextNode(this->_value));
}

std::string Xml::XmlTextNode::toString() const
{
	return (this->_value);
}

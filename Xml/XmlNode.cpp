/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlNode class implementation
*/

#include "XmlNode.hpp"

Xml::XmlNode::XmlNode(const Xml::XmlNode::NodeType type) :
	_type(type)
{
}

Xml::XmlNode::NodeType Xml::XmlNode::getType() const
{
	return (this->_type);
}

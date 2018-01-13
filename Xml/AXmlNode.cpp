/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** AXmlNode class implementation
*/

#include "AXmlNode.hpp"

Xml::AXmlNode::AXmlNode(const Xml::AXmlNode::NodeType type) :
	_type(type)
{
}

Xml::AXmlNode::NodeType Xml::AXmlNode::getType() const
{
	return (this->_type);
}

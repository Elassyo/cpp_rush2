/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlElementNode class implementation
*/

#include <sstream>
#include "XmlElementNode.hpp"

Xml::XmlElementNode::XmlElementNode(const std::string name) :
	Xml::XmlNode(Xml::XmlNode::ELEMENT), _name(name)
{
}

Xml::XmlElementNode::~XmlElementNode()
{
	std::list<const XmlNode*>::const_iterator it;
	for (it = this->_childNodes.begin(); it != this->_childNodes.end();
		it++)
		delete *it;
}

const std::string Xml::XmlElementNode::getName() const
{
	return (this->_name);
}

const std::list<const Xml::XmlNode*> Xml::XmlElementNode::getChildNodes() const
{
	return (this->_childNodes);
}

void Xml::XmlElementNode::addNode(const XmlNode *node)
{
	this->_childNodes.push_back(node);
}

std::string Xml::XmlElementNode::toString() const
{
	std::ostringstream oss;
	oss << "<" << this->_name << ">";
	std::list<const XmlNode*>::const_iterator it;
	for (it = this->_childNodes.begin(); it != this->_childNodes.end();
		it++)
		oss << (*it)->toString();
	oss << "</" << this->_name << ">";
	return (oss.str());
}

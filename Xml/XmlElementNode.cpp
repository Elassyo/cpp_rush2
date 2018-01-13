/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlElementNode class implementation
*/

#include <sstream>
#include "XmlElementNode.hpp"
#include "XmlTextNode.hpp"

Xml::XmlElementNode::XmlElementNode(const std::string name) :
	Xml::AXmlNode(Xml::AXmlNode::ELEMENT), _name(name)
{
}

Xml::XmlElementNode::~XmlElementNode()
{
	std::list<const AXmlNode*>::const_iterator it;
	for (it = this->_childNodes.begin(); it != this->_childNodes.end();
		it++)
		delete *it;
}

const std::string Xml::XmlElementNode::getName() const
{
	return (this->_name);
}

const std::list<const Xml::AXmlNode*> Xml::XmlElementNode::getChildNodes() const
{
	return (this->_childNodes);
}

const Xml::AXmlNode *Xml::XmlElementNode::clone() const
{
	auto res = new XmlElementNode(this->_name);
	std::list<const AXmlNode*>::const_iterator it;
	for (it = this->_childNodes.begin(); it != this->_childNodes.end();
		it++)
		res->addNode((*it)->clone());
	return (res);
}

void Xml::XmlElementNode::addNode(const AXmlNode *node)
{
	this->_childNodes.push_back(node);
}


void Xml::XmlElementNode::addNode(const std::string name,
	const std::string value)
{
	XmlElementNode *childNode = new Xml::XmlElementNode(name);
	childNode->addNode(new Xml::XmlTextNode(value));
	this->addNode(childNode);
}

std::string Xml::XmlElementNode::toString() const
{
	std::ostringstream oss;
	oss << "<" << this->_name << ">";
	std::list<const AXmlNode*>::const_iterator it;
	for (it = this->_childNodes.begin(); it != this->_childNodes.end();
		it++)
		oss << (*it)->toString();
	oss << "</" << this->_name << ">";
	return (oss.str());
}

/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlElementNode class definition
*/

#if !defined (XML_ELEMENT_NODE_HPP_)
	#define XML_ELEMENT_NODE_HPP_

	#include <list>
	#include "XmlNode.hpp"

namespace Xml {

class XmlElementNode : public XmlNode {
public:
	XmlElementNode(const std::string name);
	~XmlElementNode();

	const std::string getName() const;
	const std::list<const XmlNode*> getChildNodes() const;

	void addNode(const XmlNode *node);
	const XmlNode *clone() const;
	std::string toString() const;

private:
	const std::string _name;
	std::list<const XmlNode*> _childNodes;
};

} /* namespace Xml */

#endif /* !defined (XML_ELEMENT_NODE_HPP_) */

/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlElementNode class definition
*/

#if !defined (XML_ELEMENT_NODE_HPP_)
	#define XML_ELEMENT_NODE_HPP_

	#include <list>
	#include "AXmlNode.hpp"
	#include "../ObjectDB.hpp"

namespace Xml {

class XmlElementNode : public AXmlNode {
public:
	XmlElementNode(const std::string name);
	~XmlElementNode();

	const std::string getName() const;
	const std::list<const AXmlNode*> getChildNodes() const;

	void addNode(const AXmlNode *node);
	void addNode(const std::string name, const std::string value);
	const AXmlNode *clone() const;
	std::string toString() const;
	Object *deserialize(const ObjectDB *db) const;

private:
	const std::string _name;
	std::list<const AXmlNode*> _childNodes;
};

} /* namespace Xml */

#endif /* !defined (XML_ELEMENT_NODE_HPP_) */

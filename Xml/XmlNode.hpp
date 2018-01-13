/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlNode interface definition
*/

#if !defined (XML_NODE_HPP_)
	#define XML_NODE_HPP_

	#include <ostream>
	#include <string>

namespace Xml {

class XmlNode {
public:
	enum NodeType {
		ELEMENT,
		TEXT
	};

	virtual ~XmlNode() {}

	NodeType getType() const;

	virtual const XmlNode *clone() const = 0;
	virtual std::string toString() const = 0;

protected:
	XmlNode(NodeType type);

	const NodeType _type;
};

} /* namespace Xml */

#endif /* !defined (XML_NODE_HPP_) */

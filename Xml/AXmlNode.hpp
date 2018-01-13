/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** AXmlNode interface definition
*/

#if !defined (AXML_NODE_HPP_)
	#define AXML_NODE_HPP_

	#include <ostream>
	#include <string>

namespace Xml {

class AXmlNode {
public:
	enum NodeType {
		ELEMENT,
		TEXT
	};

	virtual ~AXmlNode() {}

	NodeType getType() const;

	virtual std::string innerText() const = 0;
	virtual const AXmlNode *clone() const = 0;
	virtual std::string toString() const = 0;

protected:
	AXmlNode(NodeType type);

	const NodeType _type;
};

} /* namespace Xml */

#endif /* !defined (AXML_NODE_HPP_) */

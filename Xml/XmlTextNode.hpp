/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlTextNode class definition
*/

#if !defined (XML_TEXT_NODE_HPP_)
	#define XML_TEXT_NODE_HPP_

	#include "AXmlNode.hpp"

namespace Xml {

class XmlTextNode : public AXmlNode {
public:
	XmlTextNode(const std::string value);

	const std::string getValue() const;

	const AXmlNode *clone() const;
	std::string toString() const;

private:
	const std::string _value;
};

} /* namespace Xml */

#endif /* !defined (XML_TEXT_NODE_HPP_) */

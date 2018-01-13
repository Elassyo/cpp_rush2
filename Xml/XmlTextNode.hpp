/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlTextNode class definition
*/

#if !defined (XML_TEXT_NODE_HPP_)
	#define XML_TEXT_NODE_HPP_

	#include "XmlNode.hpp"

namespace Xml {

class XmlTextNode : public XmlNode {
public:
	XmlTextNode(const std::string value);

	const std::string getValue() const;

	const XmlNode *clone() const;
	std::string toString() const;

private:
	const std::string _value;
};

} /* namespace Xml */

#endif /* !defined (XML_TEXT_NODE_HPP_) */

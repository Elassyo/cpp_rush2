/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** IXmlSerializable interface definition
*/

#if !defined (IXML_SERIALIZABLE_HPP_)
	#define IXML_SERIALIZABLE_HPP_

	#include <string>

namespace Xml {

class IXmlSerializable {
public:
	virtual ~IXmlSerializable() {}

	virtual XmlElementNode *serialize(const std::string name) const = 0;
	virtual void deserialize(const XmlElementNode *node) = 0;
};

} /* namespace Xml */

#endif /* !defined (IXML_SERIALIZABLE_HPP_) */

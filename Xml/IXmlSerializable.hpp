/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** IXmlSerializable interface definition
*/

#if !defined (IXML_SERIALIZABLE_HPP_)
	#define IXML_SERIALIZABLE_HPP_

namespace Xml {

class IXmlSerializable {
public:
	virtual ~IXmlSerializable() {}

	virtual XmlNode serialize() const = 0;
	virtual void deserialize(const XmlNode node) = 0;
};

} /* namespace Xml */

#endif /* !defined (IXML_SERIALIZABLE_HPP_) */

/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlException class definition
*/

#if !defined (XML_EXCEPTION_HPP_)
	#define XML_EXCEPTION_HPP_

	#include <ostream>
	#include <string>

namespace Xml {

class XmlException {
public:
	XmlException(const std::string message = "Error");

	std::string getMessage() const;

private:
	const std::string _message;
};

} /* namespace Xml */

std::ostream &operator<<(std::ostream &os, const Xml::XmlException &ex);

#endif /* !defined (XML_EXCEPTION_HPP_) */

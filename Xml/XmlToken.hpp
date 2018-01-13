/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlToken class definition
*/

#if !defined (XML_TOKEN_HPP_)
	#define XML_TOKEN_HPP_

	#include <string>

namespace Xml {

class XmlToken {
public:
	enum TokenType {
		TAG_BEGIN,
		TAG_TERMINATOR,
		TAG_NAME,
		TAG_END,
		TEXT,
		_EOF
	};

	XmlToken(TokenType type, const std::string value);

	const std::string getValue() const;

private:
	TokenType _type;
	const std::string _value;
};

} /* namespace Xml */

#endif /* !defined (XML_TOKEN_HPP_) */

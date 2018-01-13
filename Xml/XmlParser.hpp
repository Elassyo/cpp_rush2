/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlParser class definition
*/

#if !defined (XML_PARSER_HPP_)
	#define XML_PARSER_HPP_

	#include "XmlElementNode.hpp"
	#include "XmlLexer.hpp"

namespace Xml {

class XmlParser {
public:
	XmlParser(XmlLexer lexer);

	XmlElementNode *parse();

private:
	void accept(XmlToken::TokenType type);

	XmlLexer _lexer;
	XmlToken _current;
};

} /* namespace Xml */

#endif /* !defined (XML_PARSER_HPP_) */

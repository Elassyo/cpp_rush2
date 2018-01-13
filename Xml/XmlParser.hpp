/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlParser class definition
*/

#if !defined (XML_PARSER_HPP_)
	#define XML_PARSER_HPP_

	#include <stack>
	#include <string>
	#include "XmlElementNode.hpp"
	#include "XmlTextNode.hpp"
	#include "XmlLexer.hpp"

namespace Xml {

class XmlParser {
public:
	XmlParser(XmlLexer &lexer);

	XmlElementNode *parse();

private:
	bool accept(XmlToken::TokenType type);
	void expect(XmlToken::TokenType type);

	void ignoreWhitespaces();
	XmlElementNode *node();
	XmlElementNode *openingTag();
	void closingTag();
	XmlTextNode *text();

	XmlLexer &_lexer;
	XmlToken _current;

	std::stack<std::string> _nodeStack;
};

} /* namespace Xml */

#endif /* !defined (XML_PARSER_HPP_) */

/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 1
** File description:
** XmlLexer class definition
*/

#if !defined (XML_LEXER_HPP_)
	#define XML_LEXER_HPP_

	#include <istream>
	#include "XmlToken.hpp"

namespace Xml {

class XmlLexer {
public:
	XmlLexer(std::istream &is);

	XmlToken getNextToken();

private:
	enum LexerState {
		CONTENT,
		TAG
	};

	void advance();

	XmlToken tagBegin();
	XmlToken tagTerminator();
	XmlToken tagName();
	XmlToken tagEnd();
	XmlToken text();

	std::istream &_is;
	char _current;
	LexerState _state;
};

} /* namespace Xml */

#endif /* !defined (XML_LEXER_HPP_) */

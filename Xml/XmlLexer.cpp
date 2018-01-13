/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlLexer class implementation
*/

#include <cctype>
#include "XmlException.hpp"
#include "XmlLexer.hpp"

Xml::XmlLexer::XmlLexer(std::istream &is) :
	_is(is), _pos(0), _current(is.get()), _state(CONTENT)
{
}

Xml::XmlToken Xml::XmlLexer::getNextToken()
{
	if (this->_current == EOF)
		return (Xml::XmlToken(Xml::XmlToken::_EOF, "", this->_pos));
	if (this->_state == CONTENT) {
		if (this->_current == '<')
			return (this->tagBegin());
		else
			return (this->text());
	}
	else if (this->_state == TAG) {
		if (this->_current == '/')
			return (this->tagTerminator());
		else if (this->_current == '>')
			return (this->tagEnd());
		else if (isalpha(this->_current) || this->_current == '_')
			return (this->tagName());
	}
	throw Xml::XmlException("Invalid character");
}

void Xml::XmlLexer::advance()
{
	this->_current = this->_is.get();
	this->_pos++;
}

Xml::XmlToken Xml::XmlLexer::tagBegin()
{
	unsigned int startingPos = this->_pos;
	this->advance();
	this->_state = TAG;
	return (Xml::XmlToken(Xml::XmlToken::TAG_BEGIN, "<", startingPos));
}

Xml::XmlToken Xml::XmlLexer::tagTerminator()
{
	unsigned int startingPos = this->_pos;
	this->advance();
	return (Xml::XmlToken(Xml::XmlToken::TAG_TERMINATOR, "/", startingPos));
}

Xml::XmlToken Xml::XmlLexer::tagName()
{
	unsigned int startingPos = this->_pos;
	std::string value = "";
	value += this->_current;
	this->advance();
	while (isalnum(this->_current) ||
		this->_current == '-' ||
		this->_current == '_' ||
		this->_current == '.') {
		value += this->_current;
		this->advance();
	}
	return (Xml::XmlToken(Xml::XmlToken::TAG_NAME, value, startingPos));
}

Xml::XmlToken Xml::XmlLexer::tagEnd()
{
	unsigned int startingPos = this->_pos;
	this->advance();
	this->_state = CONTENT;
	return (Xml::XmlToken(Xml::XmlToken::TAG_END, ">", startingPos));
}

Xml::XmlToken Xml::XmlLexer::text()
{
	unsigned int startingPos = this->_pos;
	std::string value = "";
	while (this->_current != EOF &&
		this->_current != '<') {
		value += this->_current;
		this->advance();
	}
	return (Xml::XmlToken(Xml::XmlToken::TEXT, value, startingPos));
}

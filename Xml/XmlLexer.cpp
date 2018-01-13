/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlLexer class implementation
*/

#include <cctype>
#include "XmlLexer.hpp"

Xml::XmlLexer::XmlLexer(std::istream &is) :
	_is(is), _current(is.get()), _state(CONTENT)
{
}

Xml::XmlToken Xml::XmlLexer::getNextToken()
{
	if (this->_current == EOF)
		return (Xml::XmlToken(Xml::XmlToken::_EOF, ""));
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
	throw "Invalid character " + this->_current;
}

void Xml::XmlLexer::advance()
{
	this->_current = this->_is.get();
}

Xml::XmlToken Xml::XmlLexer::tagBegin()
{
	this->advance();
	this->_state = TAG;
	return (Xml::XmlToken(Xml::XmlToken::TAG_BEGIN, "<"));
}

Xml::XmlToken Xml::XmlLexer::tagTerminator()
{
	this->advance();
	return (Xml::XmlToken(Xml::XmlToken::TAG_TERMINATOR, "/"));
}

Xml::XmlToken Xml::XmlLexer::tagName()
{
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
	return (Xml::XmlToken(Xml::XmlToken::TAG_NAME, value));
}

Xml::XmlToken Xml::XmlLexer::tagEnd()
{
	this->advance();
	this->_state = CONTENT;
	return (Xml::XmlToken(Xml::XmlToken::TAG_END, ">"));
}

Xml::XmlToken Xml::XmlLexer::text()
{
	std::string value = "";
	while (this->_current != EOF &&
		this->_current != '<') {
		value += this->_current;
		this->advance();
	}
	return (Xml::XmlToken(Xml::XmlToken::TEXT, value));
}

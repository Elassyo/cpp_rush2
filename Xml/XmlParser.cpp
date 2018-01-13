/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlParser class implementation
*/

#include "XmlException.hpp"
#include "XmlParser.hpp"

#include <iostream>

Xml::XmlParser::XmlParser(XmlLexer &lexer) :
	_lexer(lexer), _current(lexer.getNextToken())
{
}

Xml::XmlElementNode *Xml::XmlParser::parse()
{
	this->ignoreWhitespaces();
	Xml::XmlElementNode *res = this->node();
	this->ignoreWhitespaces();
	this->expect(XmlToken::_EOF);
	return (res);
}

bool Xml::XmlParser::accept(XmlToken::TokenType type)
{
	if (this->_current.getType() == type) {
		this->_current = this->_lexer.getNextToken();
		return (true);
	}
	else {
		return (false);
	}
}

void Xml::XmlParser::expect(XmlToken::TokenType type)
{
	if (!this->accept(type)) {
		if (this->_current.getType() == XmlToken::_EOF)
			throw Xml::XmlException("Unexpected EOF");
		else
			throw Xml::XmlException("Invalid syntax");
	}
}

Xml::XmlElementNode *Xml::XmlParser::node()
{
	XmlElementNode *res = this->openingTag();
	this->ignoreWhitespaces();
	if (this->_current.getType() == XmlToken::TAG_BEGIN) {
		while (this->_current.getType() == XmlToken::TAG_BEGIN) {
			res->addNode(this->node());
			this->ignoreWhitespaces();
		}
	}
	else {
		res->addNode(this->text());
	}
	this->closingTag();
	return (res);
}

void Xml::XmlParser::ignoreWhitespaces()
{
	if (this->_current.getType() == XmlToken::TEXT &&
		this->_current.getValue().find_first_not_of(" \t\n\v\f\r") ==
		std::string::npos)
		this->accept(XmlToken::TEXT);
}

Xml::XmlElementNode *Xml::XmlParser::openingTag()
{
	this->expect(XmlToken::TAG_BEGIN);
	XmlToken token = this->_current;
	this->expect(XmlToken::TAG_NAME);
	this->expect(XmlToken::TAG_END);
	XmlElementNode *node = new Xml::XmlElementNode(token.getValue());
	this->_nodeStack.push(token.getValue());
	return (node);
}

void Xml::XmlParser::closingTag()
{
	this->expect(XmlToken::TAG_TERMINATOR);
	XmlToken token = this->_current;
	this->expect(XmlToken::TAG_NAME);
	this->expect(XmlToken::TAG_END);
	if (this->_nodeStack.top() != token.getValue())
		throw XmlException("Unclosed tag");
	this->_nodeStack.pop();
}

Xml::XmlTextNode *Xml::XmlParser::text()
{
	XmlToken token = this->_current;
	this->expect(XmlToken::TEXT);
	return (new XmlTextNode(token.getValue()));
}

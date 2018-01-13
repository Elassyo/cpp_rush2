/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** XmlParser class implementation
*/

#include "XmlException.hpp"
#include "XmlParser.hpp"

Xml::XmlParser::XmlParser(XmlLexer lexer) :
	_lexer(lexer), _current(lexer.getNextToken())
{
}

Xml::XmlElementNode *Xml::XmlParser::parse()
{
//	Xml::XmlElementNode *res = this->node();
	this->accept(Xml::XmlToken::_EOF);
	return NULL;
}

void Xml::XmlParser::accept(Xml::XmlToken::TokenType type)
{
	if (this->_current.getType() == type)
		this->_current = this->_lexer.getNextToken();
	else
		throw Xml::XmlException("Invalid syntax");
}

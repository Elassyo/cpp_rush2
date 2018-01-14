/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** Santa main program
*/

#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Toys/LittlePony.hpp"
#include "Toys/Teddy.hpp"
#include "BoxStory/Box.hpp"
#include "BoxStory/GiftPaper.hpp"
#include "Xml/XmlException.hpp"
#include "Xml/XmlParser.hpp"
#include "Object.hpp"
#include "ObjectDB.hpp"
#include "WarpMachine/WarpServer.hpp"

int inspect(Object *obj)
{
	if (!obj) {
		std::cerr << "Deserialization failed :(" << std::endl;
		return (1);
	}
	if (obj->getClassName() == "Object") {
		std::cerr << "There shouldn't be an 'Object' Object here :-|"
			<< std::endl;
		return (1);
	}
	Object *inside = ((Wrap *)obj)->openMe();
	if (inside->getClassName() == "Box"
	    || inside->getClassName() == "GiftPaper") {
		return (inspect(inside));
	} else {
		((Toy *)inside)->isTaken();
		return (0);
	}
}

int deserialize(std::istream &is)
{
	ObjectDB db;
	db.addClass(new LittlePony("Pony"));
	db.addClass(new Teddy("Teddy"));
	db.addClass(new Box());
	db.addClass(new GiftPaper());
	Xml::XmlLexer lexer(is);
	Xml::XmlParser parser(lexer);
	int res = 1;
	try {
		Xml::XmlElementNode *giftXml = parser.parse();
		Object *gift = giftXml->deserialize(&db);
		res = inspect(gift);
		delete gift;
		delete giftXml;
	}
	catch (Xml::XmlException ex) {
		std::cerr << "Error while parsing XML : " << ex << std::endl;
	}
	return (res);
}

int files(int argc, const char **argv)
{
	for (int i = 1; i < argc; i++) {
		std::ifstream file(argv[i]);
		if (!file) {
			std::cerr << "Failed to open gift file" << std::endl;
			return (1);
		}
		if (deserialize(file))
			return (1);
	}
	return (0);
}

int magicSock(int argc, const char **argv)
{
	if (argc < 3)
		return (1);
	WarpServer sock(argv[2], DEFAULT_WARP_PORT);
	sock.sendAddr();
	for (;;) {
		std::string mess = sock.receiveMessage();
		std::istringstream istr(mess);
		if (deserialize(istr))
			return (1);
	}
	return (0);
}

int main(int argc, const char **argv)
{
	if (argc < 2) {
		std::cerr << "usage: ./santa [GIFT] ..." << std::endl;
		std::cerr << "       ./santa -w [ADDR]" << std::endl;
		return (1);
	}
	if (strcmp(argv[1], "-w") == 0)
		return (magicSock(argc, argv));
	else
		return (files(argc, argv));
	return (0);
}

#include <fstream>
#include <iostream>
#include "XmlException.hpp"
#include "XmlParser.hpp"

int main()
{
	std::ifstream input("text.xml");
	Xml::XmlLexer lexer(input);

	Xml::XmlParser parser(lexer);

	try {
		Xml::XmlElementNode *root = parser.parse();

		std::cout << root->toString() << std::endl;

		delete root;
	} catch (Xml::XmlException ex) {
		std::cerr << ex << std::endl;
		return (1);
	}

	input.close();
	return (0);
}

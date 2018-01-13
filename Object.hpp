//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#ifndef CPP_RUSH2_OBJECT_HPP
#define CPP_RUSH2_OBJECT_HPP

#include <string>
#include "Xml/IXmlSerializable.hpp"

class Object : public Xml::IXmlSerializable
{
public :
	explicit Object(std::string _className);
	virtual ~Object();

	Xml::XmlElementNode *serialize(std::string name) const override ;
//	virtual void deserialize(const Xml::XmlElementNode *node) override ;

	const std::string &getClassName() const;

protected :
	std::string className;
};


#endif //CPP_RUSH2_OBJECT_HPP

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

class Object : public Xml::IXmlSerializable {
public :
	explicit Object(std::string _className);
	virtual ~Object();

	virtual Object *clone() const = 0;
	virtual Xml::XmlElementNode *serialize(std::string name) const override;

	const std::string &getClassName() const;

protected :
	std::string className;
};

#endif //CPP_RUSH2_OBJECT_HPP

//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#ifndef CPP_RUSH2_TOY_HPP
#define CPP_RUSH2_TOY_HPP

#include "Object.hpp"

class Toy : public Object
{
public :
	Toy(std::string _name, std::string _className);
	virtual ~Toy();

	std::string getName() const;
	virtual void isTaken();

	Xml::XmlElementNode *serialize(std::string name) const override;
	//void deserialize(const Xml::XmlElementNode *node);

private :
	std::string name;
};


#endif //CPP_RUSH2_TOY_HPP

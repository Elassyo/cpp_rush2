//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#include "Toy.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"

Toy::Toy(std::string _name, std::string className) : Object(className), name(_name)
{
}

Toy::~Toy()
{
}

void Toy::isTaken()
{
	if (Object::getClassName() == "Teddy")
		((Teddy *)this)->Teddy::isTaken();
	if (Object::getClassName() == "LittlePony")
		((LittlePony *)this)->LittlePony::isTaken();
}

std::string Toy::getName() const
{
	return (name);
}

Xml::XmlElementNode *Toy::serialize(const std::string name) const {
	Xml::XmlElementNode *res = Object::serialize(name);
	res->addNode("name", this->name);
	return (res);
}

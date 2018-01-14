//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#ifndef CPP_RUSH2_TOY_HPP
	#define CPP_RUSH2_TOY_HPP

	#include "../Object.hpp"

class Toy : public Object {
public:
	Toy(std::string _name, std::string _className);
	virtual ~Toy() {}

	std::string getName() const;
	virtual void isTaken();

	Xml::XmlElementNode *serialize(std::string name) const override;
	bool deserialize(const ObjectDB *, const Xml::XmlElementNode *) override;

protected:
	std::string name;
};


#endif //CPP_RUSH2_TOY_HPP

/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Wrap.hpp
*/

#ifndef CPP_RUSH2_WRAP_HPP
#define CPP_RUSH2_WRAP_HPP

#include <iostream>
#include "../Object.hpp"

class Wrap : public Object
{
public:
	Wrap(const std::string &);
	bool wrapMeThat(Object &);
	Object *openMe();

	Xml::XmlElementNode *serialize(std::string name) const override;
	//void deserialize(const Xml::XmlElementNode *node);

protected:
	bool _isOpen = true;
	Object *_object = NULL;
};


#endif //CPP_RUSH2_WRAP_HPP

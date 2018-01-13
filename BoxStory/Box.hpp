/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Box.hpp
*/

#ifndef CPP_RUSH2_BOX_HPP
	#define CPP_RUSH2_BOX_HPP

	#include "Wrap.hpp"

class Box : public Wrap {
public:
	Box();

	Object *clone() const;
	void deserialize(const ObjectDB *, const Xml::XmlElementNode *) override;

	void closeMe();
};

#endif //CPP_RUSH2_BOX_HPP

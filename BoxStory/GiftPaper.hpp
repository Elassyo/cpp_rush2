/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** GiftPaper.hpp
*/

#ifndef CPP_RUSH2_GIFTPAPER_HPP
	#define CPP_RUSH2_GIFTPAPER_HPP

	#include "Wrap.hpp"

class GiftPaper : public Wrap {
public:
	GiftPaper();

	Object *clone() const;
	void deserialize(const ObjectDB *, const Xml::XmlElementNode *) override;
};

#endif //CPP_RUSH2_GIFTPAPER_HPP

/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** GiftPaper.cpp
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper() :
	Wrap("GiftPaper")
{
}

Object *GiftPaper::clone() const
{
	return (NULL);
}

void GiftPaper::deserialize(const ObjectDB *, const Xml::XmlElementNode *)
{
}

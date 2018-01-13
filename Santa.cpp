/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** Santa main program
*/

#include <iostream>
#include "Toys/LittlePony.hpp"
#include "Toys/Teddy.hpp"
#include "BoxStory/Box.hpp"
#include "BoxStory/GiftPaper.hpp"
#include "Object.hpp"
#include "ObjectDB.hpp"

int main()
{
	std::cout << "HO HO HO" << std::endl;
	ObjectDB db;
	db.addClass(new LittlePony("Pony"));
	db.addClass(new Teddy("Teddy"));
	db.addClass(new Box);
	db.addClass(new GiftPaper);
	return (0);
}

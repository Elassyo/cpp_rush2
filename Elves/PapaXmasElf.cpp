//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#include <iostream>
#include "../Object.hpp"
#include "PapaXmasElf.hpp"
#include "../BoxStory/Box.hpp"
#include "../BoxStory/GiftPaper.hpp"
#include "../Toys/Toy.hpp"

void PapaXmasElf::putOnTable(Object *object)
{
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ?!" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	if (!table) {
		std::cerr << "PapaXmasElf: Where be me table ?!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'table' is NULL" << std::endl;
		return;
	}
	table->putObject(object);
}

void PapaXmasElf::putOnBelt(Object *object)
{
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ?!" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	if (!conveyorBelt) {
		std::cerr << "PapaXmasElf: Did sumun' steal me damn (conveyor)"
			" belt again ?!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'conveyorBelt' is NULL" <<
			std::endl;
		return;
	}
	conveyorBelt->putObject(object);
}

Object *PapaXmasElf::takeFromTable(unsigned int idx)
{
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ?!" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return (NULL);
	}
	if (!table) {
		std::cerr << "PapaXmasElf: Where be me table ?!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'table' is NULL" << std::endl;
		return (NULL);
	}
	if (table->_items[idx]->getClassName() == "GiftPaper"
	    || table->_items[idx]->getClassName() == "Box")
		std::cout << "Whistles while working" << std::endl;
	return (table->takeObject(idx));
}

Object *PapaXmasElf::takeFromBelt()
{
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ?!" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return (NULL);
	}
	if (!conveyorBelt) {
		std::cerr << "PapaXmasElf: Did sumun' steal me damn (conveyor)"
			" belt again ?!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'table' is NULL" << std::endl;
		return (NULL);
	}
	if (conveyorBelt->_item->getClassName() == "GiftPaper"
		|| conveyorBelt->_item->getClassName() == "Box")
		std::cout << "Whistles while working" << std::endl;
	return (conveyorBelt->takeObject());
}

Object **PapaXmasElf::look()
{
	unsigned long count = table->_items.size();
	auto array = new Object*[table->_items.size() + 2];
	array[table->_items.size() + 1] = nullptr;
	unsigned int i = 0;

	if (!eyes) {
		std::cerr << "PapaXmasElf: OH GOD SINCE WHEN AM I BLIND ?!" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'eyes' is NULL" << std::endl;
		return (NULL);
	}
	for (i = 0; i < count; i++)
		array[i] = table->_items.at(i);
	array[i] = conveyorBelt->_item;
	return (array);
}

bool PapaXmasElf::makeGift()
{
	if (!table || !conveyorBelt) {
		std::cerr << "PapaXmasElf: Oi! I'm missin' sum furniture !" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'table' or 'conveyorBelt'"
			" is NULL" << std::endl;
		return (false);
	}
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ?!" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return (false);
	}
	if (!canMakeGift()) {
		std::cerr << "PapaXmasElf: Oi! There ain't 'nuff stuff on me"
			" table fer a gift !" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: missing components for gift"<<
			std::endl;
		return (false);
	}
	backpack[0] = getToy();
	backpack[1] = getBox();
	backpack[2] = getGiftPaper();
	((Box *)backpack[1])->openMe();
	((Box *)backpack[1])->wrapMeThat(*backpack[0]);
	((Box *)backpack[1])->closeMe();
	((GiftPaper *)backpack[2])->wrapMeThat(*backpack[1]);
	putOnBelt(backpack[2]);
	pushOutButtonWithHand();
	return (true);
}

bool PapaXmasElf::canMakeGift()
{
	bool paper = false;
	bool box = false;
	bool toy = false;

	if (conveyorBelt->_item) {
		if (conveyorBelt->_item->getClassName() == "GiftPaper")
			paper = true;
		else if (conveyorBelt->_item->getClassName() == "Box")
			box = true;
		else if (conveyorBelt->_item->getClassName() == "Teddy"
			|| conveyorBelt->_item->getClassName() == "LittlePony")
			toy = true;
	}
	for (auto &_item : table->_items) {
		if (_item->getClassName() == "GiftPaper")
			paper = true;
		else if (_item->getClassName() == "Box")
			box = true;
		else if (_item->getClassName() == "Teddy"
			|| _item->getClassName() == "LittlePony")
			toy = true;
	}
	return paper && box && toy;
}

Object *PapaXmasElf::getToy()
{
	if (conveyorBelt->_item != nullptr)
		if (conveyorBelt->_item->getClassName() == "Teddy"
		    || conveyorBelt->_item->getClassName() == "LittlePony")
			return (takeFromBelt());
	if (table) {
		unsigned long count = table->_items.size();
		for (unsigned int i = 0; i < count; i++)
			if (table->_items[i]->getClassName() == "Teddy"
			    || table->_items[i]->getClassName() == "LittlePony")
				return (takeFromTable(i));
	}
	return (NULL);
}

Object *PapaXmasElf::getBox()
{
	if (conveyorBelt->_item != nullptr)
		if (conveyorBelt->_item->getClassName() == "Box")
			return (takeFromBelt());
	if (table) {
		unsigned long count = table->_items.size();
		std::cout << count << std::endl;
		for (unsigned int i = 0; i < count; i++) {
			if (table->_items[i]->getClassName() == "Box")
				return (takeFromTable(i));
		}
	}
	return (NULL);
}

Object *PapaXmasElf::getGiftPaper()
{
	if (conveyorBelt->_item != nullptr)
		if (conveyorBelt->_item->getClassName() == "GiftPaper")
			return (takeFromBelt());
	if (table) {
		unsigned long count = table->_items.size();
		for (unsigned int i = 0; i < count; i++)
			if (table->_items[i]->getClassName() == "GiftPaper")
				return (takeFromTable(i));
	}
	return (NULL);
}

void PapaXmasElf::pushInButtonWithHand(Object *object)
{
	if (!conveyorBelt) {
		std::cerr << "PapaXmasElf: Did sumun' steal me damn (conveyor)"
			" belt again ?!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'conveyorBelt' is NULL" <<
			std::endl;
		return;
	}
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ?!" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	hand->pushInButton(conveyorBelt, object);
}

void PapaXmasElf::pushOutButtonWithHand()
{
	if (!conveyorBelt) {
		std::cerr << "PapaXmasElf: Did sumun' steal me damn (conveyor)"
			" belt again ?!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'conveyorBelt' is NULL" <<
			std::endl;
		return;
	}
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ?!" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	hand->pushOutButton(conveyorBelt);
}

void PapaXmasElf::chainGifts()
{
	while (makeGift());
	std::cout << "o'pa ere's somin' wron' in da box!" << std::endl;
}


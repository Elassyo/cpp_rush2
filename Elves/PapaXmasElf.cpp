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

PapaXmasElf::PapaXmasElf() :
	table(new Table()),
	conveyorBelt(new ConveyorBelt()), eyes(new Eyes()), hand(new Hand())

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

void PapaXmasElf::takeFromTable(unsigned int idx)
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
	if (table->_items[idx])
		std::cout << "Whistles while working" << std::endl;
	heldInHand = table->takeObject(idx);
}

void PapaXmasElf::takeFromBelt()
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
		std::cerr << "PapaXmasElf: ERROR: 'table' is NULL" << std::endl;
		return;
	}
	if (conveyorBelt->_item)
		std::cout << "Whistles while working" << std::endl;
	heldInHand = conveyorBelt->takeObject();
}

Object **PapaXmasElf::look()
{
	auto array = new Object*[10];
	unsigned long count = table->_items.size();

	if (!eyes) {
		std::cerr << "PapaXmasElf: OH GOD SINCE WHEN AM I BLIND ?!" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'eyes' is NULL" << std::endl;
		return (NULL);
	}
	for (unsigned int i = 0; i < count; i++)
		array[i] = table->_items[i];
	return (array);
}

void PapaXmasElf::makeGift()
{
	if (!table || !conveyorBelt) {
		std::cerr << "PapaXmasElf: Oi! I'm missin' sum furniture !" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'table' or 'conveyorBelt'"
			" is NULL" << std::endl;
		return;
	}
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ?!" <<
			std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	if (!canMakeGift()) {
		std::cerr << "PapaXmasElf: Oi! There ain't nuff stuff on me"
			" table fer a gift !" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: missing components for gift"<<
			std::endl;
		return;
	}
	backpack[0] = getToy();
	backpack[1] = getBox();
	std::cout << "Whistles while working" << std::endl;
	backpack[2] = getGiftPaper();
	std::cout << "Whistles while working" << std::endl;
	((Box *)backpack[1])->openMe();
	((Box *)backpack[1])->wrapMeThat(*backpack[0]);
	((Box *)backpack[1])->closeMe();
	((GiftPaper *)backpack[2])->wrapMeThat(*backpack[1]);
	putOnBelt(backpack[2]);
	pushOutButtonWithHand();
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
		else if (conveyorBelt->_item->getClassName() == "Toy")
			toy = true;
	}
	for (auto &_item : table->_items) {
		if (_item->getClassName() == "GiftPaper")
			paper = true;
		else if (_item->getClassName() == "Box")
			box = true;
		else if (_item->getClassName() == "Toy")
			toy = true;
	}
	return paper && box && toy;
}

Object *PapaXmasElf::getToy()
{
	unsigned long count = table->_items.size();

	if (conveyorBelt->_item->getClassName() == "Toy")
		return (conveyorBelt->takeObject());
	else
		for (unsigned int i = 0; i < count; i++)
			if (table->_items[i]->getClassName() == "Toy")
				return (table->takeObject(i));
	std::cerr << "PapaXmasElf: Where are dem damned toys ?!" << std::endl;
	return (NULL);
}

Object *PapaXmasElf::getBox()
{
	unsigned long count = table->_items.size();

	if (conveyorBelt->_item->getClassName() == "Box")
		return (conveyorBelt->takeObject());
	else
		for (unsigned int i = 0; i < count; i++)
			if (table->_items[i]->getClassName() == "Box")
				return (table->takeObject(i));
	std::cerr << "PapaXmasElf: And where am I supposed to put it ?!" <<
		std::endl;
	return (NULL);
}

Object *PapaXmasElf::getGiftPaper()
{
	unsigned long count = table->_items.size();

	if (conveyorBelt->_item->getClassName() == "GiftPaper")
		return (conveyorBelt->takeObject());
	else
		for (unsigned int i = 0; i < count; i++)
			if (table->_items[i]->getClassName() == "GiftPaper")
				return (table->takeObject(i));
	std::cerr <<
		"PapaXmasElf: A gift ain't no good without wrappin' papeh !" <<
		std::endl;
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

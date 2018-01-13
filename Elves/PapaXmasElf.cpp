//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#include <iostream>
#include "PapaXmasElf.hpp"
#include "Toy.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"

void PapaXmasElf::putOnTable(Object *object)
{
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ???!!!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	if (!table) {
		std::cerr << "PapaXmasElf: ERROR: 'table' is NULL" << std::endl;
	}
	table->putObject(object);
}

void PapaXmasElf::putOnBelt(Object *object)
{
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ???!!!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	if (!conveyorBelt) {
		std::cerr << "PapaXmasElf: ERROR: 'table' is NULL" << std::endl;
	}
	conveyorBelt->putObject(object);
}

void PapaXmasElf::takeFromTable(unsigned int idx)
{
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ???!!!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	if (!table) {
		std::cerr << "PapaXmasElf: ERROR: 'table' is NULL" << std::endl;
	}
	heldInHand = table->takeObject(idx);
}

void PapaXmasElf::takeFromBelt()
{
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ???!!!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	if (!conveyorBelt) {
		std::cerr << "PapaXmasElf: ERROR: 'table' is NULL" << std::endl;
	}
	heldInHand = conveyorBelt->takeObject();
}

Object **PapaXmasElf::look()
{
	auto array = new Object*[10];
	unsigned long count = table->_items.size();

	if (!eyes) {
		std::cerr << "PapaXmasElf: OH GOD SINCE WHEN AM I BLIND ???!!!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'eyes' is NULL" << std::endl;
		return (nullptr);
	}
	for (int i = 0; i < count; i++)
		array[i] = table->_items[i];
	return (array);
}

void PapaXmasElf::makeGift()
{
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ???!!!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	if (!canMakeGift()) {
		std::cerr << "PapaXmasElf: Oi! There ain't nuff stuff on me table fer a gift!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: missing components for gift" << std::endl;
		return;
	}
	backpack[0] = getToy();
	backpack[1] = getBox();
	backpack[2] = getGiftPaper();
	((Box *)backpack[1])->wrapMeThat(*backpack[0]);
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
		if (conveyorBelt->_item->getClassName() == "Box")
			box = true;
		if (conveyorBelt->_item->getClassName() == "Toy")
			toy = true;
	}
	for (auto &_item : table->_items) {
		if (_item->getClassName() == "GiftPaper")
			paper = true;
		if (_item->getClassName() == "Box")
			box = true;
		if (_item->getClassName() == "Toy")
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
	return (nullptr);
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
	return (nullptr);
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
	return (nullptr);
}

void PapaXmasElf::pushInButtonWithHand()
{
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ???!!!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	hand->pushInButton(conveyorBelt);
}

void PapaXmasElf::pushOutButtonWithHand()
{
	if (!hand) {
		std::cerr << "PapaXmasElf: OH GOD WHERE ARE MY HANDS ???!!!" << std::endl;
		std::cerr << "PapaXmasElf: ERROR: 'hand' is NULL" << std::endl;
		return;
	}
	hand->pushOutButton(conveyorBelt);
}
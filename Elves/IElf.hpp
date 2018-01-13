//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#ifndef CPP_RUSH2_IELF_HPP
#define CPP_RUSH2_IELF_HPP

#include "Object.hpp"
#include "Hand.hpp"
#include "Eyes.hpp"
#include "Table.hpp"
#include "ConveyorBelt.hpp"
#include "Toy.hpp"

class IElf
{
public :
	IElf() : table(createTable()), conveyorBelt(createConveyorBelt())
	{};

	virtual void putOnTable(Object *object) = 0;
	virtual void putOnBelt(Object *object) = 0;
	virtual void takeFromTable(unsigned int idx) = 0;
	virtual void takeFromBelt() = 0;
	virtual Object **look() = 0;
	virtual void makeGift() = 0;
	virtual bool canMakeGift() = 0;
	virtual void pushInButtonWithHand() = 0;
	virtual void pushOutButtonWithHand() = 0;
	virtual Object *getGiftPaper() = 0;
	virtual Object *getBox() = 0;
	virtual Object *getToy() = 0;

protected :
	Table *table;
	ConveyorBelt *conveyorBelt;
	Eyes *eyes;
	Hand *hand;
	Object *heldInHand;
	auto backpack = new Object*[3];
};

#endif //CPP_RUSH2_IELF_HPP

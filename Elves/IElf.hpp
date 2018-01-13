//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#ifndef CPP_RUSH2_IELF_HPP
#define CPP_RUSH2_IELF_HPP


#include "../Toys/Object.hpp"
#include "../RollingCarpet/Table.hpp"
#include "../RollingCarpet/ConveyorBelt.hpp"
#include "Eyes.hpp"
#include "Hand.hpp"

class IElf
{
public :
	IElf();

	virtual void putOnTable(Object *object) = 0;
	virtual void putOnBelt(Object *object) = 0;
	virtual void takeFromTable(unsigned int idx) = 0;
	virtual void takeFromBelt() = 0;
	virtual Object **look() = 0;
	virtual void makeGift() = 0;
	virtual bool canMakeGift() = 0;
	virtual void pushInButtonWithHand(Object *object) = 0;
	virtual void pushOutButtonWithHand() = 0;
	virtual Object *getGiftPaper() = 0;
	virtual Object *getBox() = 0;
	virtual Object *getToy() = 0;

protected :
	Table *table;
	ConveyorBelt *conveyorBelt;
	Eyes *eyes;
	Hand *hand;
	Object *heldInHand{};
	Object **backpack = new Object*[3];
};

IElf::IElf() : table(new Table()), conveyorBelt(new ConveyorBelt()),
               eyes(new Eyes()), hand(new Hand())
{
}

#endif //CPP_RUSH2_IELF_HPP

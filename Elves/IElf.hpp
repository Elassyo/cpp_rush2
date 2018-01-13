//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#ifndef CPP_RUSH2_IELF_HPP
#define CPP_RUSH2_IELF_HPP

	#include "../Object.hpp"
	#include "../RollingCarpet/Table.hpp"
	#include "../RollingCarpet/ConveyorBelt.hpp"
	#include "Eyes.hpp"
	#include "Hand.hpp"

class IElf {
public :
	~IElf();

	virtual void putOnTable(Object *object) = 0;
	virtual void putOnBelt(Object *object) = 0;
	virtual Object *takeFromTable(unsigned int idx) = 0;
	virtual Object *takeFromBelt() = 0;
	virtual Object **look() = 0;
	virtual bool makeGift() = 0;
	virtual bool canMakeGift() = 0;
	virtual void pushInButtonWithHand(Object *object) = 0;
	virtual void pushOutButtonWithHand() = 0;
	virtual Object *getGiftPaper() = 0;
	virtual Object *getBox() = 0;
	virtual Object *getToy() = 0;
	virtual void chainGifts() = 0;
	Object *heldInHand{};

protected :
	Table *table = new Table();
	ConveyorBelt *conveyorBelt = new ConveyorBelt();
	Eyes *eyes = new Eyes();
	Hand *hand = new Hand();
	Object **backpack = new Object*[3];
};

#endif //CPP_RUSH2_IELF_HPP

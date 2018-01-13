//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#ifndef CPP_RUSH2_PAPAXMASELF_HPP
#define CPP_RUSH2_PAPAXMASELF_HPP

#include "IElf.hpp"

class PapaXmasElf : public IElf
{
public :
	void putOnTable(Object *object) override;
	void putOnBelt(Object *object) override;
	void takeFromTable(unsigned int idx) override;
	void takeFromBelt() override;
	Object **look() override;
	void makeGift() override;
	bool canMakeGift() override;
	void pushInButtonWithHand(Object *object) override;
	void pushOutButtonWithHand() override;
	Object *getGiftPaper() override;
	Object *getBox() override;
	Object *getToy() override;
};


#endif //CPP_RUSH2_PAPAXMASELF_HPP

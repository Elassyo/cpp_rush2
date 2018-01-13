//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// testMain.cpp in cpp_rush2
//

#include "Hand.hpp"
#include "PapaXmasElf.hpp"
#include "../Toys/Teddy.hpp"
#include "../Toys/LittlePony.hpp"
#include "../BoxStory/GiftPaper.hpp"
#include "../BoxStory/Box.hpp"

void unitTest()
{
	Object *SomeBear = new Teddy("chlamydia");
	Object *SomePony = new LittlePony("syphilis");
	auto *elf = new PapaXmasElf();
	Object *SomePaper = new GiftPaper();
	Object *SomeBox = new Box();
	Object **array;

	std::cout << "-- putting stuff on the belt and table --" << std::endl;
	elf->putOnBelt(SomeBear);
	elf->putOnTable(SomePony);
	std::cout << "-- moving stuff around a bit --" << std::endl;
	elf->heldInHand = elf->takeFromBelt();
	std::cout << elf->heldInHand->getClassName() << std::endl;
	elf->putOnTable(elf->heldInHand);
	elf->pushInButtonWithHand(SomePaper);
	elf->heldInHand = elf->takeFromBelt();
	std::cout << elf->heldInHand->getClassName() << std::endl;
	elf->putOnTable(elf->heldInHand);
	elf->pushInButtonWithHand(SomeBox);
	std::cout << "-- looking around --" << std::endl;
	array = elf->look();
	for (int i = 0; array[i] != nullptr; i++)
		std::cout << array[i]->getClassName() << std::endl;
	std::cout << "-- trying to make a gift" << std::endl;
	elf->makeGift();
}

int main()
{
	unitTest();
	return (0);
}

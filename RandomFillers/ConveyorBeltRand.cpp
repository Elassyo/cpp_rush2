//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#include "ConveyorBeltRand.hpp"
#include "../Toys/Teddy.hpp"
#include "../Toys/LittlePony.hpp"
#include "../BoxStory/GiftPaper.hpp"
#include "../BoxStory/Box.hpp"

ConveyorBeltRand::ConveyorBeltRand()
{
	long i = (random() % 4);

	if (i == 0)
		conveyorBelt._item = new Teddy("Richard");
	if (i == 1)
		conveyorBelt._item = new LittlePony("Billy la racaille");
	if (i == 2)
		conveyorBelt._item = new GiftPaper();
	if (i == 3)
		conveyorBelt._item = new Box();
}
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
	int i = (int)random() % 4;

	switch (i) {
	case 0:
		_item = new Teddy("Richard");
		break;
	case 1:
		_item = new LittlePony("Billy la racaille");
		break;
	case 2:
		_item = new GiftPaper();
		break;
	default:
		_item = new Box();
	}
}

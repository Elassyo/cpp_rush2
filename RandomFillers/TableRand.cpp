//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#include "TableRand.hpp"
#include "../Toys/Teddy.hpp"
#include "../Toys/LittlePony.hpp"
#include "../BoxStory/GiftPaper.hpp"
#include "../BoxStory/Box.hpp"

TableRand::TableRand()
{
	for (int w = 0; w < 10; w++) {
		long i = (random() % 4);
		if (i == 0)
			_items.push_back(new Teddy("Richard"));
		else if (i == 1)
			_items.push_back(new LittlePony("Billy la racaille"));
		else if (i == 2)
			_items.push_back(new GiftPaper());
		else if (i == 3)
			_items.push_back(new Box());
	}
}
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
			table._items[i] = new Teddy("Richard");
		if (i == 1)
			table._items[i] = new LittlePony("Billy la racaille");
		if (i == 2)
			table._items[i] = new GiftPaper();
		if (i == 3)
			table._items[i] = new Box();
	}
}
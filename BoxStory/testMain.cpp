/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** main.cpp
*/

#include "Wrap.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "../Toys/Teddy.hpp"

Object *MyUnitTests(Object **items)
{
	((Teddy *)(items[0]))->isTaken();
	std::cout << "-- opening empty and already open wrap --" << std::endl;
	((Box *)(items[1]))->openMe();
	std::cout << "-- adding to closed box --" << std::endl;
	((Box *)(items[1]))->closeMe();
	((Box *)(items[1]))->wrapMeThat(*items[0]);
	std::cout << "-- opening empty and closed box and adding item --" << std::endl;
	((Box *)(items[1]))->openMe();
	((Box *)(items[1]))->wrapMeThat(*items[0]);
	std::cout << "-- adding second item to wrap --" << std::endl;
	((Box *)(items[1]))->wrapMeThat(*items[0]);
	((Box *)(items[1]))->closeMe();
	((GiftPaper *)(items[2]))->wrapMeThat(*items[1]);
	return (items[2]);
}
/*
int main()
{
	auto items = new Object*[4];
	items[0] = new Teddy("cuddles");
	items[1] = new Box();
	items[2] = new GiftPaper();
	items[3] = NULL;
	std::cout << "test beginning" << std::endl;
	MyUnitTests(items);
}*/
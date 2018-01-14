//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#ifndef CPP_RUSH2_MAGICALCARPET_HPP
	#define CPP_RUSH2_MAGICALCARPET_HPP

	#include "ConveyorBeltRand.hpp"
	#include "../WarpMachine/WarpClient.hpp"

class MagicalCarpet : public ConveyorBeltRand
{
public:
	void pressOut();

private:
	WarpClient _magicSock;
};

#endif //CPP_RUSH2_MAGICALCARPET_HPP

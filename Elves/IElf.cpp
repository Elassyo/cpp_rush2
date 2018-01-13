/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** IElf interface implementation
*/

#include "IElf.hpp"

IElf::IElf() :
	table(new Table()),
	conveyorBelt(new ConveyorBelt()), eyes(new Eyes()), hand(new Hand())
{
}

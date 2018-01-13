//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#include <iostream>
#include "Object.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"

Object **MyUnitTests()
{
	auto array = new Object*[2];
	array[0] = new LittlePony("happy pony");
	array[1] = new Teddy("cuddles");
	return (array);
}
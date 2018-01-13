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

/*
int main()
{
	Object **array = MyUnitTests();

	std::cout << "DA PONY IS A " << array[0]->getClassName()
	          << " N HES NAMED " << ((Toy *)array[0])->getName() << std::endl;
	std::cout << "NOW YOU YELL " << ((Toy *)array[0])->getName() << ": ";
	((Toy *)array[0])->isTaken();
	std::cout << "DA TEDDY IS A " << array[1]->getClassName()
	          << " N HES NAMED " << ((Toy *)array[1])->getName() << std::endl;
	std::cout << "NOW YOU YELL " << ((Toy *)array[1])->getName() << ": ";
	((Toy *)array[1])->isTaken();
	delete[] array;
	return (0);
}
*/
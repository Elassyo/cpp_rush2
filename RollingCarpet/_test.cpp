//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// testMain.cpp in cpp_rush2
//

#include "ConveyorBelt.hpp"
#include "Table.hpp"
#include "../Toys/Teddy.hpp"
#include "../Toys/LittlePony.hpp"

void UnitTests()
{
	Object *SomeBear = new Teddy("chlamidia");
	Object *SomePony = new LittlePony("syphilis");
	Table *table = new Table();
	ConveyorBelt *conveyorBelt = new ConveyorBelt();

	std::cout << "-- Testing stuff with tables --" << std::endl;
	std::cout << "Putting bear on the table" << std::endl;
	table->putObject(SomeBear);
	std::cout << "Putting pony on the table" << std::endl;
	table->putObject(SomePony);
	std::cout << "Taking bear off the table" << std::endl;
	SomeBear = table->takeObject(1);
	std::cout << "Taking pony off the table\n" << std::endl;
	SomePony = table->takeObject(0);
	std::cout << "-- Testing stuff with conveyor belts --" << std::endl;
	std::cout << "Putting bear on the conveyorBelt" << std::endl;
	conveyorBelt->putObject(SomeBear);
	std::cout << "Putting pony on the conveyorBelt" << std::endl;
	conveyorBelt->putObject(SomePony);
	std::cout << "Taking bear off the conveyorBelt\n" << std::endl;
	SomeBear = conveyorBelt->takeObject();
	std::cout << "-- Testing if the toys still exist --" << std::endl;
	std::cout << SomeBear->getClassName() << std::endl;
	((Teddy *)SomeBear)->isTaken();
	std::cout << SomePony->getClassName() << std::endl;
	((LittlePony *)SomePony)->isTaken();
}

int main()
{
	UnitTests();
	return (0);
}

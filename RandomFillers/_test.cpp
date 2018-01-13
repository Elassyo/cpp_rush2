//
// Created by alexandre on 13/01/18.
//

#include "TableRand.hpp"
#include "ConveyorBeltRand.hpp"

int main()
{
	srand(52637);
	TableRand table;
	ConveyorBeltRand belt;

	std::cout << "belt : " << belt._item->getClassName() << std::endl;
	for (Object *obj : table._items)
		std::cout << "table : " << obj->getClassName() << std::endl;
}
//
// Created by alexandre on 13/01/18.
//

#include "../RollingCarpet/ConveyorBelt.hpp"
#include "../BoxStory/Box.hpp"

int main()
{
	Box box;
	ConveyorBelt belt;
	belt.putObject(&box);
	belt.pressOut();
}
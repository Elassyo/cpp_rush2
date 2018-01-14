//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#include "MagicalCarpet.hpp"

void MagicalCarpet::pressOut()
{
        if (!this->_item) {
                std::cerr << this->_className << " : ERROR : There is no object"
                        " to be sent to Santa !" << std::endl;
                return;
        }
        _magicSock.receiveAddr();
        _magicSock.sendMessage(this->_item->serialize("Gift")->toString());
        this->_item = nullptr;
}

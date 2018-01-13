//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#ifndef CPP_RUSH2_LITTLEPONY_HPP
#define CPP_RUSH2_LITTLEPONY_HPP

#include "Toy.hpp"

class LittlePony : public Toy
{
public :
    LittlePony(std::string name);
    ~LittlePony();

    void isTaken();
};

#endif //CPP_RUSH2_LITTLEPONY_HPP

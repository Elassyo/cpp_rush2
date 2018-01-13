//
// EPITECH PROJECT, 2018
// Project : cpp_rush2
// File description:
// Default header for project cpp_rush2
//

#ifndef CPP_RUSH2_OBJECT_HPP
#define CPP_RUSH2_OBJECT_HPP

#include <string>

class Object
{
public :
    explicit Object(std::string _className);
    virtual ~Object();

    const std::string &getClassName() const;

protected :
    std::string className;
};


#endif //CPP_RUSH2_OBJECT_HPP

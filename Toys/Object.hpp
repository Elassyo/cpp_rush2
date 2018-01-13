//
// EPITECH PROJECT, 2018
// That's the fucking cpp_rush2
// File description:
// i don't give a fuck that's the default header
//

#ifndef CPP_RUSH2_OBJECT_HPP
#define CPP_RUSH2_OBJECT_HPP

#include <string>

class Object
{
public :
    explicit Object(std::string _className);
    virtual ~Object();

    std::string getClassName() const;

private :
    std::string className;
};


#endif //CPP_RUSH2_OBJECT_HPP

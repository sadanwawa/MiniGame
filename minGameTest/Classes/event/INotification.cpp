
#include <iostream>

#include "INotification.h"

const std::string csstr = "NULL";

std::string const& INotification::getName(void) const{
    return csstr;
}
std::string const& INotification::getType(void) const{
    return csstr;
}
std::string INotification::toString(void) const{
    return csstr;
}

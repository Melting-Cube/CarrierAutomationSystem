/***************************************************************
 * File: inputInstructions.cpp
 * Author: cube
 * Purpose: class to read instructions to execute
 ***************************************************************/

#include "systemList.h"
#include <iostream>

std::string SystemList :: getSystem(int sequence)
{
    std::string system;
    system = csv.at(sequence + 2).at(0);
    return system;
}

int SystemList :: getTotalJumps(){
    return csv.size() - 2;
}
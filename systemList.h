/***************************************************************
 * File: systemList.h
 * Author: cube
 * Purpose: read instructions from input and execute
 ***************************************************************/

#ifndef SYSTEMLIST_H
#define SYSTEMLIST_H

#include "readInstructions.h"
#include <iostream>
#include <string>

class SystemList : public ReadInstructions
{
  private:
    int totalJumps;

  public:
    SystemList(std::string instructionPath) : ReadInstructions(instructionPath) {}

    std::string getSystem(int sequence);
    int getTotalJumps();

};

#endif
/***************************************************************
 * File: inputInstructions.h
 * Author: cube
 * Purpose: read instructions from input and execute
 ***************************************************************/

#ifndef INPUTINSTRUCTIONS_H
#define INPUTINSTRUCTIONS_H

#include "readInstructions.h"
#include "systemList.h"
#include <string>

class InputInstructions : public ReadInstructions
{
  private:
    int jumpsCompleted;
    SystemList sysList;

  public:
    InputInstructions(std::string *sysListPath)
    : sysList(*sysListPath)
    , jumpsCompleted(0) {}

    void runInstructions();

};

#endif
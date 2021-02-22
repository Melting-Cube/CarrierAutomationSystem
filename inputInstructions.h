/***************************************************************
 * File: inputInstructions.h
 * Author: cube
 * Purpose: read instructions from input and execute
 ***************************************************************/

#ifndef INPUTINSTRUCTIONS_H
#define INPUTINSTRUCTIONS_H

#include "readInstructions.h"
#include "systemList.h"

class InputInstructions : public ReadInstructions
{
  private:
    int jumpsCompleted;
    SystemList *sysList;

  public:
    InputInstructions(SystemList *sysList) : sysList(sysList) {jumpsCompleted = 0;}
    InputInstructions(std::string instructionPath) : ReadInstructions(instructionPath) 
      {jumpsCompleted = 0;}

    void runInstructions();

};

#endif
/***************************************************************
 * File: readInstructions.h
 * Author: cube
 * Purpose: class to read instructions to execute
 ***************************************************************/
#ifndef READINSTRUCTIONS_H
#define READINSTRUCTIONS_H

#include <string>
#include <vector>

class ReadInstructions
{
  private:
    std::string instructionPath;


    std::vector<std::vector<std::string>> parseInstructions();
    std::string trim(std::string text, char cut);

  protected:
    std::vector<std::vector<std::string>> csv;
    float delay;

  public:
    // constructors
    ReadInstructions() 
      : instructionPath("instructions.csv"), delay(1)
    {
      csv = parseInstructions();
    }
    ReadInstructions(std::string instructionPath)
      : instructionPath(instructionPath), delay(1)
    {
      csv = parseInstructions();
    }

    // other public methods
    std::string getInstructionPath() const { return instructionPath; }

    void displayInstructions();

};

#endif
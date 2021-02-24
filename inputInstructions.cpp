 /***************************************************************
 * File: inputInstructions.cpp
 * Author: cube
 * Purpose: class to read instructions to execute
 ***************************************************************/

#include "inputInstructions.h"
#include "keyboard.h"
#include <cstdlib>
#include <iostream>


void InputInstructions :: runInstructions()
{
    // exit if the carrier is done jumpng
    if (jumpsCompleted >= sysList.getTotalJumps())
        exit(0);
    
   //make keyboard object to be able to run cmd
   Keyboard key;

   // make vars
   std::string condition;
   std::string action;

   //focuses the right window 
   key.focusWindow();
            
    // go through every row 
    for (int i = 0; i < csv.size(); i++)
    {
        condition = csv.at(i).at(0);
        action = csv.at(i).at(1);

        if (condition == "pressKey")
        {
            key.waitForWindow();
            key.pressKey(action);
        }
        else if (condition == "time")
            sleep(std::stoi(action));
        else if (condition == "type")
        {
            key.waitForWindow();
            key.type(action);
        }
        else if (condition == "jump")
        {
            key.waitForWindow();
            key.type(sysList.getSystem(jumpsCompleted));
        }

        //defalut delay to have between instruction press
        sleep(delay);
    }

    //add to the complete jumps
    jumpsCompleted++;
   
    return;
}
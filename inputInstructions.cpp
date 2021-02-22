/***************************************************************
 * File: inputInstructions.cpp
 * Author: cube
 * Purpose: class to read instructions to execute
 ***************************************************************/

#include "inputInstructions.h"
#include "keyboard.h"
#include <iostream>


void InputInstructions :: runInstructions()
{
   //make keyboard object to be able to run cmd
   Keyboard key;

   // make vars
   std::string condition;
   std::string action;

   //focuses the right window 
    for (key.focusWindow(); jumpsCompleted < sysList->getTotalJumps(); jumpsCompleted++)
    {
        if (jumpsCompleted > 0)
            sleep(1320);

            
        // go through every row 
        for (int i = 0; i < csv.size(); i++)
        {
            condition = csv.at(i).at(0);
            action = csv.at(i).at(1);

            if (condition == "pressKey"){
                key.waitForWindow();
                std::cout << "sent key " << action << std::endl;
                key.pressKey(action);
            }
            else if (condition == "time")
                sleep(std::stoi(action));
            else if (condition == "type")
                key.type(action);
            else if (condition == "jump")
                key.type(sysList->getSystem(jumpsCompleted));

            std::cout << "round " << i << std::endl;
            //defalut delay to have between instruction press
            sleep(delay);
        }



    }
   
    return;
}
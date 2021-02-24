 /***************************************************************
 * File: fuelInstructions.cpp
 * Author: cube
 * Purpose: class to read instructions to execute
 ***************************************************************/

#include "fuelInstructions.h"
#include "keyboard.h"
#include <iostream>
#include <math.h>
#include <ostream>


void FuelInstructions :: runInstructions()
{
   std::cout << fuelLevel << " | " << cargoSize << " | " << commodities << std::endl;
   // return if carrier is full
   if (fuelLevel == 1000)
      return;

   // return if ship has no cargo
   if (cargoSize <= 0)
      return;

   // return if there is no commodies in market
   if (commodities <= 0)
      return;

   //make keyboard object to be able to run cmd
   Keyboard key;

   // make vars
   std::string condition;
   std::string action;

   //focuses the right window 
   key.focusWindow();

   //if there needs to be multiple trips
   int rounds = ceil(((float)1000 - (float)fuelLevel) / ((float)cargoSize - (float)1));
   for (int i = 0; i < rounds || i < 10; i++)
   {
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
         else if (condition == "selectTrit")
         {
            //go up only the right ammount
            for (int i = 0; i < commodities; i++)
            {
               key.pressKey(action);
            }
         }
         else if (condition == "collectCargo")
         {
            //hold to max out cargo
            int time = cargoSize;
            if (cargoSize > 10)
               time = (int)cargoSize / 10;
            key.holdKey(action, time);
         }
         else if (condition == "notEnough")
         {
            key.pressKey(action);
            // if (cargoSize <= 1000 - fuelLevel)
            //    key.pressKey(action);
         }
      
         //defalut delay to have between instruction press
         sleep(delay);
      }
   }
   return;
}

 /***************************************************************
 * Function: setCargoSize
 * Description: sets the cargo size
 ***************************************************************/
void FuelInstructions :: setCargoSize(const int cargoSize)
{
   this->cargoSize = cargoSize;
   return;
}

 /***************************************************************
 * Function: setCommodities
 * Description: sets the commodity amount
 ***************************************************************/
void FuelInstructions :: setCommodities(const int commodities)
{
   this->commodities = commodities;
   return;
}
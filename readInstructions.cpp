/***************************************************************
 * File: readInstructions.cpp
 * Author: cube
 * Purpose: class to read instructions to execute
 ***************************************************************/

#include "readInstructions.h"
#include "keyboard.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>

/***************************************************************
 * Function: parseInstructions()
 * Description: opens and outputs the instructions
 ***************************************************************/
std::vector<std::vector<std::string>> ReadInstructions :: parseInstructions()
{
   std::ifstream fin(instructionPath, std::ios::in);
   // if file fails
   if (fin.fail()){
      std::cout << "file could not be opened, aborting.";
      exit(1);
   }
      
   // set variables for properly reading csv
   std::string line, word, temp;
   std::vector<std::vector<std::string>> csv;

   // read the csv
   for (int i = 0; !fin.eof(); i++) {

      
      // read an entire row and store it in a string var 'line'
      getline(fin, line);
      
      if(!line.length())
         break;

      // segment fault cringe
      csv.resize(i+1);
      // break words
      std::stringstream s(line);

      //store the values in vector row
      while (getline(s, word, ',')) {
         word = trim(word, '\"');
         csv.at(i).push_back(word);
      }

   }

   //close file
   fin.close();

   return csv;
}

/***************************************************************
 * Function: displayInstructions()
 * Description: opens and outputs the instructions
 ***************************************************************/
void ReadInstructions :: displayInstructions()
{
   for (int i = 0; i < csv.size(); i++)
   {
      std::cout << csv.at(i).at(0) << "|" << csv.at(i).at(1) << std::endl;
   }

   return;
}

/***************************************************************
 * Function: trim()
 * Description: trims whitspace
 ***************************************************************/
std::string ReadInstructions :: trim(std::string text, char cut)
{
   if(text[0] == cut)
   {
      text.erase(0,1);
   }
   if(text[text.length() - 1] == cut)
   {
     text.erase(text.length() - 1, 1);
   }
   return text;
}

/***************************************************************
 * Function: runinstructions()
 * Description: runs the instructions provided in the csv
 ***************************************************************/
void ReadInstructions :: runInstructions()
{
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
      
      //defalut delay to have between instruction press
      sleep(delay);
   }
   return;
}
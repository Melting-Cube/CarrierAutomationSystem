/***********************************************************************
* Program:
*    Carrier Automation System
* Author:
*    Cube
* Summary: 
*    Make the jumps easy and let the program do it while you sleep.
*    With things like tritium refuel and optimal jump timings, you
*    can now grind less and actually get sleep or work not game.
************************************************************************/

#include "inputInstructions.h"
#include "readInstructions.h"
#include <cctype>
#include <cstdio>
#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unistd.h>
// #include <stdio.h>
#include <sstream>
#include "updateListener.h"

/**********************************************************************
 * gets the jump path for the user
 ***********************************************************************/
void getJumpPath(std::string* jumpPath)
{
   std::cout << "Please enter your full file path to the spansh csv:\n";
   do {
   getline(std::cin, *jumpPath);
   } while(!jumpPath->size());

   //trim whitspace
   while( !jumpPath->empty() && std::isspace( jumpPath->back() ) ) jumpPath->pop_back();
   while( !jumpPath->empty() && std::isspace( jumpPath->front() ) ) jumpPath->erase(jumpPath->begin());
   
   std::cout << *jumpPath;
   return;
}

/**********************************************************************
 * gets the amout of commodities in user carrier
 ***********************************************************************/
int getCommodities()
{
   std::string option;
   int commodities = 0;

   while (true) 
   {
      std::cout << "Enable automatic refuel? Y/N: ";
      std::cin >> option;
      std::cin.clear();

      //they want the aut refill
      if (tolower(option.at(0)) == 'y')
      {
         // get number of commodities on carrier
         std::cout << "Please enter the number of unique commodities stored in your carrier: ";
         while (!(std::cin >> commodities))
         {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Wrong input. Please enter an integer: ";
         }

         //warn them to put trit in cargo
         std::cout << "refuel will only work if you have at lease one tritium in your cargo,/n"
                   << "please set that up and press enter when ready./n";
         std::cin.ignore();

         return commodities;
      
      }

      //if they do not want automatic refuel
      else if (tolower(option.at(0) == 'n'))
      {
         return 0;
      }
   }
   return commodities;
}

/**********************************************************************
 * reload the game, this starts everything
 ***********************************************************************/
void reloadGame(){
   ReadInstructions reload("./reloadGame.csv");
   reload.runInstructions();

   return;
}

/**********************************************************************
 * call the journal update listener and watch game events
 ***********************************************************************/
void callUpdateListener(std::string* sysListPath, const int commodities){
   // Create the file system watcher instance
   // efsw::FileWatcher allow a first boolean parameter that indicates if it should start with the generic file watcher instead of the platform specific backend
   efsw::FileWatcher * fileWatcher = new efsw::FileWatcher();
   std::string filepath = "/home/brandon/.local/share/Steam/steamapps/compatdata/359320/pfx/drive_c/users/steamuser/Saved Games/Frontier Developments/Elite Dangerous/";

   // Create the instance of your efsw::FileWatcherListener implementation
   UpdateListener * listener = new UpdateListener(filepath, sysListPath, -1, commodities);

   efsw::WatchID watchID = fileWatcher->addWatch( filepath, listener, true );

   fileWatcher->watch();

   // delete fileWatcher;
   // delete listener;

   return;
}

/**********************************************************************
 * Control the events happening
 ***********************************************************************/
int main()
{

   std::string jumpPath;
   getJumpPath(&jumpPath);
   int commodities = getCommodities();

   
   callUpdateListener(&jumpPath, commodities);

   reloadGame();

   //end this program anytime by typing end
   std::cout << "end this program anytime by typing end\n";
   std::string end;
   do{
      std::cin >> end;
   } while(end != "end");
   
   return 0;
}

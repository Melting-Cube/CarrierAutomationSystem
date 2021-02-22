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
#include <iostream>
#include <ostream>
#include <string>
#include <unistd.h>
// #include <stdio.h>
#include "systemList.h"
#include "updateListener.h"
#include "jsonParse.h"

/**********************************************************************
 * 
 ***********************************************************************/
void callUpdateListener(){
   // Create the file system watcher instance
   // efsw::FileWatcher allow a first boolean parameter that indicates if it should start with the generic file watcher instead of the platform specific backend
   efsw::FileWatcher * fileWatcher = new efsw::FileWatcher();
   std::string filepath = "/home/brandon/.local/share/Steam/steamapps/compatdata/359320/pfx/drive_c/users/steamuser/Saved Games/Frontier Developments/Elite Dangerous/";

   // Create the instance of your efsw::FileWatcherListener implementation
   UpdateListener * listener = new UpdateListener(filepath);

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

   //SystemList sysList("../../../Downloads/fleet-carrier-San Tu-HIP 54597-405AA34E-711A-11EB-8498-0FD994EB4526.csv");
   // InputInstructions run(&sysList);

   // std::cout << run.getInstructionPath() << std::endl;

   callUpdateListener();

   // sysList.displayInstructions();

   // run.runInstructions();
   // system("cmd_output=`xdotool search --name \"Elite - Dangerous\"` && xdotool windowfocus $cmd_output");

   //end this program anytime by typing end
   std::cout << "end this program anytime by typing end\n";
   std::string end;
   do{
      std::cin >> end;
   } while(end != "end");
   
   return 0;
}

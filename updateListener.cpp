/***************************************************************
 * File: updateListener.cpp
 * Author: cube
 * Purpose: watch for events
 ***************************************************************/

#include "updateListener.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "jsonParse.h"
#include "lib/efsw/include/efsw/efsw.hpp"

void UpdateListener :: handleFileAction( efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename )
{
    if (filename.find(".log") != std::string::npos)
    {
        if (this->filename != filename)
        {
            // if the file is already open
            if (jsonParse.isFileOpen())
                jsonParse.closeFile();

            // if the file is new or not
            if (action == efsw::Actions::Add) {
                sleep(10);
                return;
            }
            else if (action == efsw::Actions::Modified) {
                this->filename = filename;
                jsonParse.openJson(filename, filepath);
            }
        }

        handleJournalEvent();
    }
    return;
}

void UpdateListener :: handleJournalEvent()
{
    jsonParse.readJson(&event);

    //look for a match that means something
    if (event.get("event", false) == "CarrierJumpRequest")
    {
        std::cout << "\njump request made "
                  << event.get("Body", "\"oof, dis is fucked\"").asString()
                  << std::endl;
        fuelInstructions.runInstructions();
    }
    else if (event.get("event", false) == "CarrierJump")
    {
        event.get("StarSystem", "M O N K E").asString();
        sleep(rand() % 3 + 5);
        inputInstructions.runInstructions();
    }
    else if (event.get("event", false) == "CarrierStats")
    {
        fuelInstructions.setFuelLevel(event.get("FuelLevel", 1000).asInt());
    }
    else if (event.get("event", false) == "Loadout")
    {
        std::cout << event.get("CargoCapacity", 0).asInt();
        fuelInstructions.setCargoSize(event.get("CargoCapacity", 0).asInt());
        inputInstructions.runInstructions();
    }
    


    return;
}
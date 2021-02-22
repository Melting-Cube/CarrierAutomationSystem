/***************************************************************
 * File: updateListener.cpp
 * Author: cube
 * Purpose: watch for events
 ***************************************************************/

#include "updateListener.h"
#include <iostream>
#include "jsonParse.h"

void UpdateListener :: handleFileAction( efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename )
{
    if (filename.find(".log") != std::string::npos)
    {
        if (this->filename != filename)
        {
            // if the file is already open
            if (jsonParse.isFileOpen())
                jsonParse.closeFile();
            // open the new json file
            jsonParse.openJson(filename, filepath);

            this->filename = filename;
        }

        jsonParse.readJson();

        handleJournalEvent();
    }
    return;
}

void UpdateListener :: handleJournalEvent()
{
    std::cout << "found\n";
    return;
}
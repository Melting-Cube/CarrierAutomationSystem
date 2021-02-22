/***************************************************************
 * File: updateListener.cpp
 * Author: cube
 * Purpose: watch for events
 ***************************************************************/

#include "updateListener.h"
#include <iostream>
#include <unistd.h>
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
    return;
}
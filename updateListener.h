/***************************************************************
 * File: updateListener.h
 * Author: cube
 * Purpose: watch for events
 ***************************************************************/
#ifndef UPDATELISTENER_H
#define UPDATELISTENER_H


#include <json/value.h>
#include <string>
#include "lib/efsw/include/efsw/efsw.hpp"
#include "jsonParse.h"
#include "inputInstructions.h"
#include "fuelInstructions.h"

class UpdateListener : public efsw::FileWatchListener
{
  private: 
    std::string filename;
    std::string filepath;
    JsonParse jsonParse;
    Json::Value event;
    FuelInstructions fuelInstructions;
    InputInstructions inputInstructions;

  public:
    UpdateListener(std::string filepath, std::string* sysListPath, const int fuelLevel, const int commodities)
    : filepath(filepath)
    , inputInstructions(sysListPath)
    , fuelInstructions(commodities) {}

    void handleFileAction( efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename );
    void handleJournalEvent();
};

#endif
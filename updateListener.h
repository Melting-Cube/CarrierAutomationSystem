/***************************************************************
 * File: updateListener.h
 * Author: cube
 * Purpose: watch for events
 ***************************************************************/
#ifndef UPDATELISTENER_H
#define UPDATELISTENER_H


#include <string>
#include "lib/efsw/include/efsw/efsw.hpp"
#include "jsonParse.h"

class UpdateListener : public efsw::FileWatchListener
{
  private: 
    std::string filename;
    std::string filepath;
    JsonParse jsonParse;

  public:
    UpdateListener(std::string filepath) : filepath(filepath) {}
    void handleFileAction( efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename );

    void handleJournalEvent();

    


};

#endif
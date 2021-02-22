/***************************************************************
 * File: jsonParse.h
 * Author: cube
 * Purpose: parse the json that is mainly elite journal lines
 ***************************************************************/
#ifndef JSONPARSE_H
#define JSONPARSE_H


#include <string>
#include <fstream>
#include <json/value.h>

class JsonParse
{
  private: 
    std::ifstream fin;

  public:
    JsonParse(){}
    ~JsonParse(){ fin.close(); }

    void openJson(std::string filename, std::string filepath);
    void readJson(Json::Value* event);

    bool isFileOpen();
    void closeFile();
};

#endif
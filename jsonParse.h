/***************************************************************
 * File: jsonParse.h
 * Author: cube
 * Purpose: parse the json that is mainly elite journal lines
 ***************************************************************/
#ifndef JSONPARSE_H
#define JSONPARSE_H


#include <string>
#include <fstream>

class JsonParse
{
  private: 
    std::ifstream fin;

  public:
    JsonParse(){}
    ~JsonParse(){ fin.close(); }

    void openJson(std::string filename, std::string filepath);
    void readJson();

    bool isFileOpen();
    void closeFile();
};

#endif
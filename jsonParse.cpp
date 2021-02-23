/***************************************************************
 * File: parseJson.cpp
 * Author: cuparse the jsaon and look for keywords
 ***************************************************************/

#include "jsonParse.h"
#include <X11/X.h>
#include <fstream>
#include <ios>
#include <iostream>
#include <json/json.h>
#include <json/reader.h>
#include <json/value.h>
#include <ostream>
#include <string>
#include <sstream>

/************************************************************************
 * open the file
 ************************************************************************/
void JsonParse :: openJson(std::string filename, std::string filepath)
{
    std::string fullFilePath = filepath + filename;

    fin.open(fullFilePath);

    std::cout << fullFilePath << std::endl;
}


/************************************************************************
 * Is read the last line of the file
 ************************************************************************/
int JsonParse :: readJson(Json::Value* event)
{
    // go to one spot before the EOF
    if(fin.is_open()) {
        //Got to the last character before EOF
        fin.seekg(-1, std::ios_base::end); 
        
        if(fin.peek() == '\n')
        {
            //Start searching for \n occurrences
            fin.seekg(-1, std::ios_base::cur);
            for(int i = fin.tellg(); i > 0; i--)
            {
                if(fin.peek() == '\n')
                {
                    //Found
                    fin.get();
                    break;
                }
                //move one character back
                fin.seekg(i, std::ios_base::beg);
            }
        }

        //make objects to read the line as json
        Json::CharReaderBuilder builder;
        Json::CharReader * reader = builder.newCharReader();
        std::string errors;

        std::string lastLine;
        getline(fin,lastLine);

        //parse the lines
        bool parsingSuccessful =
            reader->parse(lastLine.c_str(), lastLine.c_str() + lastLine.size(), event, &errors );
        
        //delete the reader object
        delete reader;

        //did succede?
        if(!parsingSuccessful)
        {
            // std::cout << lastLine << std::endl << errors << std::endl;
            return 1;
        }
            // std::cout << "\n\n" << event->get("event", false) << "\n\n\n\n";
            // std::cout << ;

        // std::cout << "Result: " << lastLine << '\n';

    }
    return 0;
}

/************************************************************************
 * return if the file is open
 ************************************************************************/
bool JsonParse :: isFileOpen()
{
    return fin.is_open();
}

/************************************************************************
 * close the file
 ************************************************************************/
void JsonParse :: closeFile()
{
    fin.close();
    return;
}

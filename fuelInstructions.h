/***************************************************************
 * File: fuelInstructions.h
 * Author: cube
 * Purpose: read instructions from Fuel and execute
 ***************************************************************/

#ifndef FUELINSTRUCTIONS_H
#define FUELINSTRUCTIONS_H

#include "readInstructions.h"
#include "systemList.h"

class FuelInstructions : public ReadInstructions
{
  private:
    const int fuelLevel;
    int cargoSize;
    int commodities;

  public:
    FuelInstructions(int commodities)
    : ReadInstructions("fuelInstructions.csv")
    , fuelLevel(844)
    , cargoSize(0)
    , commodities(commodities) {}

    FuelInstructions(int commodities, int cargoSize)
    : ReadInstructions("fuelInstructions.csv")
    , fuelLevel(844)
    , cargoSize(cargoSize)
    , commodities(commodities) {}

    FuelInstructions(int commodities, std::string instructionPath)
    : ReadInstructions(instructionPath)
    , fuelLevel(844)
    , cargoSize(0)
    , commodities(commodities) {}

    FuelInstructions(int commodities, std::string instructionPath, int cargoSize)
    : ReadInstructions(instructionPath)
    , fuelLevel(844)
    , cargoSize(cargoSize)
    , commodities(commodities) {}

    void runInstructions();

    int getFuelLevel() { return fuelLevel; }
    void setCargoSize(const int cargoSize);
    int getCargoSize() { return cargoSize; }
    void setCommodities(const int commodities);
    int getCommodities() { return commodities; }

};

#endif
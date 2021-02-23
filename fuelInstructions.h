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
    int fuelLevel;
    int cargoSize;
    int commodities;

  public:
    FuelInstructions(int commodities)
    : ReadInstructions("fuelInstructions.csv")
    , cargoSize(0)
    , commodities(commodities) {}

    FuelInstructions(int commodities, int cargoSize)
    : ReadInstructions("fuelInstructions.csv")
    , cargoSize(cargoSize)
    , commodities(commodities) {}

    FuelInstructions(int commodities, std::string instructionPath)
    : ReadInstructions(instructionPath)
    , cargoSize(0)
    , commodities(commodities) {}

    FuelInstructions(int commodities, std::string instructionPath, int cargoSize)
    : ReadInstructions(instructionPath)
    , cargoSize(cargoSize)
    , commodities(commodities) {}

    void runInstructions();

    void setFuelLevel(const int fuelLevel);
    int getFuelLevel() { return fuelLevel; }
    void setCargoSize(const int cargoSize);
    int getCargoSize() { return cargoSize; }
    void setCommodities(const int commodities);
    int getCommodities() { return commodities; }

};

#endif
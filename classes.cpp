/* ****************************************
Filename: classes.cpp
Author: CosmicGrace (https://github.com/CosmicGrace)

Purpose:
    This file will be to implement class
    methods

**************************************** */

// So the program isn't confused
#include "cover.h"


/* -----------------------------

    WeatherData Constructors

----------------------------- */
WeatherData::WeatherData() 
    : currentTemp(0), minTemp(0), maxTemp(0), location(""), description(""), timestamp(0) {}

WeatherData::WeatherData(double curr, double min, double max, std::string loc, std::string desc, long time)
    : currentTemp(curr), minTemp(min), maxTemp(max), location(loc), description(desc), timestamp(time) {}



/* -----------------------------

    Getters

----------------------------- */
double WeatherData::getCurrentTemp() const { return currentTemp; }
double WeatherData::getMinTemp() const { return minTemp; }
double WeatherData::getMaxTemp() const { return maxTemp; }
std::string WeatherData::getLocation() const { return location; }
std::string WeatherData::getDescription() const { return description; }
long WeatherData::getTimestamp() const { return timestamp; }



/* -----------------------------

    Displays weather data

----------------------------- */
void WeatherData::display() const {
    std::cout << "\n--- Weather for " << location << " ---\n";
    std::cout << "Current: " << currentTemp << "°F\n";
    std::cout << "Range: " << minTemp << "°F - " << maxTemp << "°F\n";
    std::cout << "Conditions: " << description << "\n";
}



/* -----------------------------

    Weather Analyzer methods

----------------------------- */
void WeatherAnalyzer::addWeatherData(const WeatherData& data) {
    history.push_back(data);
}

bool WeatherAnalyzer::detectColdFront() const {
    if (history.size() < 2) return false;
    
    // Check if temperature dropped by 10+ degrees
    double tempDrop = history[history.size()-2].getCurrentTemp() - history.back().getCurrentTemp();
    return tempDrop >= 10.0;
}

bool WeatherAnalyzer::detectWarmFront() const {
    if (history.size() < 2) return false;
    
    // Check if temperature rose by 10+ degrees
    double tempRise = history.back().getCurrentTemp() - history[history.size()-2].getCurrentTemp();
    return tempRise >= 10.0;
}

double WeatherAnalyzer::getAverageTemp() const {
    if (history.empty()) return 0.0;
    
    double sum = 0.0;
    for (const auto& data : history) {
        sum += data.getCurrentTemp();
    }
    return sum / history.size();
}

void WeatherAnalyzer::displayHistory() const {
    cout << "\n- - - - - - - - - - - - -\n\n" << endl; //Spacing

    std::cout << "\n=== Weather History ===\n";
    for (const auto& data : history) {
        data.display();
    }
}




/* -----------------------------

     - NAME
    TEXT

----------------------------- */


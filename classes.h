/* ****************************************
Filename: classes.cpp
Author: CosmicGrace (https://github.com/CosmicGrace)

Purpose:
    This file will hold all of my classes that
    I will be using in this project.

**************************************** */

#ifndef CLASS_H
#define CLASS_H


#include <string>
#include <vector>

class WeatherData {
private:
    double currentTemp;
    double minTemp;
    double maxTemp;
    std::string location;
    std::string description;
    long timestamp;

public:
    // Constructors
    WeatherData();
    WeatherData(double curr, double min, double max, std::string loc, std::string desc, long time);
    
    // Getters
    double getCurrentTemp() const;
    double getMinTemp() const;
    double getMaxTemp() const;
    std::string getLocation() const;
    std::string getDescription() const;
    long getTimestamp() const;
    
    // Display
    void display() const;
};

class WeatherAnalyzer {
private:
    std::vector<WeatherData> history;
    
public:
    void addWeatherData(const WeatherData& data);
    bool detectColdFront() const;
    bool detectWarmFront() const;
    double getAverageTemp() const;
    void displayHistory() const;
};


#endif

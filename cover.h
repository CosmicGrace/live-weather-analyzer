/* ****************************************
Filename: cover.h
Author: CosmicGrace (https://github.com/CosmicGrace)

Purpose:
    This file will contain all the includes, using namespace,
    and function prototypes for functions defined in functions.cpp.

    This whole program's purpose is to basically tell the weather.

**************************************** */

// So cover is only run once per use of this program
#pragma once


#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <curl/curl.h>

// JSON Library
#include "nlohmann/json.hpp"

// v The file for the classes
#include "classes.h"

// Using declarations
using namespace std;
using json = nlohmann::json;

// Function prototypes
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* userp);
string fetchWeatherData(const string& location, const string& apiKey);
WeatherData parseWeatherJSON(const string& jsonData);
void displayMenu();
string getUserLocation();
/* ****************************************
Filename: main.cpp
Author: CosmicGrace (https://github.com/CosmicGrace)

Purpose:    - PERSONAL PROJECT -
    This file will be what drives the program forward.
    Everything will be instructed here.

**************************************** */

#include "cover.h"



int main() {
    // Fix console encoding for special characters
    system("chcp 65001 > nul");
    
    const char* apiKeyPtr = getenv("WEATHER_API_KEY"); // Get from openweathermap.org

    // Checking it 
    if (apiKeyPtr == nullptr) {
        std::cerr << "Error: WEATHER_API_KEY environment variable not set!\n";
        std::cerr << "Please set it using: set WEATHER_API_KEY=your_key\n";
        return 1;
    }

    string API_KEY = apiKeyPtr;

    WeatherAnalyzer analyzer;
    
    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear newline


        switch(choice) {
                case 1: 
                {
                    string location = getUserLocation();
                    string jsonData = fetchWeatherData(location, API_KEY);
                    
                    if (!jsonData.empty()) {
                        WeatherData data = parseWeatherJSON(jsonData);
                        data.display();
                        analyzer.addWeatherData(data);
                    } else {
                        cout << "Failed to fetch weather data.\n";
                    }
                    break;
                }

                case 2: 
                {
                    analyzer.displayHistory();
                    break;
                }
                               
                case 3: 
                {
                    if (analyzer.detectColdFront()) {
                        cout << "\n⚠️ COLD FRONT DETECTED! Temperature dropped significantly.\n";
                    } else if (analyzer.detectWarmFront()) {
                        cout << "\n☀️ WARM FRONT DETECTED! Temperature rose significantly.\n";
                    } else {
                        cout << "\nNo significant weather fronts detected.\n";
                    }
                    cout << "Average temperature: " << analyzer.getAverageTemp() << "°F\n";
                    break;
                }
                    
                case 4: 
                {
                    cout << "- - - - - - - - - - - - -\n\n" << endl; //Spacing
                    
                    running = false;
                    cout << "Goodbye!\n";
                    break;
                }
                    
                default: 
                {
                    cout << "Invalid choice. Try again.\n";
                }
            }
        }
    return 0;
}
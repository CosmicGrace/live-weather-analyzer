/* ****************************************
Filename: functions.cpp
Author: CosmicGrace (https://github.com/CosmicGrace)

Purpose:
    This file will hold all my functions that I will
    use in this project.

**************************************** */

// So the program isn't confused
#include "cover.h"

/* -----------------------------

     - WriteCallback
    This function is a callback 
    handler that processes data 
    chunks received from a network 
    request. The function receives 
    raw data and appends it to a 
    string. 

----------------------------- */
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}


/* -----------------------------

     - fetchWeatherData
    The function takes two pieces of 
    information: a location (city name) 
    and an API key (your authentication 
    token). It then makes a network 
    request to OpenWeatherMap and 
    retrieves the weather data.

----------------------------- */
string fetchWeatherData(const string& location, const string& apiKey) {
    CURL* curl;
    CURLcode res;
    string readBuffer;
    
    curl = curl_easy_init();
    if(curl) {
        string url = "https://api.openweathermap.org/data/2.5/weather?q=" 
                         + location + "&appid=" + apiKey + "&units=imperial";
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }
        
        curl_easy_cleanup(curl);
    }

    //cout << "\n\n- - - - - - - - - - -\n\n" << endl; //Spacing

    return readBuffer;
}


/* -----------------------------

     - parseWeatherJSON
    Parse JSON response into WeatherData object

----------------------------- */
WeatherData parseWeatherJSON(const string& jsonData) {
    try {
        auto j = json::parse(jsonData);
        
        double current = j["main"]["temp"];
        double min = j["main"]["temp_min"];
        double max = j["main"]["temp_max"];
        string loc = j["name"];
        string desc = j["weather"][0]["description"];
        long time = j["dt"];
        
        return WeatherData(current, min, max, loc, desc, time);
        
    } catch (json::parse_error& e) {
        cerr << "JSON parse error: " << e.what() << endl;
        return WeatherData(); // Return default object
    }
}


/* -----------------------------

     - displayMenu
    The starting display menu

----------------------------- */
void displayMenu() {
    cout << "\n\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl; //Spacing

    cout << "\n\n= = = Weather Analyzer = = =\n";
    cout << "1. Get current weather\n";
    cout << "2. View weather history\n";
    cout << "3. Check for weather fronts\n";
    cout << "4. Exit\n";
    cout << "Choice: ";
}


/* -----------------------------

     - getUserLocation
    Getting the user's location

----------------------------- */
string getUserLocation() {
    string location;

    cout << "\n\n- - - - - - - - - - - - -\n\n" << endl; //Spacing

    cout << "Enter location (city,state or city,country): ";
    getline(cin, location);
    return location;
}


/* -----------------------------

     - NAME
    TEXT

----------------------------- */



/* -----------------------------

     - NAME
    TEXT

----------------------------- */



/* -----------------------------

     - NAME
    TEXT

----------------------------- */


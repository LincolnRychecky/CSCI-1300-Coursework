/**
 * Good Job!
 */

// Lincoln Rychecky: CS1300 Spring 2018
// Recitation: 107-Sayali Sonawane
// Cloud9 link: https://ide.c9.io/liry9073/csci1300
// Homework 3 - Problem 2

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
 * Algorithm: takes in airTemp and windSpeed and returns the windchill 
 * 1) check if wind speed is negative. if so, print "not applicable" and return 0.
 * 2) calculate wind chill using the inputs and the given equation for windchill
 * Input parameters: float airTemp, float windspeed
 * Output: "not applicable" only if invalid input is entered
 * Returns: 0 if invalid, windchill if valid inputs were entered
 */

float windChillCalculator(float airTemp, float windSpeed){
    
    if (windSpeed < 0){ //check if windspeed is negative. If so print invalid input
        
        cout << "Not applicable " << endl; 
        
        return 0;
    }
    
    float windChill = 35.74  + (0.6215*airTemp) - (35.75*pow(windSpeed, 0.16)) + ((0.4275*airTemp)*pow(windSpeed, 0.16));
    
    return windChill; //returns calculated windChill value
    
    
    
}

/**
 * Algorithm: takes in airTemp, low_wind_speed, high_wind_speed, wind_speed_step
 * 1) check if low wind speed is higher than high wind speed. if so, print invalid input
 * 2) check if wind_speed_step is less than 0. If so, print invalid input
 * Input parameters: float airTemp, float low_wind_speed, float high_wind_speed, float wind_speed_step
 * Output: prints out invalid input if invalid input has been entered. Prints out statement about wind chill at certain temps and wind speeds if input is valid
 * Returns: nothing
 */

void printWindChill(float airTemp, float low_wind_speed, float high_wind_speed, float wind_speed_step){
    
    float windSpeed = low_wind_speed;
    
    if (low_wind_speed > high_wind_speed){ //If low speed is greater than high, input is invalid
        
        cout << "Invalid input";
        
        windSpeed = high_wind_speed * 2; //makes windSpeed higher than high wind speed so loop does not execute
    }
    
    if (wind_speed_step < 0){ //If wind_speed_step is less than zero, input is invalid
        
        cout << "Invalid input";
        
        windSpeed = high_wind_speed * 2; //makes windSpeed higher than high wind speed so loop does not execute
    }
    
    while(windSpeed <= high_wind_speed){ // while windSpeed is less than or equal to high wind speed
        
        float windchill = windChillCalculator(airTemp, windSpeed); //call windchill calculator
        
        cout << "The wind chill is " << windchill << " degrees F for an air temperature of " << airTemp << " degrees F and a wind speed of " << windSpeed << " mph." << endl;
        
        windSpeed = windSpeed + wind_speed_step; // increment windSpeed by wind_speed_step
        
    }
    
    
    
}

int main() {
    
    float wind = windChillCalculator(30,5); //tests normal case
    
    cout << "The wind chill is " << wind << " degrees F." << endl;
    
    float wind2 = windChillCalculator(30,-5); //tests invalid input. Should return invalid input
    
    cout << "The wind chill is " << wind2 << " degrees F." << endl;
    
    printWindChill(10, 10, 20, 1); //tests print windchill with valid inputs
    
    cout << endl;
    
    printWindChill(10, 20, 10, 1); //tests print windchill with invalid inputs. 
    
}
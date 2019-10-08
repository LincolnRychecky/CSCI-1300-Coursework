// Lincoln Rychecky: CS1300 Spring 2018
/**
 * Good job!
 * Take care of indentation. All lines should be properly aligned.
 */

// Recitation: 107-Sayali Sonawane
// Cloud9 link: https://ide.c9.io/liry9073/csci1300
// Homework 2 - Problems 1 - 3

#include <iostream>

using namespace std;

/**
 * Algorithm: Gives US population in 1 year given a certain starting population
 * First makes variables for days per year, hours per day, minutes per hour, and seconds per minute
 * make variables for your the ammount of seconds elapsed for each rate
 * 1) set yearSecs equal to: 1* 365 *24*60*60 to get year length in seconds
 * 2) initialize and set birthsYear equal to yearSecs/8 to get ammount of births in a year
 * 3) initialize and set deathsYear equal to yearSecs/12 to get ammount of deaths in a year
 * 4) initalize and set imgYear equal to yearSecs/33 to get ammount of immigrants in a year
 * 5) initalize and set popFuture equal to initialPop + birthsYear - deathsYear + ImgYear to get the future population
 * 6) Return popFuture
 * Input parameters: Int Initial Population
 * Output: Int Future Population
 * Returns: Int Future Population
 */

 int population(int initialPop)
 {
     int daysInYear = 365; //days in year

     int hoursInDay = 24; //hours in day

     int minutesInHour = 60; //minutes in hour

     int secondsInMinute = 60; //seconds in minute

     int secondsBetweenBirths = 8; //ammount of seconds per birth

     int secondsBetweenDeaths = 12; //ammount of seconds per death

     int secondsBetweenImmigrants = 33; //ammount of seconds per immigrant

     int yearSecs = daysInYear * hoursInDay * minutesInHour * secondsInMinute; //converts 1 year into seconds

     int birthsYear = yearSecs/secondsBetweenBirths; //calculates births per year

     int deathsYear = yearSecs/secondsBetweenDeaths; //calculates deaths per year

     int imgYear = yearSecs/secondsBetweenImmigrants; //calculates new immigrants per year

     int popFuture = initialPop + birthsYear - deathsYear + imgYear; //combines deaths, births, and immigrants with initial
                                                                     //population to get the population after 1 year
     return popFuture; //returns the population after 1 year

 }

/**
 * Algorithm: Determines ammount of days, hours, minutes, and seconds after being given seconds value
 * First make variables for seconds in minutes, minutes in hour, and hours in a day to be used in conversion
 * 1) Check if value entered by user is < 0 or > 1000000. If not ask user to enter number in that range
 * 2) initalize and set secondsValue to givenSeconds % 60
 * 3) initalize seconds and set it equal to givenSeconds - secondsValue
 * 4) initalize and set minutesValue to (seconds % 3600) / 60
 * 5) update seconds : seconds = seconds - (minutesValue*60)
 * 6) initalize and set hoursValue to (seconds % 86400) / 3600
 * 7) update seconds to : seconds - (hoursValue * 3600)
 * 8) initalize and set daysValue to seconds / 86400
 * 9) Print out answer in correct format
 * Input parameters: Int ammount of seconds
 * Output: Several Strings and variables to achieve desired format
 * Returns: Nothing
 */

void howLong(int givenSeconds)
{

    int secondsInMinute = 60; //number of seconds in minute

    int minutesInHour = 60; //number of minutes in hour

    int hoursInDay = 24; //number of hours in day

   int secondsValue = givenSeconds % secondsInMinute; //Obtains seconds that will be left over and assigns them to variable

   int seconds = givenSeconds - secondsValue; //Initalizes remaining seconds value to variable and assigns value

   int  minutesValue = (seconds % (secondsInMinute*minutesInHour)) / secondsInMinute; //Obtains minutes value and assigns to variable

   seconds = seconds - (minutesValue * secondsInMinute); //Updates remaining seconds by removing seconds represented in minutesValue

    int hoursValue = (seconds % (secondsInMinute*minutesInHour*hoursInDay)) / (secondsInMinute*minutesInHour); //Obtains hours value and assigns to variable

    seconds = seconds - (hoursValue * (secondsInMinute*minutesInHour)); //Updates remaining seconds by removing seconds represented in hoursValue

    int daysValue = seconds / (secondsInMinute*minutesInHour*hoursInDay); //Assigns number of days to variable. The days value will be the remaing seconds divided by numer of seconds in a day

    cout << givenSeconds << " seconds is " << daysValue << " days, " << hoursValue << " hours, " << minutesValue << " minutes, and " << secondsValue << " seconds." << endl; //creates the print line in proper format that will be printed in console


}

/**
 * Algorithm: Determines carnot efficiency when given temps in kelvin for both the hot and cold reservoirs and returns the carnot efficiency
 * 1) initialize variable named carnotEfficiency
 * 2) set carnotEfficiency to: 1 - (tempC/ tempH)
 * 3) return carnotEfficiency
 * Input parameters: Temp of cold reservoir K. , Temp of warm reservoir K
 * Output:
 * Returns:
 */

float carnot(float tempC, float tempH)
{

    float carnotEfficiency = 1 - (tempC/tempH); //initializes float carnotEfficiency to the formula for carnot efficiency when the given values are applied

    return carnotEfficiency; //returns float value for carnot efficiency

}


int main() {

   //2 Tests for howLong

    howLong(70000); //test to see if it will output the test output from writeup

    int secondsAmmount = 546000000;

    howLong(secondsAmmount); //test with seconds value greater than 1 year

    //2 Tests for population

    cout << population(1000000) << endl;

    int population1 = 0;

    cout << population(population1) << endl; //test for when population put in is 0 as a variable

    //2 Tests for carnot

    cout << carnot(5,1) << endl; //expect -4

    int tempCold = int(5.1);

    int tempHot = int(1.1);

    cout << carnot(tempCold, tempHot); //expect -4. test when decimals are input

    cout << endl;

    string stringb;

    getline(cin, stringb);

    cout << stringb << endl;
}

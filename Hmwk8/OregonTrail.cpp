#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <random>

using namespace std;

//planned classes

//Supplies class
//includes oxen, food, bullets, spare wagon parts, as well as extra sets of clothes
//will include functions that will either add or remove from supplies count depending on actions

//character class
//each character object will have a name and health status
//get typhoid, break leg, get lost, etc. will be actions

//Party class
//a party object will be made up of an array of 5 characters
//a party will have private variables to hold the number of characters still alive as well as travel pace,
//general health of party, as well as rationing setting for food.

//map class
//destination will have a name and miles from most recent starting point
//will have a function for asking the traveler what the want upon their arrival as well as the rest of the menu of functions
//functions like "travel 1 day" and "rest 1 day" will also be encapsulated within this class
//function to show traveler their current location
//The map class functions as the user's journey and helps keep track of distace from the next location.

//in the main there will be a series of random objects which help to determine if a character
//gets sick or if a wagon part breaks, etc the main will also handle the trasition parts like when the
//characters choose to cross a river or float it, etc


void split(string s, char sep, string words[], int max_words){ //split helper function

        int i = 0;

        string str1 = "";
        string str2 = "";
        int len = s.length();

        while (s[i] != sep){

            str1 = str1 + s[i];
            i++;
        }

        words[0] = str1;

        str2 = s.substr(i+1);

        words[1] = str2;
    }

int search(string str1, string target){ //search helper function to help determine nature of landmark

    int indicator = 0;

    for(int i = 0; i <= str1.length() - target.length(); i++){

        if(str1.substr(i,target.length()) == target){
            indicator = 1;
            break;
        }

    }
    return indicator;
}

class Character{ //contains methods and constructors used to alter and set character attributes

    public:
    Character(){}
    ~Character(){}

    Character(string playerName, bool leaderStatus){ //character constructor

        dead = false;

        name = playerName;

        isSick = false;

        isLeader = leaderStatus;

    }

    string getName(){

        return name;
    }

    bool getDead(){

        return dead;
    }

    bool getIsSick(){

        return isSick;
    }

    bool getIsLeader(){

        return isLeader;
    }

    void setDead(bool deathStatus){

        dead = deathStatus;

    }

    void setName(string newName){

        name = newName;
    }

    void setIsSick(bool sicknessStatus){ //sets character object isSick to sick and if already sick they are marked as dead
        if(isSick == true && sicknessStatus == true){
            dead = true;
        }else{
        isSick = sicknessStatus;
        }
    }

    void setIsLeader(bool leaderStatus){

        isLeader = leaderStatus;
    }

    private:

    bool dead;

    string name;

    bool isSick;

    bool isLeader;

};

class map{

    public:

    map(int month1, int day1){ //map constructor, all it needs is the

        milesCovered = 0; //milesCovered are set to 0
        day = day1;
        month = month1;

    }

    void loadMapInfo(string fileName){

        //puts all of the information from the landmark/fort file into an array which holds them all
        //Parses throguh data and stores all names in the same names array in the order which they appear
        //milage will be stored in a milage array

        int currentLine = 1;//keep track of line you are on
        string line1;
        string words1[2];
        string words2[2];
        string milageHolder;

        ifstream writeFile; //create ofstream variable
	    writeFile.open(fileName); //open file in Outputmode

        while(getline(writeFile, line1)){

            if((currentLine%2) == 1){ //if on a line where its a name

                names[numNames] = line1;

                line1 = "";

                numNames++;
            }
            else{

                if(search(names[numNames - 1], "River") == 1){ //If River loads milage, type, and depth

                    split(line1, ' ', words1, 2);

                    milageHolder = words1[0].substr(0, words1[0].length() - 2);

                    milage[numMilage] = stoi(milageHolder);

                    numMilage++;

                    split(words1[1], ' ', words1, 2);

                    types[numTypes] = words1[0];

                    numTypes++;

                    riverDepths[numRiver] = stoi(words1[1].substr(0, words1[1].length() - 2));

                    numRiver++;

                    line1 = "";

                }

                if(search(names[numNames - 1], "Fort") == 1){ //If Fort loads milage, and type

                    split(line1, ' ', words1, 2);

                    milageHolder = words1[0].substr(0, words1[0].length() - 2);

                    milage[numMilage] = stoi(milageHolder);

                    numMilage++;

                    types[numTypes] = words1[1];

                    numTypes++;

                    line1 = "";
                }

                if((search(names[numNames - 1], "River") == 0) && (search(names[numNames - 1], "Fort") == 0)){ //If not river or fort loads milage, and type

                    milageHolder = line1.substr(0, line1.length() - 2);

                    milage[numMilage] = stoi(milageHolder);

                    numMilage++;

                    types[numTypes] = "Landmark";

                    numTypes++;

                    line1 = "";
                }
            }
            currentLine++; //update number of lines you've gone through;
        }
        writeFile.close();
    }

    string getNameNextLandMark(){

        return names[atLandmark];
    }

    int getMilesTillNextLandMark(){ //gets the ammount of miles until the next landmark from the users current position

        return (milage[atLandmark] - milesCovered); //subtract miles from begining to this landmark from the miles you have covered
    }

    string getTypeOfNextLandMark(){
        return types[atLandmark];
    }

    int getDay(){
        return day;
    }

    int getMonth(){
        return month;
    }

    int getMilesCovered(){
        return milesCovered;
    }

    string getNameAt(int index){
        return names[index];
    }

    string getTypeAt(int index){
        return types[index];
    }

    int getMilageAt(int index){
        return milage[index];
    }

    int getRiverDepthAt(int index){
        return riverDepths[index];
    }

    void setDay(int newDay){
        day = newDay;
    }

    void setMonth(int newMonth){
        month = newMonth;
    }

    void setMilesCovered(int newMilesCovered){
        milesCovered = newMilesCovered;
    }

    void advanceLandmarkAt(){
        atLandmark++;
    }

    private:

    int milesCovered;

    int month;

    int day;

    int numNames = 0;

    int numMilage = 0;

    int numRiver = 0;

    int numTypes = 0;

    int milage[100];

    string names[100];

    string types[100];

    int riverDepths[100];

    int atLandmark = 0;

};

class Group{ //contains all methods and constructors to hold and edit supply numbers as well as party health and misfortunes

    public:

    Group(Character characters[]){ //Group object constructor takes in an array of 5 characters

        for(int i = 0; i < 5; i++){ //set each member of the party array to its counter part in the input array

            party[i] = characters[i];

        }

        cash = 1500; //default money is 1500

        numOxen = 0;

        numBullets = 0;

        numCharacters = 5; //since everyone is alive at the the begining set numCharacters to 5

        numParts = 0;

        numMedKits = 0;

        food = 0;

        consumptionLevel = 1;

        wagonBroken = false; //Your wagon is not broken at the begining
    }

    float getCash(){

        return cash;
    }

    int getNumOxen(){

        return numOxen;
    }

    int getNumBullets(){

        return numBullets;
    }

    int getNumCharacters(){

        return numCharacters;
    }

    int getNumParts(){

        return numParts;
    }

    int getNumMedKits(){

        return numMedKits;
    }

    int getFood(){

        return food;
    }

    void setCash(float newCash){

        cash = newCash;

    }

    void setNumOxen(int newOxen){

        numOxen = newOxen;

    }

    void setBullets(int newBullets){

        numBullets = newBullets;

    }

    void setNumCharacters(int newCharacters){

        numCharacters = newCharacters;

    }

    void setNumParts(int newParts){

        numParts = newParts;

    }

    void setNumMedKits(int newMedKits){

        numMedKits = newMedKits;

    }

    void setConsumptionLevel(int choice){

        consumptionLevel = choice;
    }

    void setFood(int newFood){

        food = newFood;
    }

    void UpdateHealth(bool sick, string characterName){

            for(int i = 0; i < 5; i++){
                if(party[i].getName() == characterName){

                    party[i].setIsSick(sick);

                    break;
                }
            }
    }

    bool getHealthOfCharacter(string name){

        for(int i = 0; i < 5; i ++){
            if(party[i].getName() == name){
                return party[i].getIsSick();
            }
        }
        return false;
    }

    bool getDeadOfCharacter(string name){

        for(int i = 0; i < 5; i ++){
            if(party[i].getName() == name){
                return party[i].getDead();
            }
        }
        return false;
    }

    void advance(int choice, map &map1){ //The advance function is essentially how player take a turn
        srand(time(NULL)); //seed random
        if(choice == 1){ //rest choice is 1

            int dayNum;

            dayNum = rand() % 3 + 1;// dayNum in the range 1 to 3

            food -= ((numCharacters*1)*dayNum); //3 lbs of food per person per day of rest is subtracted

            if(dayNum >= 2){ //if the rest happens to be 2 or more days, all health is restored
                for(int i = 0; i < numCharacters; i++){
                    party[i].setIsSick(false);
                }
                    cout << "Everyone regained their health after the rest!" << endl;
            }

            if(map1.getDay() < 28){ //If the day of the month is less than 27, add because it will not exceed 30
                map1.setDay(map1.getDay() + dayNum);
            }

            else{
                for(int i = 0; i < dayNum; i++){ //add a day each time through the loop and adjust day and moth accordingly

                    if(((map1.getMonth() % 2) == 0) && (map1.getDay() < 30)){ //even number month, and day is less than 30, add a day

                        map1.setDay(map1.getDay() + 1);

                    }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() < 31)){ //odd number month, and day is less than 31, add a day

                        map1.setDay(map1.getDay() + 1);
                    }else if(((map1.getMonth() % 2) == 0) && (map1.getDay() == 30)){ //even number month and day is 30, set day to 1 and increment month by 1

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);

                    }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() == 31)){ //odd number month and day is 31, set day to 1 and incrment month by 1

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);
                    }
                }
            }

            cout << "Your party rested " << dayNum << " days... time to get back on the trail!" << endl; //let the user know how many days that they rested
        }


        if(choice == 2){ //continue on trail. 2 week intervals

            int milNum;

            milNum = rand() % 121 + 100; //generate miles covered between 100 and 220

            food -= ((numCharacters*2)*14); //2 lbs of food per person per day is subtracted

            bool indication = false;

            if(milNum > map1.getMilesTillNextLandMark()){
                map1.setMilesCovered(map1.getMilesCovered() + map1.getMilesTillNextLandMark());
            }else{
            map1.setMilesCovered( map1.getMilesCovered() + milNum); //advance between 70 and 140 miles in this turn
            }
            if(map1.getDay() < 17){ //If the day of the month is less than 17, add because it will not exceed 30
                map1.setDay(map1.getDay() + 10);
            }
            else{
                for(int i = 0; i < 10; i++){ //calendar advancing for loop used in all advance choices
                    if(((map1.getMonth() % 2) == 0) && (map1.getDay() < 30)){ //even number month, and day is less than 30, add a day

                        map1.setDay(map1.getDay() + 1);

                    }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() < 31)){ //odd number month, and day is less than 31, add a day

                        map1.setDay(map1.getDay() + 1);
                    }else if(((map1.getMonth() % 2) == 0) && (map1.getDay() == 30)){ //even number month and day is 30, set day to 1 and increment month by 1

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);

                    }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() == 31)){ //odd number month and day is 31, set day to 1 and incrment month by 1

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);
                    }
                }
            }

            if(map1.getMilesTillNextLandMark() == 0){ //if the miles till next landmark is 0, you have arrived at the landmark
            cout << "You made it! Welcome to " << map1.getNameNextLandMark() << "!" << endl;

            }else{ //if there are still miles to go, let them knowo how many are left
            cout << map1.getMilesTillNextLandMark() << " miles to go till you reach " << map1.getNameNextLandMark() << endl;
            }
        }

        if(choice == 3){ //hunt

            int animalProbs;

            animalProbs = rand() % 101; //create a random number which represents what animals they encounter

            int possibleMeat = 0;

            if((animalProbs <= 50)){
                cout << "You encountered a rabbit!" << endl;
                possibleMeat += 2;
            }

            if((animalProbs <= 25)){
                cout << "You encountered a fox!" << endl;
                possibleMeat += 5;
            }

            if((animalProbs <= 10)){
                cout << "You encountered a deer!" << endl;
                possibleMeat += rand() % 26 + 30;
            }

            if((animalProbs <= 7)){
                cout << "You encountered a bear!" << endl;
                possibleMeat += rand() % 151 + 100;
            }

            if((animalProbs<= 3)){
                cout << "You encountered a moose!" << endl;
                possibleMeat += rand() % 301 + 300;

            }

            if(possibleMeat == 0){
                cout << "You, didnt encounter an Animals" << endl;
            }

            cout << "Do you want to hunt?: (1) yes (2) no ..." << endl;

            string ch;

            getline(cin, ch);

            if(ch == "1"){

            if((numBullets < 10) || (possibleMeat == 0)){ //if you didnt encounter any animals or have less than 10 bullets, its unsuccessful
                cout << "The hunt was unsuccessful..." << endl;
            }else{ //if the hunt is possible

                numBullets -= 10; //lose ten bullets

                int genNum;

                genNum = rand() % 10 + 1; //create a random number for user to guess

                string guess;

                int intGuess = 0;

                bool wonFight = false;

                cout << "You have three guesses to guess a number between 1-10 and have a successful hunt!" << endl;

                for(int i = 1; i < 4; i++){

                    if(i == 3){ //if we are on the third guess, print this message instead
                        cout << "This is your last guess! Choose wisely... ";
                    }

                    cout << "Guess " << i << ":" << endl;

                    getline(cin, guess); //take in user guess

                    while((guess != "1") && (guess != "2") && (guess != "3")  && (guess != "4") && (guess != "5") && (guess != "6") && (guess != "7") && (guess != "8") && (guess != "9") && (guess != "10")){ //takes care of invalid input from user
                        cout << "Invalid choice. Choose a number between 1-10. Guess " << i << ":" << endl;
                        getline(cin, guess);
                    }

                    intGuess = stoi(guess); //turn their guess into an int

                    if(genNum == intGuess){ //if they guess, it let them know that had a successful hunt and exit loop
                        cout << "Correct! Your Party had a successful hunt!" << endl;
                        wonFight = true;
                        break;
                    }

                }

                if(wonFight == true){ //if they won, they gained meat and are shown this print statement
                    cout << "Your party gained " << possibleMeat << " lbs of food!" << endl;
                }else{ //let them know they failed the hunt
                    cout << "Your party had an unsuccessful hunt and gained 0 lbs of food..." << endl;
                }

                if(wonFight == true){ //They are asked how well they would like to eat

                    cout << "How well would you like to eat? (1) Poorly 2lbs of food per person (2) Moderately 3lbs of food per person (3) Well 5lbs of food per person" << endl;

                    string choiceEat;

                    getline(cin, choiceEat); //take in their choice

                    //different choices means different ammounts of food are subtracted
                    if(choiceEat == "1"){
                        food -= (2*numCharacters);
                    }else if(choiceEat == "2"){
                        food -= (3*numCharacters);
                    }else if(choiceEat == "3"){ //if they eat well they all regain their health
                        food -= (5*numCharacters);

                                for(int i = 0; i < numCharacters; i++){
                                    party[i].setIsSick(false);
                                }
                                    cout << "Everyone regained their health after the hearty meal!" << endl;
                                    }

                                    if(possibleMeat > 1000){
                                        cout << "You cant take more than 1000 lbs of food at the same time, you had to leave some behind" << endl;
                                        food += 1000;
                                    }else{
                                        food += possibleMeat;
                                    }
                }

            }

            if(((map1.getMonth() % 2) == 0) && (map1.getDay() < 30)){ //advance a day in the calendar

                map1.setDay(map1.getDay() + 1);
                food -= (numCharacters*3);
            }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() < 31)){

                map1.setDay(map1.getDay() + 1);
                food -= (numCharacters*3);
            }else if(map1.getDay() == 31){

                map1.setDay(1);
                map1.setMonth(map1.getMonth() + 1);
                food -= (numCharacters*3);
            }else if(map1.getDay() == 30){

                map1.setDay(1);
                map1.setMonth(map1.getMonth() + 1);
                food -= (numCharacters*3);
                }
            }else{
                cout << "You decided not to hunt." << endl;
            }
        }

        if(choice == 4){ //quit

        cout << "I'm sorry that you had to cut your trip short. Thanks for playing!" << endl;
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl;
        cout << "_*_*_*_*_*_*_*_*T H E   O R E G O N   T R A I L*_*_*_*_*_*_*_*_*_*_" << endl;
        cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_";

        }


        if(choice == 5){ //just advances 1 day. helper for a few other functions in the game

            if(((map1.getMonth() % 2) == 0) && (map1.getDay() < 30)){

                map1.setDay(map1.getDay() + 1);
                food -= (numCharacters*3);
            }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() < 31)){

                map1.setDay(map1.getDay() + 1);
                food -= (numCharacters*3);
            }else if(map1.getDay() == 31){

                map1.setDay(1);
                map1.setMonth(map1.getMonth() + 1);
                food -= (numCharacters*3);
            }else if(map1.getDay() == 30){

                map1.setDay(1);
                map1.setMonth(map1.getMonth() + 1);
                food -= (numCharacters*3);
            }
        }

    }

    void encounterRaiders(int milesCovered){ //Raider encounter function

        float top = pow ((milesCovered/(100 - 4)), 2) + 72;

        float bottom = pow ((milesCovered/(100 - 4)), 2) + 12;

        float probability = ((top/bottom) - 1)/10;

        //this is all the probability calculation ^^

        float range = 100 * probability; //multiply 100 by the probability to get the range

        int spot;

        srand(time(NULL)); //seed random with current time

        spot = rand() % 101 + 1; //create a random number between 1 and 100

        if(spot <= range){ //you encounter raiders

            cout << "RIDERS AHEAD! THEY LOOK HOSTILE!" << endl;

            cout << "Would you like to run(1), attack(2), or surrender(3)?" << endl;

            string choice;

            getline(cin, choice); //get choice from user

            while ((choice != "1") && (choice != "2") && (choice != "3")){ //keep asking if input is invalid
                cout << "Would you like to run(1), attack(2), or surrender(3)?" << endl;
                getline(cin, choice);
            }

            if(choice == "1"){ //run

                numOxen --; //lose 1 ox
                food -= 10; //lose 10lbs of food
                numParts --; //lose 1 wagon part

                cout << "In your escape, you left behind 1 ox, 10lbs of food, and 1 wagon part!" << endl;
                if(numOxen == 0){
                    cout << "You have no oxen left. You cannot go any farther" << endl;
                }
                if(food <= 0){
                    cout << "You have no food left. You cannot go any farther" << endl;
                }
            }

            if(choice == "2"){

                cout << "You chose to fight the raiders. You have 3 guesses to guess a number between 1-10 and win the fight!" << endl;

                int genNum;

                genNum = rand() % 10 + 1;

                string guess;

                int intGuess = 0;

                bool wonFight = false;

                for(int i = 1; i < 4; i++){

                    cout << "Guess " << i << ":" << endl;

                    getline(cin, guess);

                    intGuess = stoi(guess);

                    if(genNum == intGuess){
                        cout << "Correct! Your Party repelled the raiders and continue on!" << endl;
                        wonFight = true;
                        break;
                    }

                    if(i == 2){
                        cout << "This is your last guess! Choose wisely... ";
                    }

                }

                if(wonFight == false){
                    cout << "Your party lost the fight, you lose 50lbs of food and a quater of your cash reserves." << endl;
                    food -= 50;
                    float lostCash = cash * 0.25;
                    cash -= lostCash;
                }
            }

            if(choice == "3"){

                cout << "You surrender and the raiders take a quarter of your cash reserves." << endl;
                float lostCash = cash * 0.25;
                cash -= lostCash;
            }
        }
    }

    void possibleCalamity(map &map1){

        int genNum;

        srand(time(NULL)); //seed random with current time

        genNum = rand() % 150 + 1; //generate a random number between 1 and 200

        if(genNum <= 30){ //get sick 20% chance

            int genNum1;

            if(numCharacters > 1){
                genNum1 = rand() % (numCharacters-1); //generate a random number between 1 and numCharacters //chooses character to get sick
            }else{
                genNum1 = rand() % 1; //so we dont end up dividing by zero. Always generates 0 as the first index is the only one still alive
            }
            int sickness;

            sickness = rand() % 3 + 1; //generate a random number between 1 and 3

            bool wasAlreadySick = false;

            if(sickness == 1){
                cout << party[genNum1].getName() << " got dysentery" << endl;
                if(numMedKits > 0){
                    cout << "You used a med kit and healed them!" << endl;
                    numMedKits--;
                }else{
                if(party[genNum1].getIsSick() == true)    {
                    wasAlreadySick = true;
                }
                party[genNum1].setIsSick(true);
                }
            }
            if(sickness == 2){
                cout << party[genNum1].getName() << " got the flu" << endl;
                if(numMedKits > 0){
                    cout << "You used a med kit and healed them!" << endl;
                    numMedKits--;
                }else{
                    if(party[genNum1].getIsSick() == true)    {
                    wasAlreadySick = true;
                }
                party[genNum1].setIsSick(true);
                }
            }
            if(sickness ==3){
                cout << party[genNum1].getName() << " fell off the wagon and broke their arm" << endl;
                if(numMedKits > 0){
                    cout << "You used a med kit and healed them!" << endl;
                    numMedKits--;
                }else{
                    if(party[genNum1].getIsSick() == true)    {
                    wasAlreadySick = true;
                }
                party[genNum1].setIsSick(true);
                }
            }

            if(wasAlreadySick == true){ //if the member died from their sickness (meaning they were already sick)

                cout << party[genNum1].getName() << " tragically died from their illness since they were already sick. You stop for a burial, but must forge ahead..." << endl;

                         for(int i = 0; i < numCharacters; i++){

                            if(party[i].getName() == party[genNum1].getName()){

                                party[i].setDead(true);

                                    Character holder = party[numCharacters - 1]; //holder is the last character in array

                                    party[numCharacters - 1] = party[i]; //set last character to the dead character

                                    party[i] = holder; //the index where the dead character was taken from is where the last character goes

                                    numCharacters --; //number of alive characters is dropped by 1

                        break; //exit loop, all tasks complete
                    }
                }
            }
        }

        if((genNum > 30) && (genNum <=40)){ //oxen dies 7% chance

            cout << "One of your oxen fell ill and died." << endl;
            numOxen --;
            if(numOxen == 0){
                cout << "all of your oxen died. You cannot go any farther" << endl;
            }
        }

        if((genNum > 40) && (genNum <=60)){ //a thief attacks 15% chance

            int genNu;

            genNu = 10 + rand() % ((25 + 1) - 10); //generate a random number between 1 and numCharacters

            food -= genNu;

            cout << "OH NO! LAST NIGHT YOU GOT ATTACKED BY A THIEF! He stole " << genNu << " lbs of food." << endl;
        }

        if((genNum > 60) && (genNum <= 80)){ //wagon part breaks 15% chance

            if(numParts > 0){

                numParts--;

                int partChooser;

                partChooser = rand() % 3 + 1; //generate a random number between 1 and numCharacters

                if(partChooser == 1){

                    cout << "Oh No! You hit a rock and broke a wagon wheel! You must spend a day to repair it using a spare part." << endl;
                }

                if(partChooser == 2){

                    cout << "Oh No! You made a turn too sharp and broke your wagon tongue! You must spend a day to repair it using a spare part." << endl;
                }

                if(partChooser == 3){

                    cout << "Oh No! A wagon axel got bent! You must spend a day to repair it using a spare part." << endl;
                }

                if(((map1.getMonth() % 2) == 0) && (map1.getDay() < 30)){

                    map1.setDay(map1.getDay() + 1);
                    food -= (numCharacters*3);
                }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() < 31)){

                    map1.setDay(map1.getDay() + 1);
                    food -= (numCharacters*3);
                }else if(map1.getDay() == 31){

                    map1.setDay(1);
                    map1.setMonth(map1.getMonth() + 1);
                    food -= (numCharacters*3);
                }else if(map1.getDay() == 30){

                    map1.setDay(1);
                    map1.setMonth(map1.getMonth() + 1);
                    food -= (numCharacters*3);
                }
            }else{
                cout << "Oh No! You hit a rock and broke a wagon wheel! You must spend a day to repair it using a spare part." << endl;
                cout << "Your wagon is broken down and you are out of spare parts." << endl;

                wagonBroken = true;
            }
        }

        if((genNum > 80) && (genNum <=100)){ //bad weather hits 15% chance

            int genNu1;

             genNu1 = rand() % 5 + 1; //generate a random number between 1 and numCharacters

             if(genNu1 == 1){

                 cout << "Heavy Rain! You must stop for a day." << endl;
                     if(((map1.getMonth() % 2) == 0) && (map1.getDay() < 30)){

                    map1.setDay(map1.getDay() + 1);
                    food -= (numCharacters*3);
                }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() < 31)){

                    map1.setDay(map1.getDay() + 1);
                    food -= (numCharacters*3);
                }else if(map1.getDay() == 31){

                    map1.setDay(1);
                    map1.setMonth(map1.getMonth() + 1);
                    food -= (numCharacters*3);
                }else if(map1.getDay() == 30){

                    map1.setDay(1);
                    map1.setMonth(map1.getMonth() + 1);
                    food -= (numCharacters*3);
                }
             }

             if(genNu1 == 2){

                 cout << "A Hail storm! You must stop for a day." << endl;
                         if(((map1.getMonth() % 2) == 0) && (map1.getDay() < 30)){

                        map1.setDay(map1.getDay() + 1);
                        food -= (numCharacters*3);
                    }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() < 31)){

                        map1.setDay(map1.getDay() + 1);
                        food -= (numCharacters*3);
                    }else if(map1.getDay() == 31){

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);
                        food -= (numCharacters*3);
                    }else if(map1.getDay() == 30){

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);
                        food -= (numCharacters*3);
                    }
             }

             if(genNu1 == 3){

                 cout << "A violent storm! You must stop for 3 days" << endl;

                 for(int i = 0; i < 3; i++){

                     if(((map1.getMonth() % 2) == 0) && (map1.getDay() < 30)){

                        map1.setDay(map1.getDay() + 1);
                        food -= (numCharacters*3);
                    }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() < 31)){

                        map1.setDay(map1.getDay() + 1);
                        food -= (numCharacters*3);
                    }else if(map1.getDay() == 31){

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);
                        food -= (numCharacters*3);
                    }else if(map1.getDay() == 30){

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);
                        food -= (numCharacters*3);
                    }
                 }
                  for(int i = 0; i < numCharacters; i++){
                    party[i].setIsSick(false);
                }
                cout << "Everyone healed up while you had to stay put!" << endl;
             }

             if(genNu1 == 4){

                 cout << "A whiteout blizzard! You must stop for 3 days" << endl;

                 for(int i = 0; i < 3; i++){

                     if(((map1.getMonth() % 2) == 0) && (map1.getDay() < 30)){

                        map1.setDay(map1.getDay() + 1);
                        food -= (numCharacters*3);
                    }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() < 31)){

                        map1.setDay(map1.getDay() + 1);
                        food -= (numCharacters*3);
                    }else if(map1.getDay() == 31){

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);
                        food -= (numCharacters*3);
                    }else if(map1.getDay() == 30){

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);
                        food -= (numCharacters*3);
                    }
                 }
                  for(int i = 0; i < numCharacters; i++){
                    party[i].setIsSick(false);
                }
                cout << "Everyone healed up while you had to stay put!" << endl;
             }

             if(genNu1 == 5){

                 cout << "A hurricane hits! You must stop for a week" << endl;

                 for(int i = 0; i < 7; i++){

                     if(((map1.getMonth() % 2) == 0) && (map1.getDay() < 30)){

                        map1.setDay(map1.getDay() + 1);
                        food -= (numCharacters*3);
                    }else if(((map1.getMonth() % 2) == 1) && (map1.getDay() < 31)){

                        map1.setDay(map1.getDay() + 1);
                        food -= (numCharacters*3);
                    }else if(map1.getDay() == 31){

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);
                        food -= (numCharacters*3);
                    }else if(map1.getDay() == 30){

                        map1.setDay(1);
                        map1.setMonth(map1.getMonth() + 1);
                        food -= (numCharacters*3);
                    }
                 }
                  for(int i = 0; i < numCharacters; i++){
                    party[i].setIsSick(false);
                }
                cout << "Everyone healed up while you had to stay put!" << endl;
             }

        }

    }

    string getNameCharacterAt(int index){
        return party[index].getName();
    }

    bool getWagonBroken(){
        return wagonBroken;
    }

    void characterDies(string characterName){ //kills character with name that is input as a parameter

        for(int i = 0; i < numCharacters; i++){

                if(party[i].getName() == characterName){

                    party[i].setDead(true);

                    if(party[i].getIsLeader() == true){

                        //game over, leader is dead.
                    }

                    Character holder = party[numCharacters - 1]; //holder is the last character in array

                    party[numCharacters - 1] = party[i]; //set last character to the dead character

                    party[i] = holder; //the index where the dead character was taken from is where the last character goes

                    numCharacters --; //number of alive characters is dropped by 1

                    if(numCharacters == 0){ //if everyone is dead, the game ends

                        //game over, everyone is dead
                    }
                    break; //exit loop, all tasks complete
                }
            }
    }

    void goToStore(int priceMultiplier){ //Store Function. Handles all cout for store and purchase of all items. Price multiplier indicates the number for you are on

        int billTotal = 0;

        if(priceMultiplier == 0){
            cout << "YOU HAD SAVED $1700 TO SPEND FOR THE TRIP, AND YOU'VE JUST PAID $200 FOR A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS:" << endl << endl;
        }

        float oxenPrice = 40 * (1 +(0.25*priceMultiplier));
        float foodPrice = 0.5 * (1 +(0.25*priceMultiplier));
        float bulletPrice = 2 * (1 +(0.25*priceMultiplier));
        float partPrice= 20 * (1 +(0.25*priceMultiplier));
        float kitPrice = 25 * (1 +(0.25*priceMultiplier));

        cout << "*****W E L C O M E  T O  T H E  S T O R E *****" << endl;
        cout << "(1) Oxen - $" << oxenPrice << " per yoke (2 animals)" << endl;
        cout << "(2) Food - $" << foodPrice << " per pound (recommended: At least 200 lbs per person)" << endl;
        cout << "(3) Bullets - $" << bulletPrice << " per box of 20" << endl;
        cout << "(4) Spare wagon parts - $" << partPrice << " per Part" << endl;
        cout << "(5) Medical Aid Kits - $" << kitPrice << " per kit" << endl;
        cout << "(6) Done shopping" << endl << endl;

        cout << "What would you like to buy?" << endl;
        string purchaseChoice;
        getline(cin, purchaseChoice);
        while((purchaseChoice != "1") && (purchaseChoice != "2") && (purchaseChoice != "3") && (purchaseChoice != "4") && (purchaseChoice != "5") && (purchaseChoice != "6")){
            cout << "That's not one of the options. What do you want again?" << endl;
            getline(cin, purchaseChoice);
        }

        while(purchaseChoice != "6"){

            if(purchaseChoice == "1"){
                cout << "How many yokes would you like?" << endl;
                string numO;
                getline(cin, numO);
                int numOHolder = stoi(numO);
                if(priceMultiplier == 0){
                    while((numOHolder < 3) || (numOHolder > 5)){
                        cout << "You need to spend between $100-$200 on your team. please choose a different number of yokes" << endl;
                        getline(cin, numO);
                        numOHolder = stoi(numO);
                    }
                }
                if(cash >= (oxenPrice * numOHolder)){
                    cout << numOHolder << " Yokes of oxen have been added to your bill" << endl << endl;
                    billTotal += (oxenPrice * numOHolder);
                    numOxen += numOHolder*2;
                    cash -= (oxenPrice * numOHolder);
                    cout << "Current Bill: $" << billTotal << endl;
                }else{
                    cout << "You cant afford that" << endl;
                }
            }

            if(purchaseChoice == "2"){
                cout << "How many lbs of food would you like?" << endl;
                string numLbs;
                getline(cin, numLbs);
                int numLbsHolder = stoi(numLbs);

                if(cash >= (foodPrice * numLbsHolder)){
                    billTotal += (foodPrice * numLbsHolder);
                    cout << numLbsHolder << " lbs of food have been added to your bill" << endl << endl;
                    food += numLbsHolder;
                    cash -= (foodPrice * numLbsHolder);
                    cout << "Current Bill: $" << billTotal << endl;
                }else{
                    cout << "You cant afford that" << endl;
                }
            }

            if(purchaseChoice == "3"){
                cout << "How many boxes of bullets would you like?" << endl;
                string numBoxes;
                getline(cin, numBoxes);
                int numBoxesHolder = stoi(numBoxes);

                if(cash >= (bulletPrice * numBoxesHolder)){
                    billTotal += (bulletPrice * numBoxesHolder);
                    cout << numBoxesHolder << " boxes of bullets have been added to your bill" << endl << endl;
                    numBullets += (numBoxesHolder * 20);
                    cash -= (bulletPrice * numBoxesHolder);
                    cout << "Current Bill: $" << billTotal << endl;
                }else{
                    cout << "You cant afford that" << endl;
                }
            }

            if(purchaseChoice == "4"){
                cout << "How many spare Wagon Parts would you like?" << endl;
                string numWag;
                getline(cin, numWag);
                int numWagHolder = stoi(numWag);

                if(cash >= (partPrice * numWagHolder)){
                    billTotal += (partPrice * numWagHolder);
                    cout << numWagHolder << " spare wagon parts have been added to your bill" << endl << endl;
                    numParts += numWagHolder;
                    cash -= (partPrice * numWagHolder);
                    cout << "Current Bill: $" << billTotal << endl;
                }else{
                    cout << "You cant afford that" << endl;
                }
            }

            if(purchaseChoice == "5"){
                cout << "How many Medical Aid Kits would you like?" << endl;
                string numKits;
                getline(cin, numKits);
                int numKitsHolder = stoi(numKits);

                if(cash >= (kitPrice * numKitsHolder)){
                    billTotal += (kitPrice * numKitsHolder);
                    cout << numKitsHolder << " Medical Aid Kits have been added to your bill" << endl;
                    numMedKits += numKitsHolder;
                    cash -= (kitPrice * numKitsHolder);
                    cout << "Current Bill: $" << billTotal << endl;
                }else{
                    cout << "You cant afford that" << endl << endl;
                }
            }

                    cout << "What would you like to buy?" << endl;
                getline(cin, purchaseChoice);
                while((purchaseChoice != "1") && (purchaseChoice != "2") && (purchaseChoice != "3") && (purchaseChoice != "4") && (purchaseChoice != "5") && (purchaseChoice != "6")){
                    cout << "That's not one of the options. What do you want again?" << endl;
                    getline(cin, purchaseChoice);
                }

        }

        cout << "Your final bill is: $" << billTotal << endl;
        cout << "Thank you for shopping with us! Good luck on the trail!" << endl;
        cout << "******************************************************************" << endl;


    }

    string getSickGroupMembers(){

        string output;

        for(int i = 0; i < numCharacters; i++){

            if(party[i].getIsSick() == true){
                output += party[i].getName();
            }

        }
        return output;
    }

    string getDeadGroupMembers(){

        string output;

        for(int i = 0; i < 5; i++){

            if(party[i].getDead() == true){
                output += party[i].getName();
            }

        }
        return output;
    }

    bool isLeaderDead(string nameLead){

        bool output;

        for(int i = 0; i < 5; i++){

            if((party[i].getDead() == true) && (party[i].getName() == nameLead)){
                output = true;
            }

        }

        return output;

    }

    void gameOver(bool wonOrLost, map &map1){ //For when all the players die, the leader dies, food runs out, or the wagon is broken permenantly

        if(wonOrLost == true){
            cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl;
            cout << "_*_*_*_*_*_*_*_*T H E   O R E G O N   T R A I L*_*_*_*_*_*_*_*_*_*_" << endl;
            cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl << endl;
            cout <<"Congratulations! You successfully led your party all the way from independence to Oregon City!" << endl;
            cout << "THE END";
        }else{
            cout << "You cannot go on any further. Thanks for playing" << endl;
                cout << "Final Stats|" << endl;
                cout << "----------" << endl;
                cout << "Leader: ";
                for(int i = 0; i < 5; i++){
                    if(party[i].getIsLeader() == true){
                        cout << party[i].getName();
                    }
                }
                cout << endl << "Miles Traveled: " << map1.getMilesCovered() << endl;
                cout << "Food remaining: " << food << endl;
                cout << "Cash remaining: " << cash << endl;
             }
    }

    private:

    float cash;

    int numOxen;

    int numBullets;

    int numCharacters;

    int numParts;

    int food;

    int numMedKits;

    int consumptionLevel;

    bool wagonBroken;

    Character party[5];

};

class OregonTrail{ //handles all of the user interface and calculation of whether or not a misfortune occurs in a turn
                   //Functions included: Hunt, Go to shop, Rivercrossing,

    public:

    OregonTrail(){
        numStoreVisits = 0;
        riversVisited = 0;
    }

    void playGame(){

        cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM INDEPENDENCE MISSOURI TO OREGON CITY, OREGON IN 1847. YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5-6 MONTHS --- IF YOU MAKE IT ALIVE." << endl << endl;

        cout << "What is the name of your party leader?" << endl;
        string inName;
        getline(cin, inName);
        Character one(inName, true);
        string leaderName = inName;

        cout << "What is the name of the next member of your party?" << endl;
        getline(cin, inName);
        Character two(inName, false);

        cout << "What is the name of the next member of your party?" << endl;
        getline(cin, inName);
        Character three(inName, false);

        cout << "What is the name of the next member of your party?" << endl;
        getline(cin, inName);
        Character four(inName, false);

        cout << "What is the name of the next member of your party?" << endl;
        getline(cin, inName);
        Character five(inName, false);

        Character charA[] = {one,two,three,four,five}; //put all five characters in an array
        Group g1(charA); //create a group object

        cout << "******************************************************************" << endl;

        g1.goToStore(numStoreVisits); //group goes to store for first time
        numStoreVisits ++;

        cout << endl;

        cout << "You must arrive in Oregon City by November 30th. When would you like to begin your journey? (1) Deafault 3-28 (2) enter any date between the default and 5-1" << endl;
        string choiceDate;
        getline(cin, choiceDate);
        while((choiceDate != "1") && (choiceDate != "2")){
            cout << " Invalid chocie. You must arrive in Oregon City by November 30th. When would you like to begin your journey? (1) Deafault 3-28 (2) enter any date between the default and 5-1" << endl;
            getline(cin, choiceDate);
        }

        map gameMap(3,28);

        if(choiceDate == "1"){
            //nothing. Already set
        }
        else{
            cout << "What month would you like to leave?" << endl;
            string monthChoice;
            getline(cin,monthChoice);

            while((monthChoice != "3") && (monthChoice != "4") && (monthChoice != "5")){
                cout << "That's an invalid choice. What month would you like to leave?" << endl;
                getline(cin,monthChoice);
            }

            cout << "What day would you like to leave?" << endl;
            string dayChoice;
            getline(cin,dayChoice);

            if(monthChoice == "3"){

                while((dayChoice != "28") && (dayChoice != "29") && (dayChoice != "30") && (dayChoice!= "31")){
                    cout << "Invalid day chosen. Day must be 28, 29, 30, or 31 for this month. What day would you like to leave?" << endl;
                    getline(cin,dayChoice);
                }

            }

            if(monthChoice == "4"){

                while((stoi(dayChoice) < 1) || (stoi(dayChoice) > 30) ){
                    cout << "Invalid day chosen. Day must be between 1 and 30 for this month. What day would you like to leave?" << endl;
                    getline(cin,dayChoice);
                }

            }
            if(monthChoice == "5"){

                while(dayChoice != "1" ){
                    cout << "Invalid day chosen. 1 is the only valid day this month. What day would you like to leave?" << endl;
                    getline(cin,dayChoice);
                }
            }

            int MonthHolder = stoi(monthChoice); //convert month choice
            int DayHolder = stoi(dayChoice); //convert day choice

            gameMap.setMonth(MonthHolder);
            gameMap.setDay(DayHolder); //create a new map with the date given

            cout << gameMap.getMonth() << "-" << gameMap.getDay() << endl;
        }

        cout << "Let's hit the trail!" << endl;
        cout << "******************************************************************" << endl;
        cout << "Date:" << gameMap.getMonth() << "-" << gameMap.getDay() << " Food: " << g1.getFood() << "lbs" << " Miles covered: " << gameMap.getMilesCovered() << endl;
        cout << "Oxen: " << g1.getNumOxen() << " Med Kits: " << g1.getNumMedKits() << " Wagon Parts: " << g1.getNumParts() << endl;
        gameMap.loadMapInfo("milestones.txt"); //loads landmarks in

        bool endCondition = false;

        string choiceAdvance;
        int choiceAdvanceHolder;

        while(endCondition == false){

            if((g1.getNumCharacters() == 0) || (g1.getFood() <= 0) || (gameMap.getMonth() >= 12) || (g1.getNumOxen() == 0) || (g1.getWagonBroken() == true) || (g1.isLeaderDead(leaderName))){ //game is over. Check at begining of every turn

                if(g1.getFood() <= 0){
                    cout << "You ran out of food! You have to turn around and abandon your journey..." << endl;
                }
                if(g1.getNumCharacters() == 0){
                    cout << "Everyone in your party is dead. You failed your journey" << endl;
                }
                if(gameMap.getMonth() >= 12){
                    cout << "You didnt make it by November 30th! The weather turned sour and you had to end your journey..." << endl;
                }
                if(g1.isLeaderDead(leaderName) == true){
                    cout << "Your leader died. You had to turn around." << endl;
                }

                g1.gameOver(false, gameMap);
                endCondition = true; //game ended with a loss
                break;
            }

            cout << "What would you like to do? (1) rest (2) continue on the trail (3) hunt" << endl;
            getline(cin, choiceAdvance);

            while((choiceAdvance != "1") && (choiceAdvance != "2") && (choiceAdvance != "3")){ //handles invalid input
                cout << "That is not a valid choice. Please enter 1, 2, or 3 to indicate your choice" << endl;
                getline(cin, choiceAdvance);
            }

            choiceAdvanceHolder = stoi(choiceAdvance);

            g1.advance(choiceAdvanceHolder,gameMap);
            if(gameMap.getMilesCovered() >= 2040){ //if the player ends up covering at least 2040 miles, they win
                g1.gameOver(true, gameMap);
                endCondition = true;
                break;//exit while loop
            }
            g1.possibleCalamity(gameMap); //determines if misfortune occurs
            g1.encounterRaiders(gameMap.getMilesCovered()); //determines if raiders happen
            cout << "******************************************************************" << endl;
            cout << "Date: " << gameMap.getMonth() << "-" << gameMap.getDay() << " Food: " << g1.getFood() << "lbs"<< " Miles covered: " << gameMap.getMilesCovered() << endl; //print date and food left
            cout << "Oxen: " << g1.getNumOxen() << " Med Kits: " << g1.getNumMedKits() << " Wagon Parts: " << g1.getNumParts() << endl; //print oxen, med kits, and wagon parts remaining
            cout << "Sick People: " << g1.getSickGroupMembers() << " Dead People: " << g1.getDeadGroupMembers() << endl;
            if(gameMap.getMilesTillNextLandMark() == 0){
                if(gameMap.getTypeOfNextLandMark() == "Fort"){ //if a fort there is a store to go to or rest opportunity
                    string fortChoice;
                    int fortChoiceHolder;
                    cout << "Would you like to (1) rest,(2) go to the store, or (3) move on?" << endl;
                    getline(cin, fortChoice);

                    while((fortChoice != "1") && (fortChoice != "2") && (fortChoice != "3")){
                        cout << "Invalid choice. Please choose 1 to rest, 2 to shop, or 3 to go on." << endl;
                    }

                    if(fortChoice == "3"){
                        cout << "Let's get on the trail again!" << endl;
                    }


                while(fortChoice != "3"){
                    if(fortChoice == "2"){
                        g1.goToStore(numStoreVisits);

                    }

                    if(fortChoice == "1"){
                        g1.advance(1,gameMap);
                        cout << "Date:" << gameMap.getMonth() << "-" << gameMap.getDay() << " Food: " << g1.getFood() << "lbs" << " Miles covered: " << gameMap.getMilesCovered() << endl;
                            cout << "Oxen: " << g1.getNumOxen() << " Med Kits: " << g1.getNumMedKits() << " Wagon Parts: " << g1.getNumParts() << endl;
                            cout << "Sick People: " << g1.getSickGroupMembers() << " Dead People: " << g1.getDeadGroupMembers() << endl;
                    }

                    if(fortChoice == "3"){
                        cout << "Let's get on the trail again!" << endl;
                    }

                    if((fortChoice == "2") || (fortChoice == "1")){
                        cout << "Would you like to (1) rest,(2) go to the store?, or (3) move on." << endl;
                    getline(cin, fortChoice);

                    }

                }
                gameMap.advanceLandmarkAt(); //you just passed a landmark
                 numStoreVisits++;
                }else if(gameMap.getTypeOfNextLandMark() == "River"){//if a River, need to use ferry or rest opportunity
                    if(gameMap.getRiverDepthAt(riversVisited) > 3){
                        int priceCross = (g1.getNumCharacters() * 10);
                         cout << "The river is deeper than 3 feet. It costs " << priceCross << "$ to ferry accross the river." << endl;
                        if(priceCross > g1.getCash()){
                            cout << "You cannot afford to go on." << endl;
                            g1.gameOver(false, gameMap);
                            break;
                        }

                        cout << "You you like to (1) Rest or (2) Cross now" << endl;
                        string choiceRiver;
                        getline(cin, choiceRiver);

                        while((choiceRiver != "1") && (choiceRiver != "2")){
                            cout << "Not a valid choice. please enter 1 to rest or 2 to cross." << endl;
                            getline(cin, choiceRiver);
                        }

                        while(choiceRiver != "2"){
                            g1.advance(1,gameMap);
                            cout << "Date:" << gameMap.getMonth() << "-" << gameMap.getDay() << " Food: " << g1.getFood() << "lbs" << " Miles covered: " << gameMap.getMilesCovered() << endl;
                            cout << "Oxen: " << g1.getNumOxen() << " Med Kits: " << g1.getNumMedKits() << " Wagon Parts: " << g1.getNumParts() << endl;
                            cout << "Sick People: " << g1.getSickGroupMembers() << " Dead People: " << g1.getDeadGroupMembers() << endl;
                            cout << "You you like to (1) Rest or (2) Cross now" << endl;
                            getline(cin, choiceRiver);
                            while((choiceRiver != "1") && (choiceRiver != "2")){
                                cout << "Not a valid choice. please enter 1 to rest or 2 to cross." << endl;
                                getline(cin, choiceRiver);
                            }
                        }

                        cout << "You successfully crossed the river! Let's keep moving!" << endl;
                        cout << "******************************************************************"<< endl;
                        gameMap.advanceLandmarkAt(); //you are now moving on to the next landmark

                        g1.setCash(g1.getCash() - priceCross);
                    }
                gameMap.advanceLandmarkAt();
                }else if(gameMap.getTypeOfNextLandMark() == "Landmark"){

                    string landChoice;
                    int landChoiceHolder;
                    cout << "Would you like to (1) rest, or (2) move on?" << endl;
                    getline(cin, landChoice);

                    while((landChoice != "1") && (landChoice != "2")){
                        cout << "Invalid choice. Please choose 1 to rest, or 2 to shop." << endl;
                    }

                    if(landChoice == "2"){
                        cout << "Let's get on the trail again!" << endl;
                    }


                while(landChoice != "2"){

                    if(landChoice == "1"){
                        g1.advance(1,gameMap);
                    }

                    if((landChoice == "2") || (landChoice == "1")){
                        cout << "Would you like to (1) rest, or (2) move on?" << endl;
                    getline(cin, landChoice);

                    }

                    if(landChoice == "2"){
                        cout << "Let's get on the trail again!" << endl;
                    }

                }
                gameMap.advanceLandmarkAt();

            cout << "******************************************************************"<< endl;
            }


            } //while loop close

        }
    }
    int getNumStore(){
        return numStoreVisits;
        int riverAt;
    }

    private:
    int numStoreVisits;
    int riversVisited;

};

int main(){

    OregonTrail newGame1; //create an oregon trail object

    newGame1.playGame(); //call the play game function on that object to play the game

     //I had to make it so that the milage was between 100 and 220 for them to successfully get there.
     //Also gave the user $1500 to start with so they had enough money. Also, every advance had to be 10 days so the
     //user ran out of time no matter what happened if the parameters werent changed. Other than that, I stuck very closely to the template
}

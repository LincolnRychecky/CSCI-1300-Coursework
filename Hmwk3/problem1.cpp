/**
 * Good job!
 */
// Lincoln Rychecky: CS1300 Spring 2018
// Recitation: 107-Sayali Sonawane
// Cloud9 link: https://ide.c9.io/liry9073/csci1300
// Homework 3 - Problem 1 

#include <iostream>
#include <string>

/**
 * Algorithm: takes in words from user and returns a mad lib
 * 1) Take in all of the words needed from user
 * 2) print the print statement with the words input by the user inserted in
 * Input parameters: None 
 * Output: Print statement mad lib
 * Returns: nothing 
 */
 
using namespace std;

void story1 ()
{
    string pluralN; //initalizes word for user to input
    
    string occupation; //initalizes word for user to input
    
    string animalName; //initalizes word for user to input
    
    string place; //initalizes word for user to input
    
    cout << "Enter a plural noun:" << endl; // prompt user to enter string
    
    cin >> pluralN; // take in string and assign it to pluralN
    
    cout << "Enter an occupation:" << endl; // prompt user to enter string
    
    cin >> occupation; // take in string and assign it to occupation
    
    cout << "Enter an animal name:" << endl; // prompt user to enter string
    
    cin >> animalName; // take in string and assign it to animalName
    
    cout << "Enter a place:" << endl; // prompt user to enter string
    
    cin >> place; // take in string and assign it to place
    
    cout << "In the book War of the "<< pluralN << ", the main character is an anonymous " << occupation << " who records the arrival of the "<< animalName << "s" << " in " << place << "." << endl;
}

/**
 * Algorithm: takes in words from user and returns a mad lib
 * 1) Take in all of the words needed from user
 * 2) print the print statement with the words input by the user inserted in
 * Input parameters: None 
 * Output: Print statement mad lib
 * Returns: nothing 
 */

void story2 ()
{
    
    string name; //initalizes word for user to input
    
    string state; //initalizes word for user to input
    
    cout << "Enter a name:"<< endl; // prompt user to enter string
    
    cin >> name; // take in string and assign it to name
    
    cout << "Enter a state/country:"<< endl; // prompt user to enter string
    
    cin >> state; // take in string and assign it to state
    
    cout << name <<", I've got a feeling we're not in " << state << " anymore." << endl;

}

/**
 * Algorithm: takes in words from user and returns a mad lib
 * 1) Take in all of the words needed from user
 * 2) print the print statement with the words input by the user inserted in
 * Input parameters: None 
 * Output: Print statement mad lib
 * Returns: nothing 
 */

void story3 ()
{
    
    string firstName; //initalizes word for user to input
    
    string relative; //initalizes word for user to input
    
    string verb; //initalizes word for user to input
    
    cout << "Enter a first name:"<< endl; // prompt user to enter string
    
    cin >> firstName; // take in string and assign it to firstName
    
    cout << "Enter a relative:"<< endl; // prompt user to enter string
    
    cin >> relative; // take in string and assign it to relative
    
    cout << "Enter a verb:"<< endl; // prompt user to enter string
    
    cin >> verb; // take in string and assign it to verb
    
    cout << "Hello. My name is " << firstName << ". You killed my " << relative << ". Prepare to " << verb << "." << endl;
    
}

/**
 * Algorithm: allows the user the option of what story they would like to play or quit
 * 1) ask user what they would like to do given options of stories 1,2,3 and q. 
 * 2) if 1 do story 1. if 2 do story 2. if 3 do story 3. if q, quit asking and say good bye
 * 3) check if the user input is invalid and if so print a statement to the user telling them that
 * 4) loop unitl user decides to quit
 * Input parameters: nothing
 * Output: the mad libs stories
 * Returns: nothing
 */

void menu ()
{
   string indicator = "1";
    
    while(indicator == "1" ) //while indicator is 1, continue to loop
    {
        
    string choice;
    
    cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit:" << endl;
    
    cin >> choice; // ask user for choice
    
    
   if (choice == "q") //when choice is q print good bye and set indicator to kick out of loop
    {
        
        cout << "good bye";
        
        indicator = "2";
    }
    else{
        
        if ( choice == "1"){ //when choice is 1, call story 1
            
            story1();
            
        }
        
        else{
            
            if ( choice == "2"){ //when choice is 2, call story 2
            
            story2();
            
        }
        else 
        {
            if (choice == "3"){//when choice is 3, call story 3
            
            story3();
        }
            else { //if none of the above options have been chosen, input is invalid and print statement to let user know
                
                cout << "Valid choice not selected." << endl;
                
               }//fourth else
            
            } //third else
            
         } //second else
    
       } //first else
     
     
    } //while loop
    
}

int main() {
    
    story1(); //run story 1 and enter words when prompted
    
    story1(); //run story 1 and enter words when prompted
    
    cout << endl;
    
    story2(); //run story 2 and enter words when prompted
    
    story2(); //run story 2 and enter words when prompted
    
    cout << endl;
    
    story3(); //run story 3 and enter words when prompted
    
    story3(); //run story 3 and enter words when prompted
    
    menu(); //run each story 1, 2, and 3 and then use q to test ability to call each story function
    
    menu(); //this time enter invalid entries "hey", "quit", and "him" and then q to test ability to detect invalid entries
    
}
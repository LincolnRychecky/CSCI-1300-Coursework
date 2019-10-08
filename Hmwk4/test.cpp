#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){

/*

string user = "";

cout << "please enter a username." << endl;

cin >> user;

if(user == ""){
    
while(user == ""){
    
    cout << "enter a username";
    
    cin >> user;
}
 
}
 cout << "success";
 
 */
 
 /*
 cout << "Would you like to (v)iew your ratings, (r)ate a book," << endl << "(g)et recommendations, or (q)uit?:" << endl;
    
    char choice;
    
    cin >> choice;
    
    if((choice == 'v') || (choice == 'V') || (choice == 'r') || (choice == 'R') || (choice == 'g') || (choice == 'G') || (choice == 'q') || (choice == 'Q')){
    	
    	
    	
    }else{
    	
    	while((choice != 'v') && (choice != 'V') && (choice != 'r') && (choice != 'R') && (choice != 'g') && (choice != 'G') && (choice != 'q') && (choice != 'Q')){
    		
    		cout << "That is not a valid choice, please enter a valid option:" << endl;
    		
    		cin >> choice;
    		
    	} 
    	
    	
    }
*/
    	
    	cout << "Welcome to the Library, What is your name?:" << endl;
    
    string name; 
    
    getline(cin, name);
    
    if(name == ""){
    	
    	cout << "You provided an empty username, Please provide a valid user name to login or register:" << endl;
    	
    	cout << "Enter your name again:" << endl;
    	
        cin >> name;
    
    }
    	
    	
    	
}
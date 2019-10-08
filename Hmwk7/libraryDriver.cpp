// Lincoln Rychecky: CS1300 Spring 2018
// Recitation: 107-Sayali Sonawane
// Cloud9 link: https://ide.c9.io/liry9073/csci1300
// Homework 7 

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <sstream>


using namespace std;

class User{ //User class
    
    public:
           
    User(string name1, int userRatings[], int numberRatings){ //User constructor
        
        for (int i = 0; i < numberRatings; i++){
            
            ratings[i] = userRatings[i];
            
            name = name1;
            
            numRatings = numberRatings;
            
        }
        
    }
        
    User(){ //default user constructor
        
       name = "NONE";
       
       for(int i = 0; i < 100; i++){
           
           ratings[i] = 0;
           
       }
       
       numRatings = 0;
        
    }    
        
    string getName(){ //name getter
        
        return name;
        
    }
    
    void setName(string name1){ //name setter
    
        name = name1;
        
    }
    
    int getNumRatings(){ //numRatings getter
        
        return numRatings;
        
    }
    
    void setNumRatings(int numberRatings){ //numRatings setter
        
        numRatings = numberRatings;
        
    }
    
    int getRatingAt(int index){ //Rating getter
        
        if(index >= numRatings){
            
            return -1000;
            
        }
        
        return ratings[index];
        
    }
    
    int setRatingAt(int index, int rating){ //Rating setter
        
        if(index >= numRatings){
            
            return -1000;
            
        }
        
        if((rating == -5) || (rating == -3) || (rating == 0) || (rating == 1) || (rating == 3) || (rating == 5)){
            
            ratings[index] = rating;
            
            cout << "Success!" << endl;
            
            return 0;
            
        }else{
            
            cout << "Invalid Input!" << endl;
            
            return -1;
        }
        
        
    }
    
    private:
    
    string name;
    
    int ratings[100];
    
    int numRatings;

};

class Book{
    
    public:
           
    Book(){ //book default constructor
        
        title = "NONE";
        
        author = "NONE";
        
    }       
           
    Book(string title1, string author1){ //book constructor
        
        title = title1;
        
        author = author1;
        
    }
           
    string getTitle(){ //title getter
        
        return title;
               
    }
           
    void setTitle(string title1){ //title setter
        
        title = title1;
        
    }
           
    string getAuthor(){ //author getter
        
        return author;
        
    }
    
    void setAuthor(string author1){ //author setter
        
        author = author1;
        
    }
    
    private:
    
    string title;
    
    string author;

};

class Library{
    
    public:
    
     Library(){ //default user constructor
    
        numBooks = 0;
    
        numUsers = 0;
        
    }    
    
    void loadInformation()
    {
    	
	ifstream writeFile; //create ofstream variable
	writeFile.open("books.txt"); //open file in Outputmode
    	
    if (writeFile.fail()) //if file fails to open return -1
    { 
       
        cout << "Error! books or ratings file could not be found.";
        return;
    }
    string line;
    int numBooks1 = 0;
    int numUsers1 = 0;
    
    while(getline(writeFile, line))//While there are still lines in the file to be read
    { 
    	
    	transform( line.begin(), line.end(), line.begin(), ptr_fun <int, int> ( tolower ) ); //turn to lowercase using transform function
    
        if(line.back() == '\r' || line.back() == '\n' || line.back() == ' ')
            line.erase(line.end()-1);
            
    	string title = "";
    	string author = "";
    	
    	bool authorDone = false;
    	bool titleDone = false;
    	int endIndex;
    	int i = 0;
    	while(authorDone == false)
    	{ //parse through line to get just the author
    		
    		if(line[i] != ',')
    		{
    			author = author + line[i];
    			i++;
    		}
    		else
    		{
    			authorDone = true;
    			endIndex = i + 1;
    		}
    		
    	}
    	
    	title = line.substr(endIndex, line.length() - author.length() - 1);//the rest of the line must be the title
    	
    	Book b(title, author); //create a book user with your stuff youve gotten
    	
    	books[numBooks1] = b; //set the author of the book at books[i] to the author pulled from the get line
    	 //set the title of the book at books[i] to the title pulled from the get line
    	
    	author = "";
    	
    	title = "";
    	
    	numBooks1++;
    	
    }
	writeFile.close();
	numBooks = numBooks1;
	    	
	ifstream w_File; //create ofstream variable
	w_File.open("ratings.txt");
	    	
    if (w_File.fail()) //if file fails to open return -1
    { 
       
        cout << "Error! books or ratings file could not be found.";
        return;
        
    }
    else
    {
	    	
    	string line1;
    	
    	int endIndex1;
	    	
		while(getline(w_File, line1)) //while there is still input from the file
		{ 
		    stringstream line2(line1); //takes in the name, makes it tower case and assins to line2
		    string name;
		    getline(line2, name, ',');
		    string username = name;
		    transform( name.begin(), name.end(), name.begin(), ptr_fun <int, int> ( tolower ) );
		    getline(line2, name, ',');
		    
		    stringstream ss(name); //takes that rating and converts the string to an int and then assigns to ratings
		    string rate;
		    int ratings[numBooks];
		    int i = 0;
		    while(getline(ss, rate, ' ')) { //will continually take ratings from file deliniated by ' ' until there are no more
		        ratings[i] = stoi(rate); //turn rating string into an int to be stored in the int array ratings
		        
		        i++;
		    }
		    
		    User u = User(username, ratings, numBooks); //creates new user with gathered informations
		    
		    users[numUsers1] = u; //sets user at index numusers to the new user
	
        	numUsers1 ++; //increment the number of new users

        }
   }
   
	w_File.close(); //close the file
	
	numUsers = numUsers1; //update private variable numUsers
	
	cout << "Data Loaded successfully!"<< endl;
    	
    }
    
    void login(){
    
    cout << "Welcome to the Library, What is your name?:" << endl;
    
    string name; 
    
    getline(cin, name); //get a name from the user
    
    while(name == ""){ //while the name the user enters is an empty string, keep looping
    	
    	cout << "You provided an empty user name, Please provide a valid user name to login or register:" << endl;
    	
    	cout << "Enter your name again:" << endl;
    	
        getline(cin, name); //get another name from the user
    
    }
   
    bool foundUser = false; //boolean to keep track of whether the user exists already or not
    
    string userFound; //string for username we take from array
    
    string nameHolder = name; //name holder to keep track of the original name entered by user
    
    transform( name.begin(), name.end(), name.begin(), ptr_fun <int, int> ( tolower ) ); //make the name entered by the user lowercase
    
    int userLocation; //where this particular user is located within the user array
    
    for(int i = 0; (i < numUsers) && (foundUser == false); i ++){ //if i is less than number of users and you have not yet found the user, keep incrementing
    	
    	userFound = users[i].getName(); //get the user at index i
    	
    	if(userFound == name){ //if the username pulled from array matches user entry
    		
    		cout << "Welcome back, " << nameHolder << endl;
    		
    		userLocation = i; //keeps track of the users location in the array
    		
    		foundUser = true; //set to true since you have found the user
    		
    		break; //break loop
    	
    	}
    	
     }
    
    if(foundUser == false){ //if the user doesnt exist in the user array yet
    		
    		cout << "Welcome to the Library, " << nameHolder << endl;
    		
    		int useRate[numBooks]; //make an array of 0s for the new users ratings (has not yet rated any books)
    		
    		for(int i = 0; i < numBooks; i++){ 
    		    
    		    useRate[i] = 0;
    		    
    		}
    		
    		User u = User(name,useRate,numBooks); //create a new user with the input name and defualt numbers
    		
    		users[numUsers] = u; //set users[numUsers] to the new user object created
    		
    		userLocation = numUsers; //set user location to the number of users. helps track index
    		
    		numUsers ++; //increment numUsers by 1
    	
    }

    cout << "Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:" << endl;
    
    char choice; //char to store the user's choice
    
    string choiceHolder; //a string so you can validly use getLine
    
    getline(cin,choiceHolder); 
    
    choice = choiceHolder[0]; //choice is the first character in the choiceHolder string 
    
    	while((choice != 'v') && (choice != 'V') && (choice != 'r') && (choice != 'R') && (choice != 'g') && (choice != 'G') && (choice != 'q') && (choice != 'Q')){ //loop while no valid choice have ben selected yet
    		
    		cout << "Please input a valid choice" << endl;
    		
    		cout << "Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:" << endl;
    		
    		getline(cin,choiceHolder);
    
    choice = choiceHolder[0];
    	} 
    
    string rateHolder; //a string to hold the rating entered by user with a getLine
    
    //(choice != 'q') && (choice != 'Q')
    while(choice != 'q' && (choice != 'Q')){ //overarching while loop
    	
    	if((choice == 'v') || (choice == 'V')){ //if the user inputs v, call view ratings function
    		
    		viewRatings(name, foundUser);
    		
    	}
    	
    	if((choice == 'r') || (choice == 'R')){ //if the user enters r, call the rate a book function
    		
    		cout << "Enter the name of the book that you would like to rate:" << endl;
    		
    		string bookName;
            int bookRating;
    		
    		getline(cin,bookName);
    		
    		
    		cout << "Enter your rating of the book:" << endl;
    		
    		getline(cin,rateHolder);
    		bookRating = stoi(rateHolder);
    		
    	
    		rateABook(bookName, bookRating, userLocation);
    		
    		foundUser = true;
    		
    	}
    	
    	if((choice == 'g') || (choice == 'G')){ //if choice is g, call the get recommendations function
    		
    		getRecommendations(userLocation, foundUser);
    		
    	}
    	
    	cout << "Would you like to (v)iew your ratings, (r)ate a book," << " (g)et recommendations, or (q)uit?:" << endl; //prompt user for their next action 
    
    getline(cin,choiceHolder);
    
    choice = choiceHolder[0];
    
    	while((choice != 'v') && (choice != 'V') && (choice != 'r') && (choice != 'R') && (choice != 'g') && (choice != 'G') && (choice != 'q') && (choice != 'Q')){
    		
    		cout << "That is not a valid choice, please enter a valid option:" << endl;
    		
    		getline(cin,choiceHolder);
    
    choice = choiceHolder[0];
    		
    	} 
    	
	  } //over arching while loop
	  
	  	if((choice == 'q') || (choice == 'Q')){ //if the choice is q, call the quit function
    		
    		quit();
    		
    		
    		return;
    		
    	}
    
    }   //last curly bracket
    
    
    
    void viewRatings(string name, bool newUser){ //Function that can be called to help a user view the ratings of a certain user

    if(newUser == false){ //if the user is not a current user, let them know they havent rated any books and return nothing
        
        cout << "You have not rated any books as yet:" << endl;
        
        return;
    }

	cout << "Here are the books that you have rated:" << endl;

    bool foundUser = false;
    
    string userFound;
    
    int indexUser;  
    
    transform( name.begin(), name.end(), name.begin(), ptr_fun <int, int> ( tolower ) );
    
    for(int i = 0; (i < numUsers) && (foundUser == false); i ++){ //find the user's index and save it in the indexUser variable
    	
    	userFound = users[i].getName();
    	
    	if(userFound == name){
    		
    		indexUser = i;
    		
    		break;
    	
    	}
    	
     }
    	
    	for(int i = 0; (i < (numBooks)); i++){ //loop while i is less than the number of books
    		
    		if(users[indexUser].getRatingAt(i) != 0){ //get every rating for every book which the user has read
    			
    			cout << "Title : " << books[i].getTitle() << endl;
    			
    			cout << "Rating : " << users[indexUser].getRatingAt(i) << endl;
    			
    			cout << "------------------------------" << endl;
   
    		}
    		
    	}
    	
    	
    	
    	
    }
    
    void rateABook(string bookName, int bookRating, int userIndex){
    	
    	string nameHolder = bookName; //a string to keep track of the exact name the user entered
    	
    	transform( bookName.begin(), bookName.end(), bookName.begin(), ptr_fun <int, int> ( tolower ) ); //make lowercase
    	
    	int bookIndex = -1; //variable to hold the book's current index 
    	
    	for(int i = 0; i < numBooks; i++){ //look for the title in the books array, and if you find it, save the index
    	    
    	    if(books[i].getTitle() == bookName){
    	        
    	        bookIndex = i;
    	        
    	        break;
    	        
    	    }
    	    
    	}
    	
    	if((bookIndex == -1)){ //if book was not located, print this message and return nothing
    	    
    	    cout << "The book you requested does not exist in the database" << endl;
    	    
    	    return;
    	}else{ //if it was, update the rating and print that it worked
    	    
    	    	users[userIndex].setRatingAt(bookIndex,bookRating); //update rating
    	    	
    	    //	cout << "Success!" << endl;
    	    	
                cout << "Thank-you. The rating for the book titled " << nameHolder << " has been updated to " << bookRating << endl;
                
                return;
    	}
    	
    }
 
 
 
 void getRecommendations(int indexUser, bool foundUser){
     
    if(foundUser == false) //if the user is a new user with no ratings, return this
    {
    
        cout << "there are no recommendations for you at present" << endl;
        
        return; //terminates get recommendations function
    }
    
    int sum = 0, numFilled = 0, minScore = 1000000000, minScoreIndex = -1; //variables to be used in the similarity equation
    
    for(int i = 0; i < numUsers; i ++) //loop for when i is less than numUsers 
    {
        if(i == indexUser) //if i is equal to the index of the user, skip this iteration
            continue;
         for(int x = 0; x < users[indexUser].getNumRatings(); x++) //compare each rating of a user to the user wanting recommendations
         {
            if(i != indexUser) 
            {
                sum += pow(users[indexUser].getRatingAt(x) - users[i].getRatingAt(x), 2);
            }
        }
        if(sum < minScore) //if the sum is less than the minScore already save, set minScore to this new lesser sum
        {
            minScore = sum;
            minScoreIndex = i;
        }
        sum = 0;
        numFilled++;
    }
    
    int numRecs = 0;
    for(int l = 0; numRecs < 10 && l < users[minScoreIndex].getNumRatings(); l++) //loop while under 10 for number of recommendatuins and the number of ratings is less than l
    {
        if((users[minScoreIndex].getRatingAt(l) >= 3) && (users[indexUser].getRatingAt(l) == 0)) //if the rating is greater than or equal to 3, print the recommendation
        {
            if(numRecs == 0)
                cout << "Here are some of the books that we think you would like" << endl;
            cout << books[l].getTitle() << " by " << books[l].getAuthor() << endl;
            numRecs++;
        }
    }
    if(numRecs == 0) //if the user has no recommendations, print a message to them
    {
        cout << "there are no recommendations for you at present" << endl;
    }
     
     
     
 }
 
    void quit(){
        
        ofstream to_File; //of stream variable
            
        to_File.open("saveData.txt");
	    
            for(int x = 0; x < numUsers; x++){ //iterate while x is less than the number of users
                
                to_File << users[x].getName() << ","; //print the name of users[x] to the save file
                
                for(int i = 0; i < users[i].getNumRatings(); i++){ //while i is less than the number of ratings, iterate
                    
                    to_File << users[x].getRatingAt(i); //print the rating for the current user at x 
                    
                        if(i != users[i].getNumRatings() - 1 ){ //if i is not the last index of the users array that is filled print a space
                            
                            to_File << " ";
                            
                        }
                }
                
                if(x != numUsers - 1){ //if x is not equal to the last filled index, print an empty line
                    
                    to_File << endl;
                    
                }
                
            }
          
        cout << "Data successfully saved. Goodbye!";
                   
        to_File.close(); //close the save data file
        
   }
   
    
    int getNumBooks(){
        
        return numBooks;
        
    }
    
    int getNumUsers(){
        
        return numUsers;
        
    }
    
    void testBooks(){
        
        for(int i = 0; i < numBooks; i++){
            
            cout << books[i].getTitle() << endl;
            
        }
        
    }
    
    void testUsers(){
        
        for(int i = 0; i < 10; i++){
            
            cout << users[i].getRatingAt(0) << endl;

        }
        
        
    }
    
    private:
    
    Book books[500];
    
    User users[500];
    
    int numBooks;
    
    int numUsers;
    
};






int main()
{
	// Put your algorithms here. We have provided an example below of loading from the external data files.
	//
	//
	// create new Library object which will have all users in an array and all books in an array 
	
	//Algorithm: Library will have two parameters which are arrays. each array will be used to fill the private arrays
	
	// Read the file books.txt 
	// Read the file users.txt
	// Check if file open fails for either file 
	//		if a file open fails, print "Error. User file or book file could not be found. Please make sure that users.txt and books.txt is in the same directory."
	//		exit program 
	
	//Algorithm: Open both files in read mode so that you can take from the txt. file. check if either fails. print proper values. return 0
	
	// Create a book object for each book in the book file 
	
	//Algoritm: Read in from the txt file in order to locate the name and author which can then be put into a new book object
	//Use a while loop to continue throguh the array to do this. 
	
	// Create a user object for each user in the book file 
	
	//Algorithm: read in from the book file and use each name to put it into a user object
	//Use a while loop to continue through the array to do this. 
	
	// present menu to the user
	// the menu should have the following options: 
	//		quit
	//		...
	//		...
	//	Continue elaborating what should happen if the user selects other menu options. You should also think about what happens 
	//	when the user provides invalid input, or some operation cannot occur. 
	
	
	//Algorithm: the user can input (v), (r), (g), (q). depending on what the user inputs, the program will either terminate
	//or the user will be shown their ratings which need to be read and printed from the txt file, be able to add a new
	//rating to a book, or they will be presented with recommendations read from a txt file and printed to their console
	
	
	Library library1;
	
	library1.loadInformation();
	
	library1.login();
	
	//cout << library1.getNumUsers(); 
	
//	library1.testBooks();
	return 0;
	
	
	
}
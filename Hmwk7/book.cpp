// Lincoln Rychecky: CS1300 Spring 2018
// Recitation: 107-Sayali Sonawane
// Cloud9 link: https://ide.c9.io/liry9073/csci1300
// Homework 7 questions 1-4

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

int main(){
    
    
    
}

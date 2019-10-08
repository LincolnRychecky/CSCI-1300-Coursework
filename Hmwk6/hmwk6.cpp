/**
 * Good job!
 */ 
// Lincoln Rychecky: CS1300 Spring 2018
// Recitation: 107-Sayali Sonawane
// Cloud9 link: https://ide.c9.io/liry9073/csci1300
// Homework 6 Problems 1-5

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


/**Algorithm: Take an input file and add the words in that file to the correctWords[]
 * #1) use a for loop to go through the array and see how many correct words are currently already inside
 * #2) use ifs to check if the file failed to open or if the starting index is greter than or equal to the size of the array
 * #3) use a while loop to add words from the input file at the index of the array [i+startIndex]. Keep track of added strings
 * #4) close the input file
 * #5) after kicking out of the while loop, return the number of words now in the array
 * Input parameters: string filename, string correctWords[], int size, int startIndex
 * Output: Nothing
 * Returns: total number of correct words in array correctWords[]
*/

int ReadCorrectWords(string fileName, string correctWords[], int size, int startIndex){
   
   ifstream in_file; //create an instream variable
   
   in_file.open(fileName); //open file given by user
   
   int wordCount = 0; //int variable to keep track of words
   
   for (int i = 0; i < size; i++){ //use for loop to go through entire array correctWords[] to see current count of words
      
      if(correctWords[i] != ""){ //if the index at i of correct words is not equal to "" add 1 to word count
         
         wordCount ++;
         
      }
      
   }
    if (in_file.fail()) //if file fails to open return -1
   { 
      return -1; 
   }
   
   if(startIndex >= size){ //if starting index is greater than or equal to the 
                            //size of the array, return -1
      return -1;
      
   }
   
   int i = 0; //counter int
   
   string word = ""; //string word to hold input string from file
   
   while(in_file >> word){ //while there is still input from file, keep looping
   
   correctWords[startIndex + i] = word; //initalize index i of array to input string from file
   
   i++; //increment counter by 1
   
   wordCount ++; //increment word input counter by 1
   
   }

in_file.close(); //close the input file

return wordCount; //return the number of words in the array to the user

}

/**Algorithm: Take an input file and add the pairs of words in that file to the misspelledWords[][]
 * #1) use a for loop to go through the array and see how many pairs are currently already inside
 * #2) use ifs to check if the file failed to open or if the starting index is greter than or equal to the rows of the array
 * #3) use a while loop to add words from the input file at the index of the array [i+startIndex] for each column. Keep track of added strings
 * #4) close the input file
 * #5) after kicking out of the while loop, return the number of pairs now in the array
 * Input parameters: string fileName, string misspelledWords[][2], int rows, int startIndex
 * Output: Nothing
 * Returns: number of pairs of words in the array, -1 if the file does not open or if start index is > rows
*/

int ReadMisspelledWords(string fileName, string misspelledWords[][2], int rows, int startIndex){
   
   ifstream in_file; //create an instream variable
   
   in_file.open(fileName); //open file given by user
   
    if (in_file.fail()) //if file fails to open return -1
   { 
      return -1; 
   }
   
   if(startIndex >= rows){ //if starting index is greater than or equal to the 
                            //rows of the array, return -1
      return -1;
      
   }
   
   int wordCount = 0; //int variable to keep track of words
   
   for (int i = 0; i < rows; i++){ //use for loop to go through entire array correctWords[] to see current count of words
      
      if(misspelledWords[i][1] != ""){ //if the index at i of correct words is not equal to "" add 1 to word count
         
         wordCount ++;
         
      }
      
   }
   
   string word1 = ""; //holder string for first word on line in file 
   
   string word2 = ""; //holder string for second word on line in file
   
   int x = 1; //counter variable starts at 1
   
  while(in_file >> word1 >> word2){ //while there is still input from the given file
     
     misspelledWords[startIndex + x][0] = word1; //the misspelled index is equal to the first word
     
     misspelledWords[startIndex + x][1] = word2; //the correctly spelled index is equal to the second word
     
     x++; //increment counter by 1
     
     wordCount++; //increment word count by 1

  }

in_file.close(); //close the input file

return wordCount; //return the number of words in the array to the user


}

/**Algorithm: Take a word and check that it is spelled correctly
 * #1) turn the string into lowercase
 * #2) use for loops to traverse throguh each array and compare the string to our know words and misspellings
 * #3) if the word is found in any of those arrays, return the correct spelling
 * #4) if the word is not found in any of those arrays, return "unknown"
 * Input parameters: string word, string correctWords[], int sizeCorrectWords, string misspelledWords[][2], int rows
 * Output: Nothing
 * Returns: the correctly spelled word, if it cannot be indentified return "unknown"
*/

string CheckWord(string word, string correctWords[], int sizeCorrectWords, string misspelledWords[][2], int rows){
   
   transform( word.begin(), word.end(), word.begin(), ptr_fun <int, int> ( tolower ) ); //turn to lowercase using transform function
   
   for(int i = 0; i <= sizeCorrectWords; i++){ //check if word is correctly spelled by going through correct words array
      
      if(correctWords[i] == word){
         
         return word; //if the word is found there, return it
         
      }
      
   }
   
   for(int i = 0; i < rows; i++){ //search for the misspelling in our array of known misspellings
      
      if(misspelledWords[i][0] == word){
         
         return misspelledWords[i][1]; //if it is found there, return the correct spelling located 1 column to the right 
         
      }
      
   }
   
   return "unknown"; //if the word is not found in either array, return "unknown"

}

/**Algorithm: Checks the spelling of an entire phrase and appends the corrected phrase to a file
 * #1) break the string phrase into individual words placed into an array of strings 
 * #2) use the word check function to see if it is spelled correctly or not 
 * #3) append the phrase to the end file 
 * #4) close the file in write function
 * Input parameters: string phrase, string outputFile, string correctWords[], int sizeCorrectWords, string misspelledWords[][2], int rowsMisspelledWords
 * Output: writes corrected phrase to user given file
 * Returns: Nothing
*/

void CheckPhrase(string phrase, string outputFile, string correctWords[], int sizeCorrectWords, string misspelledWords[][2], int rowsMisspelledWords){
    
    ofstream writeFile; //create ofstream variable
    
    writeFile.open(outputFile, fstream::app); //open file in append mode
    
    writeFile << endl; //add a line to current file 
    
   if (phrase == ""){ //if phrase is empty return this string
      
      cout << "Phrase is empty. Nothing to write in file." << endl;
      
      return;
      
   }else{ //if not empty, continue
      if(writeFile.fail()){//if file fails to open, print this string 
         
         cout << "Unable to create/ access output file.";
      }
      else{ //if both of these are satisfied, go here
         
          string wordsPhrase[100]; //create an array of size 100 to hold the words from the phrase
   
   string holder = ""; //string to hold the strings pulled out of the phrase
   
   int wordCount = 0; //create word counter int 
   
   for(int i = 0; i < phrase.length(); i++){ //as long as i is less then the length of the phrase, continue looping 
      
       if(i == phrase.length()-1){ //if you are at the last index, perform this code
            
         holder = holder + phrase[i];   
            
         wordsPhrase[wordCount] = holder;
         
         holder = "";
         
         wordCount++;
         
         }
         else{ //if you are not at the last index, perform this code
          if((phrase[i] != ' ') ){
         
          holder = holder + phrase[i];
         
      }
      else{//if you end up at this line of code, set the index word count of the array to the current string you pulled out
         
         wordsPhrase[wordCount] = holder;
         
         holder = ""; //reset holder to an empty string
         
         wordCount++; //increment word count
         
      }
         }
   }
   
   for(int i = 0; i < wordCount; i++){ //continue looping while i is less than the size of the wordsPhrase array
      
      wordsPhrase[i] = CheckWord(wordsPhrase[i], correctWords, sizeCorrectWords, misspelledWords, rowsMisspelledWords);//check the word at the current index
      
      if(i == wordCount - 1){ //if you are at the last index, write to the file, but no space
         
          writeFile << wordsPhrase[i];
          
      }
      else{ //otherwise, write to the file with a space 
         
      writeFile << wordsPhrase[i] << " ";
      
      }
   }
   
   writeFile.close(); //close the file in write mode
         
         
      }
   }

}

/**Algorithm: Checks the spelling over an entire file
 * #1) use an if statement to ensure that the file was opened properly
 * #2) use a while loop to loop through every line in the file and check it for spelling. Then append the corrected line to a new file
 * #3) close file in read mode
 * Input parameters: string phrase, string outputFile, string correctWords[], int sizeCorrectWords, string misspelledWords[][2], int rowsMisspelledWords
 * Output: writes corrected phrase to user given file
 * Returns: Nothing
*/

void CheckFile(string inputFile, string outputFile, string correctWords[], int sizeCorrectWords, string misspelledWords[][2], int rows){
   
   ifstream fromFile;
   
   fromFile.open(inputFile);
   
   string line;
   
    if (fromFile.fail()){
      
      cout << "invalid";
      
   }
   
   while(getline(fromFile, line)){
  
       if(line != ""){
      
      CheckPhrase(line, outputFile, correctWords, sizeCorrectWords, misspelledWords, rows);
      
      }
   
   }
      
      fromFile.close();
      
   
  
   
}



int main()
{  

string correctWords[5000]; //array for correct words to read into
   
ReadCorrectWords("VALID_WORDS_3000.txt", correctWords, 5000, 0); //Problem 1 test 1

string MisspelledWords[5000][2]; //array for mispelled words to read into

ReadMisspelledWords("MISSPELLED.txt", MisspelledWords, 5000, 0); //Problem 2 test 2

cout << CheckWord("ack", correctWords, 5000, MisspelledWords, 5000) << endl; //Problem 3 test 1
   
cout << CheckWord("abouy", correctWords, 5000, MisspelledWords, 5000) << endl; //Problem 3 test 2

cout << endl;

CheckPhrase("Hi my name is Lincoln", "Mary.txt", correctWords, 5000, MisspelledWords, 5000); //Problem 4 test 1

CheckPhrase("qert adsnf asdkfn masd", "Mary.txt", correctWords, 5000, MisspelledWords, 5000); //Problem 4 test 1 

CheckFile("SaveData.txt", "checkFile.txt", correctWords, 5000, MisspelledWords, 5000); //Problem 5 test 1

CheckFile("SaveData copy.txt", "checkFile2.txt", correctWords, 5000, MisspelledWords, 5000); //Problem 5 test 2

cout << ReadCorrectWords("goof.txt", correctWords, 5000, 0) << endl; //Problem 1 test 2

cout << ReadMisspelledWords("goof.txt", MisspelledWords, 5000, 0) << endl; //Problem 2 test 2

   }
   



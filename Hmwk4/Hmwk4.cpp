// Lincoln Rychecky: CS1300 Spring 2018
// Recitation: 107-Sayali Sonawane
// Cloud9 link: https://ide.c9.io/liry9073/csci1300
// Homework 4 problems 1-2

#include <iostream>
#include <string>

using namespace std;

/**
 * Algorithm: Takes in 2 strings and compares them in order to achieve a similarity score
 * 1) use if statements to check that neither string is empty and to make sure they are the same length
 * 2) if they pass the test, use a while loop to compare every index of each sequence to eachother
 * 3) add 1 to hamming score for each dissimilar letter at the same index
 * 4) calculate similarity score and return it to user
 * Input parameters: string sequence1, string sequence2
 * Output: nothing
 * Returns: -1 if input does not pass validity test, returns float similarityScore if inputs are valid
 */
 
 float findSimilarityScore(string sequence1, string sequence2){
     
     int traverse = 0; //create an int to use to traverse the strings
     
     float hamming = 0; //will add one to this variable each time a similarity is found
     
     
     if((sequence1.length() != sequence2.length()) || ((sequence1 == "") || (sequence2 == "")) ){ //if either string is empty or different lengths, return -1
         
         return -1;
         
     }
     
     while(traverse <= sequence1.length()){ //while the traverse int indicating the index of the sequence we are checking is equal to length, continue looping
         
        if(sequence1[traverse] != sequence2[traverse]){ //if the characters at the same index in both strings aren't equal, add 1 to hamming.
            
            hamming = hamming + 1;
            
        }
         
         traverse = traverse + 1; //increment the traverse int by 1 to go to the next index
         
     }
     
     float similarityScore = (sequence1.length() - hamming) / sequence1.length(); //create float to hold similarityScore and calculate similarity score
     
     return similarityScore; //return similarity score to user
     
 }

/**
 * Algorithm: Takes in a string genome and a string sequence and finds the highest similarity substring compared to the sequence within the genome 
 * 1) use if statements to make sure neither input is an empty string and that the sequence is not longer than the genome
 * 2) use a while loop to traverese through the genome and create and check every possible substring compared to the sequence
 * 3) if the new substring has a higher similarity, replace the old highest similairty value 
 * 4) once you kick out of the while loop, return the highestSimilarity value
 * Input parameters: string genome, string sequence 
 * Output: nothing
 * Returns: -1 if an input is empty, -2 if length of sequence is greater than length, float bestMatch if inputs are valid
 */

float findBestMatch (string genome, string sequence){
    
    if ((genome == "") || (sequence == "")){ //if either string is empty return -1
        
        return -1;
        
    }
    
    if (sequence.length() > genome.length()){ //if sequence is greater in length than the length of genome, return -2
        
        return -2;
        
    }

    int sequencelength = sequence.length(); // create a length value to keep track of the length of the substring
    
    int positionCounter = 0; //create a position counter to count where the leading number in substring is at
    
    string sub1; //declare a string to be used as the variable to hold the smaller substrings created in the while loop
    
    float bestSimilarity = 0;
    
    while(positionCounter <= (genome.length() - 1)){ //while the position counter is <= the length of string1 - 1, continue looping
        
        sub1 = genome.substr(positionCounter, sequencelength); //initialize sub1 into a string made in this substring
        
        float similar = findSimilarityScore(sub1, sequence); //create a similarity score between the substring and the sequence
        
        if (similar > bestSimilarity){ //if the similarity score is better than the current one, replace the current one
            
            bestSimilarity = similar;
            
        }
        
        positionCounter = positionCounter + 1; //update the position of the leading number in the substring
        
    }

return bestSimilarity; //after exiting the while loop, return the occurance value

}







int main() {
    
  //creating variables to hold the inputs  
  string genome1;
    
  string genome2;
    
  string genome3;
    
  string sequence;
  //prompt user to input genomes 1-3 as well as sequence  
  cout << "Please enter genome 1:" << endl;
  
  cin >> genome1;
  
  cout << "Please enter genome 2:" << endl;
  
  cin >> genome2;
  
  cout << "Please enter genome 3:" << endl;
   
  cin >> genome3;
   
  cout << "Please enter a sequence:" << endl;
  
  cin >> sequence;
   
  //while the sequence is longer than any of the input genomes, continue prompting user to input a shorter sequence 
  while ((sequence.length() > genome1.length()) || (sequence.length() > genome2.length()) || (sequence.length() > genome3.length())){
      
      cout << "Sequence cannot be longer than genomes." << endl;
      
      cout << "Please enter a sequence:" << endl;
      
      cin >> sequence;
      
  }
   
   //if any of the inputs are blank, print out a statement notifying the user they cannot be blank
   if((genome1 == "") || (genome2 == "") || (genome3 == "") || (sequence == "")){
       
       
       cout << "Genome and sequence cannot be empty." << endl;
   }
   
  //calculating the best match within each of the genomes
  float matchGenome1 = findBestMatch(genome1, sequence);
  
  float matchGenome2 = findBestMatch(genome2, sequence);
  
  float matchGenome3 = findBestMatch(genome3, sequence);
  
  //if any of the genomes are blank the program will not enter this section 
  if((genome1 != "") && (genome2 != "") && (genome3 != "") && (sequence != "") ){
      
  //if genomes 1 is the best match or equaly good as either genome, print that Genome 1 is the best match
  if ((matchGenome1 >= matchGenome2) && (matchGenome1 >= matchGenome3)){
      
     cout << "Genome 1 is the best match." << endl;
      
      }
 
  //if genomes 2 is the best match or equaly good as either genome, print that Genome 2 is the best match
  if((matchGenome2 >= matchGenome1) && (matchGenome2 >= matchGenome3)){
          
     cout << "Genome 2 is the best match." << endl;
          
      }
      
  //if genomes 3 is the best match or equaly good as either genome, print that Genome 3 is the best match    
  if((matchGenome3 >= matchGenome1) && (matchGenome3 >= matchGenome2)){
          
     cout << "Genome 3 is the best match." << endl;
          
      }
      
  }
      
}
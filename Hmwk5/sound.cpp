
/**
 * Good job!
 */
// Lincoln Rychecky: CS1300 Spring 2018
// Recitation: 107-Sayali Sonawane
// Cloud9 link: https://ide.c9.io/liry9073/csci1300
// Homework 5 Problems 1-4


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

/*
   This program processes a 16 bit uncompressed mono .WAV file.
   Courtesy of Cay Horstman (Wiley Publisher)
*/

/**
   Processes the sound samples. Modify this function to change
   the way the sound is processed.
   @param samples the sound samples in the sound file
   @param size the number of samples
*/
void process(int samples[], int size)
{
   // Here, we make the sound three times as loud

   for (int i = 0; i < size; i++)
   {
      samples[i] = 3 * samples[i];
   }
}



/**
   Processes the sound samples. Reverses the values in the samples array.
   @param samples the sound samples in the sound file
   @param size the number of samples
*/

/**Algorithm: reverse
 * #1) Create a copy array of the input array
 * #2) Use a for loop in order to go through the original array and set each index the the index at the end of the copy
 */
 
void reverse(int samples[], int size){
   
   int samplesCopy[size]; //create array of same length as samples[]
   
   for (int x = 0; x < size; x++){ //copy samples[] into the copy array
       
       samplesCopy[x] = samples[x];
       
   }
   
   
   for (int i = 0; i < size; i++) //go through the entire array
   {
      
      samples[i] = samplesCopy[(size-1)-i]; //set samples to the index size - 1 -i until i is greater than size. Should reverse Array
      
   }
   
}




/**
   Processes the sound samples. Adds an echo to the samples array: 
   Take a sample and replace it by the sum of its original value and 
   another value, from "delay" seconds earlier.  
   @param samples the sound samples in the sound file
   @param size the number of samples
   @param sample_rate the number of samples per second
   @param delay the number of seconds echo delay
*/

/**Algorithm: add_echo
 * #1)calcualte the ammount of indexes you will have to go back and save it in a variable
 * #2)create a copy array of the input array
 * #3)go through the original array, and if the index is larger than the ammount of indexes you will have to go 
 * back in order to find the adding value, add that value at the calculated indexes back to the current array value
 */
 
void add_echo(int samples[], int size, int sampleRate, double delay){
   
   double size1 = size;
   
   double sampleRate1 = sampleRate;
   
   double secondsPerBucket = (size1/sampleRate1)/size1; //calculate number of seconds between each individial index
   
   int bucketsBack = delay/secondsPerBucket; //calculate the number of indexes you'll have to move backwards
   
   int samplescopy[size]; //initialize an array ot copy all values into 
   
   for (int i = 0; i < size; i++){
      
      samplescopy[i] = samples[i];
      
   }
   
   for (int x = 0; x < size; x++){ 
      
      if(x < bucketsBack){ //if the index is less than the number of indexes you'll have to move back, do nothing
         
         samples[x] = samples[x] + 0;
         
      }
      else{ //otherwise, set sample[x] to the value it contains plus the value x indexes back
         
         samples[x] = samplescopy[x] + samplescopy[x-bucketsBack];
         
      }
      
   }
   
}


// your function normalize() goes here
/**
   Processes the sound samples. Normalize the values in the samples array:
   Find the maximum value. Multiply all samples by 36773 and divide by the maximum value.
   @param samples the sound samples in the sound file
   @param size the number of samples
*/

/**Algorithm: normalize
 * #1) find the max value by going through the array with a while loop
 * #2) perform the normalizing operation on each value in the array
 */
void normalize(int samples[], int size){

int max = 0; //create a variable to hold the max value

int i = 0; // create counter variable

while (i < size){ //while counter is less than size continue looping
   
   if (samples[i] > max){ //if samples[i] > max, replace max with that value
      
      max = samples[i];
      
   }
   
   i ++; //increment counter by 1
   
}

int x = 0; //create counter variable

int mult = 36773; //store the value used to normalize in a variable for easy access

while(x < size){ //while counter is less than size continue looping
   
   samples[x] = (samples[x] * mult)/max; //perform the normalizing function on the value in samples[x]
                                         //and assign that new value to that bucket
   x++;
   }

}

// -------------------------------------------------------------------

/*
  The code below processes a file in the WAV format.
  You can use this program to manipulate sound files without 
  reading or understanding the code below. 

  The code uses C++ features that are introduced in chapters 7 and 8, 
  as well as the internals of the WAV format 
  (https://ccrma.stanford.edu/courses/422/projects/WaveFormat/)
*/

/**
   Gets an unsigned 4-byte integer from a binary stream.
   @param stream the stream
   @return the integer 
*/
int get_unsigned_int4(fstream& stream)
{
   int result = 0;
   int base = 1;
   for (int i = 0; i < 4; i++)
   {
      result = result + stream.get() * base;
      base = base * 256;
   }
   return result;
}

/**
   Gets an unsigned 2-byte integer from a binary stream.
   @param stream the stream
   @return the integer
*/
int get_unsigned_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   return lo + 256 * hi;
}

/**
   Gets a signed 2-byte integer from a binary stream.
   @param stream the stream
   @return the integer
*/
int get_signed_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   int result = lo + 256 * hi;
   if (result >= 32768) { result = result - 65536; }
   return result;
}

/**
   Puts a signed 2-byte integer to a binary stream.
   @param stream the stream
   @param value the integer to put
*/
void put_signed_int2(fstream& stream, int value)
{
   if (value < 0) { value = value + 65536; }
   stream.put(value % 256);
   stream.put(value / 256);
}

int main()
{
   cout << "Please enter the file name: ";
   string filename;
   cin >> filename;

   fstream stream;

   // Open as a binary file
   stream.open(filename.c_str(), ios::in | ios::out | ios::binary);

   // Check that we can handle this file
   stream.seekg(20);
   int format_type = get_unsigned_int2(stream);
   if (format_type != 1)
   {
      cout << "Not an uncompressed sound file." << endl;
      return 1;
   }
   int num_channels = get_unsigned_int2(stream);
   if (num_channels != 1)
   {
      cout << "Not a mono sound file." << endl;
      return 1;
   }

   int sample_rate = get_unsigned_int2(stream);

   stream.seekg(34);
   int bits_per_sample = get_unsigned_int2(stream);
   if (bits_per_sample != 16)
   {
      cout << "Not a 16 bit sound file." << endl;
      return 1;
   }

   // Read data size and allocate data array
   stream.seekg(40);
   int data_size = get_unsigned_int4(stream) / 2; // 2 bytes per data
   int* samples = new int[data_size];

   // Read sound data
   for (int i = 0; i < data_size; i++) 
   {
      samples[i] = get_signed_int2(stream);
   }

   double delay1 = 2.0;

   add_echo(samples, data_size, 2, delay1);


   // A. Reverse
   // 1. Call the reverse function

   // B. Add echo
   // 1. Declare and initialize variable for echo delay
   // 2. Call the add_echo function
   // 3. Call the normalize function

   // Write sound data
   stream.seekp(44);
   for (int i = 0; i < data_size; i++)
   {
      put_signed_int2(stream, samples[i]);
   }

   stream.close();

   delete[] samples;
     
   return 0;
}

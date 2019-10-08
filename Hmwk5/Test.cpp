#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void reverse(int samples[], int size){
   
   int samplesCopy[size];
   
   for (int x = 0; x < size; x++){
       
       samplesCopy[x] = samples[x];
       
   }
   
   
   for (int i = 0; i < size; i++)
   {
      
      samples[i] = samplesCopy[(size-1)-i];
      
   }
   
  
   
}

void normalize(int samples[], int size){

int max = 0;

int i = 0;

while (i < size){
   
   if (samples[i] > max){
      
      max = samples[i];
      
   }
   
   i ++;
   
}

int x = 0;

int mult = 36773;

while(x < size){
   
   samples[x] = (samples[x] * mult)/max;
   
   x++;
}


}

void add_echo(int samples[], int size, int sampleRate, double delay){
   
   double size1 = size;
   
   double sampleRate1 = sampleRate;
   
   double secondsPerBucket = (size1/sampleRate1)/size1;
   
   int bucketsBack = delay/secondsPerBucket;
   
   int samplescopy[size];
   
   for (int i = 0; i < size; i++){
      
      samplescopy[i] = samples[i];
      
   }
   
   for (int x = 0; x < size; x++){
      
      if(x < bucketsBack){
         
         samples[x] = samples[x] + 0;
         
      }
      else{
         
         samples[x] = samplescopy[x] + samplescopy[x-bucketsBack];
         
      }
      
   }
   
}


int main(){

int test[] = {1,2,3};

reverse(test, 3);

for(int i = 0; i < 3; i++){
    
    cout << test[i];
    
}

cout << endl;

int test2[] = {5,3,1};

normalize(test2,3);

for(int x = 0; x < 3; x++){
    
    cout << test2[x] << " ";
    
}

cout << endl;

int test3[] = {5, 8, 3, 10, 6, 2};

add_echo(test3,6,2,2.0);

for(int y = 0; y < 6; y++){
    
    cout << test3[y] << " ";
    
}



}
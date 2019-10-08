#include <iostream>

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

int main(){
    
    
    
}
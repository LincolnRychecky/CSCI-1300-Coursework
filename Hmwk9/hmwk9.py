# Lincoln Rychecky: CS1300 Spring 2018
# Recitation: 107-Sayali Sonawane
# Cloud9 link: https://ide.c9.io/liry9073/csci1300
# Homework 9 problems 1-5

def split(splitString, listString, charSeperator): #Split helper function
    i = 0
    string1 = ""
    string2 = ""
    
    while splitString[i] != charSeperator:
        string1 += splitString[i]
        i+=1
    i+=1
    
    while i < len(splitString):
        string2 += splitString[i]
        i+=1
    listString.append(string1)
    listString.append(string2)

#Algorithm: Takes a list of names and splits them to add the first part as a key if not already in dictionary
#and then adds the second part of the string as a definition of the first part
#Inputs: listNames
#Outputs: NewDictionary
def countNames(listNames): #Count names function
    NewDictionary = {}
    for fullName in listNames:
        firstAndLast = fullName.split()
        if len(firstAndLast) < 2:
            continue
        if firstAndLast[0] not in NewDictionary.keys():
            NewDictionary[firstAndLast[0]] = [firstAndLast[1]]
        else:
            NewDictionary[firstAndLast[0]].append(firstAndLast[1])

    return NewDictionary

#Algorithm: Reads in a file of scores, assignment, and weight and then creates a wieghted average
#Inputs: file_name
#Outputs: sumFinal
def compute_grade(file_name):
    try:
        f = open(file_name)
    except:
        return "File not found"
    sumFinal = 0
    for line in f:
        gradesNSuch = line.split(',')
        li2 = gradesNSuch[:-2]
        for i in range(len(li2)):
            li2[i] = float(li2[i])
        sumFinal += ((sum(li2)/len(li2))*float(gradesNSuch[-1]))
    f.close()
    return sumFinal
    
#Algorithm: Reads in keys and definitions and adds them to a passed dictionary
#Inputs: file_name, dictionary_one
#Outputs: dictionary_one
def update_dictionary(file_name, dictionary_one):  
    try:
        previous_size = len(dictionary_one)
        f = open(file_name)
        print(file_name,"loaded successfully.")
    except:
        print(file_name,"does not exist.")
        print("The dictionary has",previous_size,"entries.")
        return dictionary_one
    for line in f:
        Key_N_Def = line.split(',')
        if len(Key_N_Def) < 2:
            continue
        if Key_N_Def[0] not in dictionary_one.keys():
            previous_size+=1
        dictionary_one[Key_N_Def[0]] = Key_N_Def[1][:-1]
        
      
    print("The dictionary has",previous_size,"entries.")

    return dictionary_one

#Algorithm: Takes in a sentence and deslangs it by changing slang words to real words that are part of a 
#Dictionary
#Inputs: slang_string, dictionary_one
#Outputs: string_corrected
def deslang(slang_string, dictionary_one):
    list_words = slang_string.split(' ')
    for i in range(len(list_words)):
        if list_words[i] in dictionary_one.keys():
            list_words[i] = dictionary_one[list_words[i]]

    string_corrected = ""
    
    for x in range(len(list_words)):
        if x == len(list_words) -1:
            string_corrected += list_words[x]
        else:
            string_corrected += list_words[x] + " "
            
    return string_corrected    

def main():
    dictionary_main = {}

    print("Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: ", end = '')
   
    choice = input()
   
    while choice != "a" and choice!= "d" and choice != "q":
        print("Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: ", end = '')
        choice = input()
       
    while choice != "q":
       
        if choice == "a":
            print("Enter a filename: ", end = '')
            choice_a = input()
            while choice_a == "":
                 print("Enter a filename: ", end = '')
                 choice_a = input()
            update_dictionary(choice_a,dictionary_main)
       
       
        if choice == "d":
            print("Enter a sentence: ", end = '') 
            choice_b = input()
            while choice_b == "":
                print("Enter a sentence: ", end = '')
                choice_b = input()
            print(deslang(choice_b,dictionary_main))
        print("Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: ", end = '')
        choice = input()
        while choice != "a" and choice!= "d" and choice != "q":
            print("Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: ", end = '')
            choice = input()   
               
               
       
if __name__ == "__main__":
    main()
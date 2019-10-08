
def hash_func(inputString):
    i = 0
    hashValue = 0
    while i < len(inputString):
        if inputString[i] == "a":
            hashValue += (len(inputString) + 1)
        elif inputString[i] == "b":
            hashValue += (len(inputString) + 2)
        elif inputString[i] == "c":
            hashValue += (len(inputString) + 3)
        elif i >= 0:
            hashValue += 1
        
        i+=1
        
    return hashValue%10

def GetItems(listOfValues, target):
    listOfCValues = []
    i = 0
    numIn = 0
    while i < len(listOfValues):
        if listOfValues[i][0] == target:
            listOfCValues.append(listOfValues[i])
            numIn += 1
        i += 1
    return listOfCValues
    
def LoadMovieData(file_name):
    dictionary_one = {}
    try:
        f = open(file_name)
    except:
        return -1
    
    for line in f:
        newLine = line.strip()
        Key_N_Def = newLine.split(':')
        if len(Key_N_Def) < 2:
            continue
        if Key_N_Def[1] not in dictionary_one.keys():
            dictionary_one[Key_N_Def[1]] = Key_N_Def[0]
    
    return dictionary_one
    
def main():
    
   print(LoadMovieData("scores.txt"))
   
    
if __name__ == "__main__":
    main()
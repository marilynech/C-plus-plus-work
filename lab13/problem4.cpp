#include <iostream>
#include <string>
using namespace std; 

//loop to size of array then use couts to function getPrifixes
//copys first three elements of array 
//in next function take new array and copy and store in the five words
// take all string in array and return concatination of array in the string 

void readInput(string arr[], int cap){
    cout<<"Enter "<<cap<<" words:";
    for(int i = 0; i < cap; i++){
        cin>>arr[i]; 
    }
}

void getPrefixes(string start[], string end[], int size){
    for(int i = 0; i < size; i++){
        if(start[i].length() >= 3){
            end[i] = start[i].substr(0,3); //copying first 3 letters
        }
        else{
            end[i] = start[i]; //if word has less than 3 chars 
        }
    }
}

string concatenateStrings(string arr[], int cap){
    string answer = ""; 
    for(int i = 0; i < cap; i++){
        answer += arr[i]; 
    }
    return answer; 
}

int main(){
    string words[5];
    string prefixes[5]; 

    readInput(words, 5); 
    getPrefixes(words, prefixes, 5);

    string concatenatedStrings = concatenateStrings(prefixes, 5); 

    cout<<"The concatenated string is "<<concatenatedStrings<<endl; 

    return 0; 
}

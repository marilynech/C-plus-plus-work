#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std; 

char randomChar(){
    return static_cast<char>(rand() % 26 + 97);
}

void fillCharArray(char arr[][4], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = randomChar(); 
        }
    }
}

void printArray(char arr[][4], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<<arr[i][j]<<" "; 
        }
        cout<<endl; 
    }
}

void vowelsPerRow(char arr[][4], int vowelCount[], int rows, int cols){
    for(int i = 0; i < rows; i++){
        vowelCount[i] = 0; 
        for(int j = 0; j < cols; j++){
            char ch = arr[i][j];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowelCount[i]++; 
            }
        }
    }
}

void vowelsPerCol(char arr[][4], int vowelCount[], int rows, int cols){
    for(int j = 0; j < cols; j++){
        vowelCount[j] = 0; 
        for(int i = 0; i < rows; i++){
            char ch = arr[i][j];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowelCount[j]++;
            }
        }
    }
}

void printVowelRows(int vowelCount[], int rows){
    for(int i = 0; i < rows; i++){
        if(vowelCount[i] > 0){
            cout<<"Row "<<i<<" contains "<<vowelCount[i]<<" vowels."<<endl; 
        }
    }
}

void printVowelCols(int vowelCount[], int cols){
    for(int i = 0; i < cols; i++){
        if(vowelCount[i] > 0){
            cout<<"Column "<<i<<" contains "<<vowelCount[i]<<" vowels."<<endl; 
        }
    }
}
//do random char first randomChar -> generates random char for fillarray func do part c first 
//part d take same argument as first function printCharArray -> print out 2D array(char, width , height)
//print out like a table 
//change original array with pass by reference & 

int main(){

    //declare a 2 x 4 character array 
    char charArray[2][4]; 

    //declare an integer array of size 2
    int rowVowels[2];

    //"""" size 4
    int colVowels[4];

    //call the srand fun to seed the rand num generator using time(0)
    srand(static_cast<unsigned int>(time(0))); 

    //call fillChar pass into char array and  2 and 4
    fillCharArray(charArray, 2, 4);

    //call printArray pass into char array and in 2 and 4
    cout<<"Character array:"<<endl;
    printArray(charArray, 2, 4);

    //call vowelsPerRow pass in char array and int array of size 2,2, and 4
    vowelsPerRow(charArray, rowVowels, 2,4);

    //call function vowelsPerCol pass into array int of array size 4, 2 and 4
    vowelsPerCol(charArray, colVowels, 2, 4); 

    printVowelRows(rowVowels, 2); 
    printVowelCols(colVowels, 4);

    return 0;

}
//strings in C++ are passed by reference take both the strings by reference use & in both arguments
//then swap first character of a string string[0] 
//swap using swap code u know aleady

#include <iostream>
#include <string>
using namespace std; 

void swapFirstLetters(string &str1, string &str2){
    if(!str1.empty() && !str2.empty()){
        char temp = str1[0];
        str1[0] = str2[0];
        str2[0] = temp; 
    }
}

int longestString(string str1, string str2){
    if(str1.length() >= str2.length()){
        cout<<str1<<" is the longest string."<<endl; 
        return str1.length();
    }
    else{
        cout<<str2<<" is the longest string."<<endl; 
        return str2.length(); 
    }
}

void repeatHello(int n){ // use length from longest string of first and last name here 
    for(int i = 0; i < n; i++){
        cout<<"hello";
    }
    cout<<endl; 
}

int main(){
    string firstName, lastName; 

    cout<<"Please enter your first name: ";
    cin>>firstName; 

    cout<<"Please enter your last name: "; 
    cin>>lastName; 

    swapFirstLetters(firstName, lastName); 

    cout<<"Your new first name is "<<firstName<<endl;
    cout<<"Your new last name is "<<lastName<<endl; 

    int length = longestString(firstName, lastName); 
    repeatHello(length); 

    return 0; 

}

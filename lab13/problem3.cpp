#include <iostream>
using namespace std; 

void bookEndString(string &s, int r){
    if(s[0] == s[s.length() - 1]){
        string repeatedChar(r, s[0]);
        s = repeatedChar + s + repeatedChar; 
    }
    else{
        string repeatZ(r,'Z');
        s = repeatZ + s + repeatZ;
    }
}

int main(){
    string inputString; 
    int r; 

    cout<<"Enter a word with atleast three letters: "; 
    cin>>inputString;

    while(inputString.length() < 3){
        cout<<"Invalid input! Enter a word with atleast three letters: "; 
        cin>>inputString; 
    }

    cout<<"Enter a number greater than zero: "; 
    cin>>r; 

    while(r <= 0){
        cout<<"Invalid input! Enter a number greater than zero: ";
        cin>>r; 
    }

    bookEndString(inputString, r); 

    cout<<"The modified word is: "<<inputString<<endl; 

    return 0; 
}
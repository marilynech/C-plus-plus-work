#include <iostream>
using namespace std; 

int main(){
    //string names int scores indexes are the same for both 
    //need to write a loop from 0 to 2 print name[i;s ] scores[i] you can do it in one for loop 

    //output from each array at each index values are the same index
    string names[3] = {"Marilyn", "Alice", "Bob"};
    int scores[3] = {100, 90, 80}; 

    for(int i = 0; i < 3; i++ ){
        cout<< names[i]<<"'s score is "<<scores[i]<<"."<<endl; 
    }

    return 0; 
}
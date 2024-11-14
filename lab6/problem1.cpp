#include <iostream>
using namespace std; 

int main(){
    double salary = .01; 
    int day = 1; 

    cout<<"Day \tSalary: "<<endl; 
    while(salary <= 10000){
        cout<< day <<"\t"<<salary<<endl; 
        day++; 
        salary *= 2;
    }

    cout<<day<<"\t"<<salary<<endl; 

    return 0; 
}
#include <iostream>
using namespace std; 

int main(){
    int ang1,ang2,ang3;

    cout<<"Please enter 3 angles in degress"<<endl; 
    cin>>ang1>>ang2>>ang3; 

    if(ang1 + ang2 + ang3 == 180){
        cout<<"Can form a triangle with these angles."<<endl; 

        if(ang1 == 60 && ang2 == 60 && ang3 == 60)
            cout<<"This triangle is an equalateral triangle.";
        else if(ang1 == 90 || ang2 == 90 || ang3 == 90)
            cout<<"The triangle is a right triangle."; 
        else 
            cout<<"The triangle is neither equilater or right, it's just a triangle."; 
    }
    else{
        printf("Cannot form a triangle with these angles.");
    }
   
    return 0;  
}
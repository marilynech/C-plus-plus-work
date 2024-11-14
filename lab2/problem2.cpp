#include <iostream> 
using namespace std; 

int main(){

    double widthOfPaper = 8.5;
    int heightOfPaper = 11;
    double areaOfPaper = widthOfPaper * heightOfPaper;
    double perimeterOfPaper = (2 * widthOfPaper) + (2 * heightOfPaper);

    cout<<"The area of a letter-sized paper is "<<areaOfPaper<<endl; 
    cout<<"The perimeter of a letter-sized paper is "<<perimeterOfPaper<<endl; 

    return 0;

}
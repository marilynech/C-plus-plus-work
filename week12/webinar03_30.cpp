#include <iostream>
#include <string>
using namespace std; 

class Thing{
    int num; 
public: 
    /*explicit*/ Thing(int newnum = 0): num(newnum){}//constructor //creates a thing out of a int
    int getNum() const{return num; }//getter to get number
    void setNum(int newnum) {num = newnum; }
    //memeber only one parameter this object is lhs 
    Thing operator+(const Thing& rhs) const; //has to be const bc x is
    Thing& operator++(); //pre increment
    Thing operator++(int);  //post increment
    void demoThisfunc()const; 
};
void Thing::demoThisfunc() const{
    cout<<this<<endl; 

}

Thing& Thing::operator++(){
    num++;
    return *this; //return the this object
}

Thing Thing::operator++(int){
    Thing temp = *this; //copy object of this object
    num++;//then increment value
    return temp; //then return original 
}

Thing operator-(const Thing& lhs, const Thing& rhs){//non member two parameters 
    return lhs.getNum() - rhs.getNum(); 
}
void fun(const Thing& x){
    //x.setNum(100); //unexcepted x is constified and calling a functon thats not const
    //but if 
    x.getNum(); //this is okay
    Thing three = x + 5; 

}

Thing Thing::operator+(const Thing& rhs) const{
    return num + rhs.num; //what is return data type? 
    //C++ does this automatic implicit call to a constructor and passing in the value 
}

int maint(){
    Thing one(1);
    one.demoThisfunc(); //this is same variable as 1 to left is calling object 
    cout<<one.getNum()<<endl; 
    Thing two(2); 

    Thing three = one + two; //function call: three.operator = result (one.operator+(two))
    //do this as member or non memeber thing + thing

    fun(two); 
    //cout<<two.getNum()<<endl; //will print 100 not 2 bc passed by reference 


    ++++two; //double preincrement
    ++(++two); //same as aobve
    (two.operator++()).operator++(); //still same as above

    int x = 5 + 6; //we can still add two ints 
    string name = "Mar";
    string lastname = "Ech";
    string fullname = name + lastname; //string concatenation 

    int var = 5; 
    int result = 0 ;
    result = var++; //post incremenet operator 
    //result = func1(); //func 1 returns orginal value
    cout<<var<<endl; //6
    cout<<result<<endl; //5

    int var = 5; 
    int result = 0 ;
    result = ++var; //pre incremenet operator 
   // result = func2(); //func 2 returns the CHANGED VALUE so return value is different 
    cout<<var<<endl; //6
    cout<<result<<endl; //6

}
//anywhere where thing is defined then we know we can add things together
//get num is memeber of class 
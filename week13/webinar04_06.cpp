#include <iostream>
using namespace std; 

void func1(int x){
    cout<< x<<endl;
    x =100;
}
void func2(int& x){
    cout<< x<<endl;
    x =100;
}
void func3(const int& x){
    cout<< x <<endl;
    //x =100;
}
int func4(int x, int y){
    if(x > y)
        return x; 
    return y;   
}
int& func5(int x, int y){ //bad 
    if(x > y)
        return x; 
    return y;   
}
int& func6(int& x, int& y){ //good thing returning is outside 
    int result; 
    if(x > y)
        return x; 
    return y;   
}

class Thing{
    int x; 
public:
    Thing(int newx=0):x(newx){}
    int getx()const {return x; }
    void setx(int newx){x = newx;}
    //void operator = (const Thing& ); 
    Thing& operator = (const Thing& ); 
};

Thing& Thing::operator=(const Thing& rhs){
    x = rhs.x; 
    return *this; 
}
int main(){
    //class
    Thing one(1);
    Thing two; 
    Thing three; 
   // three = two = one; //doesnt work instea two.operator=(one)
   //we have to return by refernce 
   three = two = one;
   
    //func6
    int var1 = 5;
    int var2 = 10; 
    //int result; 
    //result = func4(var1, var2); //5,10
    int&result = func6(var1, var2); 
    result++;
    cout<<"Var1 after func6:"<<var1<<endl; //5
    cout<<"Var2 after func6:"<<var2<<endl;//11
    cout<<"Result after func6:"<<result<<endl;//11 

    int& temp = var1; 
    int& result = func5(var1,var2); 

    int var = 0; 
    func1(var); 
    cout<<"Var after func1"<<var<<endl; 
    func2(var);
    func3(var); 

}
#include <iostream>
using namespace std; 

class Car{
    private:
        double _weight; 
        double _height; 
        string _color; 
        int _numOfWheels; 
        int _year; 
        string _name; 
    public:
        //constructor:
        Car(){
            _weight = 0; 
        }
        Car(double weight){
            _weight = weight; 
        }

        Car(double weight, string name){
            _weight = weight; 
            _name = name; 
        }

        //getters and setters: way to interact with prvivate var setting or getting
        double getWeight(){
            return _weight; //only availabe to insanciated car 
        }

        void displayWeight(){
            cout<<"This car which is a " <<_name<<" has a weight of "<<_weight<<" tons."<<endl; 
        }
};

/*int main(){
    Car chevy(15, "chevy");
    Car tesla(10); 
    cout<<chevy.getWeight(); 

    chevy.displayWeight();
    tesla.displayWeight(); 

    return 0;

}*/

class Pet{
    private:
        int _age;
        string _name; 
        double _weight; 
    public:
        Pet(){
            _age = 0; 
        }

        void setAge(int newAge){
            _age = newAge; 
        }

        void setName(string newName){
            _name = newName; 
        }
       virtual  void speak() = 0; 
       /*{ creates all classes to speak; 
            cout<<"Deafault noise";
        }*/
};

class Dog: public Pet{
    private:
        int barkloudness; 
        int _cuteness; 
    public:
        Dog(){
            this -> setAge(0); 
        }

        Dog(string newName, int cuteness){
            this -> setName(newName);
            setCuteness(cuteness); 
        }

        void setCuteness(int newCuteness){
            if(newCuteness > 10){
                cout<<"too cute! setting highest value of 10"; 
                _cuteness = 10; 
            }
            else{
                _cuteness = newCuteness; 
            }
        }

        int getCutness(){
            return _cuteness; 
        }

        virtual void speak(){
            cout<<"Woof!";
        }
};//dog inhertis pet 

class Cat: public Pet{
    private:
        int scariness; 
        int clawSize; 
        bool stealthMode; 
    public:
        Cat(string newName){
            this -> setName(newName);
        }

        virtual void speak(){
            cout<<"Meow"; 
        }

};

class Bird: public Pet{
    private:
    public:
        virtual void speak(){
            cout<<"Chirp!";
        }
}; 

int main(){
    Dog buba("Buba", 10);
    Cat cheese("Cheese");
    //cout<<Buba.getCutness();
    buba.speak(); 
    cheese.speak(); 
    Bird beyonce; 

    return 0; 
}
//HW 12 Q1 CheckBook Program
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>

using namespace std; 
//void sort(double* arr, int arrSize); //to hold deposits 

class Money{
    public://declare constructors, variables in money class
    friend Money operator +(const Money& amount1, const Money& amount2); //returns sum of values of amount1 and 2
    friend Money operator -(const Money& amount1, const Money& amount2); //returns amount1 -amount2
    friend Money operator -(const Money& amount);//returns negative 
    friend bool operator ==(const Money& amount1, const Money& amount2);//returns true if amount1=amount2 or flase if not
    friend bool operator <(const Money& amount1, const Money& amount2); //returns true if amount1 < amount2 or false
    //Money(long dollars, int cents); //initalizes the object so its value represents an amount with the dollars and cents
    //if amount is neg then both dollars and cents should be neg
    Money(double dollars);//initalizes the object so its value represents $dollars. 00
    Money(); //initalizes the object so its value represents $0.00
    double getValue() const;//returns the amount of money recorded in data portion of the calling object
    friend istream& operator >>(istream& ins, Money& amount); //overloads >> operator so it can be used to input values
    //of type Money. Notation for inputting negative amounts is as in -$100. Precondition: if ins is a file input stream
    //then ins has been connected to a file
    friend ostream& operator <<(ostream& outs, const Money& amount); //overloads << operator so it can be used to output values
    //of type Money. Precedes each output value of type Money with a dollar sign. Precond: if outs is a file output stream
    //then outs has already been connected to a file
    private:
        double allCents;  
}; 

//OPERATIONS: //from textbook
//returns sum of the values 
Money operator +(const Money& amount1, const Money& amount2){
    Money temp; 
    temp.allCents = amount1.allCents + amount2.allCents; 
    return temp; 
}
//return amount1-amount2
Money operator -(const Money& amount1, const Money& amount2){
    Money temp; 
    temp.allCents = amount1.allCents - amount2.allCents; 
    return temp; 
}

//returns negative
Money operator -(const Money& amount){
    Money temp; 
    temp.allCents = -amount.allCents; 
    return temp; 
}

//returns true if amount1 =amount2 or false otherwise
bool operator ==(const Money& amount1, const Money& amount2){
    return(amount1.allCents == amount2.allCents); //will get out if it isnt
}
//returns true if amount1<amount2
bool operator <(const Money& amount1, const Money& amount2){
    return(amount1.allCents < amount2.allCents);
}

Money:: Money(double dollars){
    if (dollars<0){
        cout<<"Illegal value\n";
        exit(1);
    }
    allCents = dollars;
}

Money:: Money(): allCents(0){}

double Money:: getValue() const{
    return allCents;
}

istream& operator >>(istream& ins, Money& amount){
    ins>>amount.allCents;
    return ins;
}

/*istream& operator >>(istream& ins, Money& amount){
    ins>>amount.allCents; 
    return ins; 
}

//Money::Money(long dollars): allCents(dollars * 100){}
double Money::getValue() const{ //returns amount of money in data portion of callin object
    return (allCents * 0.01); //might need to fix 
}

Money::Money(): allCents(0){} //initalizes object so its value is $0.00 

//initalize object my values given 
Money::Money(double dollars){
    if (dollars < 0){
        cout<<"Wrong Value Input"<<endl; 
        exit(1); 
    }
    allCents = dollars;//
}*/

class Check{
    public:
        Check(Money Check); 
        Check(); 
        friend istream& operator >>(istream& ins, Check& check); 
        friend ostream& operator <<(ostream& outs, const Check& check); //to be able to return check and its value
        double getAmount() const; //getter 
        bool gotCashed() const; //func status
        void setAmount(Money Amount); //setter
        void checkCashed(); //func
        void setCheckNum(int numb); //setter
    private: 
        int checkNum; 
        bool cashed; //check if cashed or not
        Money checkAmount; //class within a class uses money class
}; 

Check::Check(Money check): checkAmount(0){
    checkAmount = check.getValue(); 
    cashed = false; //check is the check is cashed or not
}

Check::Check(): checkAmount(0), cashed(false){}; //false if 0 

void Check:: checkCashed(){ //true if 1
    cashed = true; 
}

double Check:: getAmount() const{
    return checkAmount.getValue(); //getter
}

bool Check:: gotCashed() const {
    return this -> cashed; 
}

void Check:: setAmount(Money amount){
    checkAmount = amount.getValue();
}

void Check:: setCheckNum(int numb){
    checkNum = numb; 
}

istream& operator >>(istream& ins, Check& check){//used to input the values of check 
    ins>>check.checkAmount;
    return ins; 
}
//overload << to output values of check num 
ostream& operator<<(ostream& outs, const Check& check){
    outs<<"Check Numer: "<<check.checkNum<<" with amount: $"<<check.checkAmount.getValue(); 
    return outs; 
}

/*Sort the checks into two arrays: checks cashed since the last time you balanced your checkbook and 
checks still not cashed. Display both lists of checks in sorted order from lowest to highest check number.
*/

int main(){
    //define variables for main 
    double newBalance, oldBalance, totalDep, totalCash, bankBalance, currDep; 
    totalDep = 0; 
    totalCash = 0; 
    Money amt; 
    int totalChecks, cashedCheck, numDep; 
    cashedCheck = 0;
    vector<Check> cashedChecks; 
    vector<Check> notCashed; 
    vector<double>deposit; 
    char yesOrNo; 

    cout<<"Please enter your old balance: "<<endl; 
    cin>>oldBalance; 
    cout<<"Please enter the total number of checks you have: "<<endl; 
    cin>>totalChecks; 
    Check checkBook[totalChecks]; 
    cout<<"Enter the "<<totalChecks<<" amounts of the checks and a 'y' if its been cashed or 'n' if not (Press enter for each input)"<<endl; 
    for(int i = 0; i < totalChecks; i++){
        cin>>amt; 
        checkBook[i].setAmount(amt); 
        checkBook[i].setCheckNum(i+1);
        cin>>yesOrNo; 
        if(yesOrNo == 'y' || 'Y'){
            checkBook[i].checkCashed();
            totalCash+= checkBook[i].getAmount();
            cashedChecks.push_back(checkBook[i]);
            cashedCheck++; 
        }
        else if(yesOrNo == 'n' || 'N'){

        }
        else{
            notCashed.push_back(checkBook[i]);
        }
    }

    cout<<"How many deposits did you make?"<<endl; 
    cin>>numDep; 
    cout<<"Enter the amount of each deposit: "<<endl; 
    for(int i = 0; i < numDep; i++){
        cin>>currDep;
        deposit.push_back(currDep);  
    } //figure out how to end by typing 0 later

    //cout<<"The sum of the deposits are: "<<totalDep<<endl; 
    cout<<"All the cashed checks and their numbers are: "<<endl; 
    for(Check i: cashedChecks){
        cout<<i<<" "<<endl; 
    }

    for(int i = 0; i < deposit.size(); i++){
        totalDep+= deposit[i];
        bankBalance = oldBalance + totalDep - totalCash; 
        newBalance = oldBalance + totalDep; //adding deposits and old balance to get current balance
    }

    cout<<"The sum of the cashed checks are: "<<totalCash<<endl; 
    
    for(int i = 0; i < totalChecks; i++){
        newBalance -= checkBook[i].getAmount();
    }
    cout<<"The new balance is: "<<newBalance<<" and the bank balance is: "<<bankBalance<<endl; 
    cout<<"The difference between account hold balance and bank balance is: "<<bankBalance - newBalance<<endl;
 
     if(cashedChecks.size() > 0){
    cout << "The sorted list of cashed checks is: " << endl;
    for(int i = 0; i < cashedChecks.size(); i++){
      cout << cashedChecks[i] << "\n";
    }
    cout << endl;
  }
 
  if(notCashed.size() > 0){
    cout << "The sorted list of uncashed checks is: " << endl;
    for(int i = 0; i < notCashed.size(); i++){
      cout << notCashed[i] << "\n";
    }
    cout << endl;
  }
 
  return 0;
}

//unfinished code doesnt account for the uncashed checks and the newbalance to bank balance difference are off




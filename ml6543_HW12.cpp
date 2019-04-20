//
//  main.cpp
//  ml6543_HW12
//
//  Created by Mina on 10/5/18.
//  Copyright © 2018 Mina. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Money
{
public:
    friend Money add(Money amount1, Money amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money( );
    double get_value( );
    
private:
    long all_cents;
};

Money add(Money amount1, Money amount2)
{
    Money temp;
    
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0) //If one is negative and one is positive
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100)
{
    //Body intentionally blank.
}

Money::Money( ) : all_cents(0)
{
    //Body intentionally blank.
}

double Money::get_value( )
{
    return (all_cents * 0.01);
}




//class check
const int MAX_LIST = 11;

class Check{
    
public:
    Check();
    Check(Money amount);
    Check(Money amount, bool cashedOrNot);
    Check(int thenumber, Money amount, bool cashedOrNot );
    
    friend void print_notCashedChecks(Check check[], int numOfCheck);
    friend void print_CashedChecks(Check check[], int numOfCheck);
    friend Money cashedChecksTotal(Check check[],int numOfCheck);
    friend Money notCashedChecksTotal(Check check[],int numOfCheck);

    
    void output();
    
    void set_AmountOfCheck(Money newAmount);
    void set_cashed(bool cashedOrNot);
    void set_checkNumber(int number);
    
    int get_checkNumber();
    bool get_cashed();
    Money get_AmountOfCheck();
    
    
    
private:
    int numberOfCheck;
    Money amountOfCheck;
    bool cashed;
};




Check::Check(){
    numberOfCheck = 1;
    amountOfCheck = 0;
    cashed = false;
}

Check::Check(Money amount){
    numberOfCheck = 1;
    amountOfCheck = amount;
    cashed = false;
}

Check::Check(Money amount, bool cashedOrNot){
    numberOfCheck = 1;
    amountOfCheck = amount;
    cashed = cashedOrNot;
}

Check::Check(int thenumber, Money amount, bool cashedOrNot){
    numberOfCheck = thenumber;
    amountOfCheck = amount;
    cashed =cashedOrNot;
}


void print_CashedChecks(Check check[], int numOfCheck){
    
    bool cashedOrNot;
    for(int i=1; i<=numOfCheck; i++){
        
        cashedOrNot=check[i].get_cashed();
        
        if(cashedOrNot==true){
            cout<<"check"<<i<<" ";
        }
    }
    
}

void print_notCashedChecks(Check check[], int numOfCheck){
    bool cashedOrNot;
    for(int i=1; i<=numOfCheck; i++){
        
        cashedOrNot=check[i].get_cashed();
        
        if(cashedOrNot==false){
            cout<<"check"<<i<<" ";
        }
    }
    
}

Money cashedChecksTotal(Check check[],int numOfCheck) {
    
    bool cashedOrNot;
    Money total, amt;
    
    for(int i=1; i<=numOfCheck; i++){
        
        cashedOrNot=check[i].get_cashed();
        if (cashedOrNot) {
            amt = check[i].get_AmountOfCheck();
            total = add(total, amt);
        }
    }
    return total;
}

Money notCashedChecksTotal(Check check[],int numOfCheck) {
    
    bool cashedOrNot;
    Money total, amt;
    
    for(int i=1; i<=numOfCheck; i++){
        
        cashedOrNot=check[i].get_cashed();
        if (cashedOrNot==false) {
            amt = check[i].get_AmountOfCheck();
            total = add(total, amt);
        }
    }
    return total;
}

void Check::set_AmountOfCheck(Money newAmount){
    
    amountOfCheck =newAmount;
}
void Check::set_cashed(bool cashedOrNot){
    cashed = cashedOrNot;
}

void Check::set_checkNumber(int number){
    numberOfCheck = number;
}

int Check::get_checkNumber(){
    return numberOfCheck;
}

bool Check::get_cashed(){
    return cashed;
}

Money Check::get_AmountOfCheck(){
    return amountOfCheck;
}


void Check::output(){
    double amount;
    Money checkamount;
    cout<<"\nCheck"<<get_checkNumber();
    cout<<"\nCashed?"<<get_cashed();
    checkamount =get_AmountOfCheck();
    amount = checkamount.get_value();
    cout<<"\nCheck Amount: "<<amount;
    
}





int main( )
{
    Check checkAccount[MAX_LIST];
    Money amtOfCheck, sumOfDepositTotal, originalBalance, cashedCheckTotal, notCashedCheckTotal;
    int i, yesOrNot, n;
    int numOfCheck;
    double tempAmt, currentBalance, customerExpectedBalance;
    bool cashed;
    long dollar;
    int cents;
    
    
    
    cout << "How much was your original Balance? ";
    cin >> tempAmt;
    
    dollar=trunc(tempAmt);
    cents=round((tempAmt-dollar)*100);
    originalBalance=Money(dollar, cents);
    
    //Set up an array of Check Objects
    cout << "\nEnter the number of checks(Under 10): ";
    cin >> n;
    
    if(n>10){
        cout<<"You put a number over 10. Please follow the rule "<<endl;
        exit(1);
    }else{
        
        for (i = 1; i <= n; i++)
        {
            numOfCheck =i;
            cout<<"\nCheck "<<i<<endl;
            cout<<"Please enter the amount of Check"<<endl;
            cin>>tempAmt;
            
            dollar=trunc(tempAmt);
            cents=round((tempAmt-dollar)*100);
            amtOfCheck=Money(dollar, cents);
            
            cout<<"Please enter if you want to cash out the check"<<i<<"(Yes: 1, No:2) "<<endl;
            cin>>yesOrNot;
            
            if(yesOrNot==1){
                cashed =true;
            }else{
                cashed = false;
            }
            
            checkAccount[i] = Check(numOfCheck, amtOfCheck, cashed);
            
        }
        
    }
    
    //Deposit Money
    cout << "\nDo you want to deposit money? (Yes: 1, No: 2) ";
    cin>>yesOrNot;
    
    vector<Money> arrOfDeposit;
    while(yesOrNot==1){
        cout << "\nHow much do you want to deposit today? ";
        cin>>tempAmt;
        
        dollar=trunc(tempAmt);
        cents=round((tempAmt-dollar)*100);
        Money amtOfDeposit(dollar, cents);
        
        arrOfDeposit.push_back(amtOfDeposit);
        
        cout << "\nDo you want to deposit money again? (Yes: 1, No: 2) ";
        cin>>yesOrNot;
        
    }
    
    
    
    //cachedCheckTotal - Money
    cashedCheckTotal = cashedChecksTotal(checkAccount, n);
    notCashedCheckTotal =notCashedChecksTotal(checkAccount, n);
    
    //sumOfDepositTotal - Money
    for(i=0; i<arrOfDeposit.size(); i++){
        sumOfDepositTotal = add(sumOfDepositTotal,arrOfDeposit[i]);
    }
    
    //balance - Double
    currentBalance = originalBalance.get_value()+sumOfDepositTotal.get_value() - cashedCheckTotal.get_value();
    customerExpectedBalance = originalBalance.get_value()+sumOfDepositTotal.get_value() - cashedCheckTotal.get_value() - notCashedCheckTotal.get_value();
    
    cout<<"\nThe total of the checks cashed: "<<cashedCheckTotal.get_value();
    cout<<"\nThe total of the deposits: "<<sumOfDepositTotal.get_value();
    
    cout<<"\nThe checks cashed since the last time you balanced your checkbook: "<<endl;
    print_CashedChecks(checkAccount, n);
    
    cout<<"\nThe checks still not cashed: "<<endl;
    print_notCashedChecks(checkAccount, n);
    
    cout<<"\nYour current bank balance is "<<currentBalance<<"(Difference with your expected ammount: "<<currentBalance-customerExpectedBalance<<")"<<endl;

    
    return 0;
}

/*
 
 cout<<endl;
 cout<<"\nPlease enter your expected current balance: ";
 cin>>tempAmt;
 
 if(currentBalance==tempAmt){
 cout<<"\nYes it is correct."<<"\n"<<"Your current balance is "<<currentBalance<<endl;
 }else{
 cout<<"\nSorry it is not correct."<<"\n"<<"Your current balance is "<<currentBalance<<"(Difference with your expected ammount: "<<currentBalance-tempAmt<<")"<<endl;
 
 */
/*
 
 CH12 #7: Write a checkbook balancing program.
 The program will read in, from the console, the following for all checks that were not cashed as of the last time you balanced your checkbook:
 
 the number of each check (int),
 the amount of the check (double),
 and whether or not it has been cashed (1 or 0, boolean in the array).
 
 Use an array with the class as the type. The class should be a class for a check.
 There should be three member variables to record the
 1.check number,
 2.the check amount,
 3.whether or not the check was cashed.
 
 The class for a check will have a member variable of type Money (as defined on page 662 in the book; Display 11.9) to record the check amount.
 So, you will have a class used within a class.
 
 
 
 The class for a check should have accessor and mutator functions as
 well as
 constructors and functions for both input and output of a check.
 
 
 In addition to the checks, the program also reads all the deposits (from the console; cin),
 the old and the new account balance (read this in from the user at the console; cin).
 You may want another array to hold the deposits.
 The new account balance should be the old balance plus all deposits, minus all checks that have been cashed.
 
 The program outputs
 the total of the checks cashed,
 the total of the deposits,
 what the new balance should be,
 and how much this figure differs from what the bank says the new balance is.
 
 It also outputs two lists of checks:
 the checks cashed since the last time you balanced your checkbook and
 the checks still not cashed.
 Display both lists of checks in sorted order from lowest to highest check number.
 
 
 --------------
 Just to maybe offer slightly more detail: your homework should have two separate classes defined: Check and Money. There is an example of the Money class in the textbook that it is suggested we use (I ended up writing my own shorter version of Money, but I think other students are just copying the the textbook class directly.)
 
 The Money class represents Money objects. The Money class should be able to read in money data in the format "dd.dd", parse the input, and store it as a Money object, as the textbook example shows. The Check class, a separate class, makes use of the Money class. Specifically, Checks represent the amount of money they are for using the Money class. So while your check number is stored as an int type and your was cashed value is stored as a bool type, your check amount - the money it is valued for - is stored as a Money type. The Money type that you yourself define.
 
 So in other words, whenever you create a Check, because the Check stores a Money object, you also implicitly create a Money object  inside the Check object. When you want to find out how much money the check contains, you access the Check's Money object to get at the amount, etc.
 
 */





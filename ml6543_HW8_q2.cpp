//
//  main.cpp
//  HW8_question2
//
//  Created by Mina on 9/2/18.
//  Copyright © 2018 Mina. All rights reserved.
//

#include <iostream>
using namespace std;

bool isPalindrome(string str);


int main() {
    
    string userInput;

    cout<<"Please enter a word: ";
    getline(cin, userInput);
    
    if(isPalindrome(userInput)){
        cout<<userInput<<" is a palindrome"<<endl;
    }else{
        cout<<userInput<<" is NOT a palindrome"<<endl;

    }
    
    return 0;
}

bool isPalindrome(string str){
    
    string reverseWord;
    for(int i=(str.length()-1); i>=0; i--){
        reverseWord += str[i];
    }
    
    if(reverseWord == str){
        return true;
    }else{
        return false;
    }
    
}

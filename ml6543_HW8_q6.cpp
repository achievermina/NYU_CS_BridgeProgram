//
//  main.cpp
//  HW8_question6
//
//  Created by Mina on 9/2/18.
//  Copyright © 2018 Mina. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

bool checkHasOnlyNumbers(int input);


int main() {
    string line;
    int firstnumber =0, secondnumber=0;
    bool numberOrNot;
    cout<<"Please enter a line of text:"<<endl;
    getline(cin,line);
    
    const char* arr = line.c_str();
    
    
    for(int i =0; i<=line.length(); i++){
        if((arr[i]==' ')|| (i==line.length())){
            secondnumber = i;
            
            
            for(int j=firstnumber; j<=secondnumber; j++){
                
                numberOrNot =checkHasOnlyNumbers((int) arr[j]);
                if(numberOrNot==true){
                    continue;
                }else{
                    if(j==secondnumber){
                        string inputX = string((secondnumber-firstnumber), 'x');
                        line.replace(firstnumber, (secondnumber-firstnumber), inputX);
                        
                        
                    }else{
                        break;
                    }
                }
                
            }
            
            
            firstnumber=secondnumber+1;
            
        }
        
    }
    
    cout<<line<<endl;
    
    
    return 0;
}



bool checkHasOnlyNumbers(int input){
    
    return (input<=57 && input>=48);
}

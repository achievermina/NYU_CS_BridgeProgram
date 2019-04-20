//
//  main.cpp
//  HW8_question5
//
//  Created by Mina on 9/2/18.
//  Copyright © 2018 Mina. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstname, middlename, lastname;
    char initial;
    
    cout<<"Print your first name, middle name or initial, and the last name"<<endl;
    cin>>firstname>>middlename>>lastname;
    
    initial = middlename[0];
    cout<<lastname<<", "<<firstname<<" "<<initial<<"."<<endl;
    
    
    return 0;
}

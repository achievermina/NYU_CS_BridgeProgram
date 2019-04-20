//
//  main.cpp
//  HW11_question1
//
//  Created by Mina on 9/23/18.
//  Copyright © 2018 Mina. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);

int main() {
    cout<<"(a)"<<endl;
    printTriangle(4);
    cout<<"--------------------"<<endl;
    cout<<"(b)"<<endl;
    printOpositeTriangles(4);
    cout<<"--------------------"<<endl;
    cout<<"(c)"<<endl;
    printRuler(3);
    
    return 0;
}

void printTriangle(int n){
    if(n==1){
        cout<<string(1,'*')<<endl;
    }else{
        printTriangle(n-1);
        cout<<string(n,'*')<<endl;
    }
}

void printOpositeTriangles(int n){
    if(n==1){
        cout<<string(1,'*')<<endl;
        cout<<string(1,'*')<<endl;
    }else{
        cout<<string(n,'*')<<endl;
        printOpositeTriangles(n-1);
        cout<<string(n,'*')<<endl;
    }
}

void printRuler(int n){

    
    if(n==1){
        cout<<string(1,'-')<<endl;
    }else{
            printRuler(n-1);
            cout<<string(n, '-')<<endl;
            printRuler(n-1);

    }
}

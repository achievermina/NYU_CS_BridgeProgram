//
//  main.cpp
//  HW8_question1
//
//  Created by Mina on 9/2/18.
//  Copyright © 2018 Mina. All rights reserved.
//

#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);


int main() {
    int cuurentNumber, minimunNumber;
    int array1 [20];
    
    cout<<"Please enter 20 integers separated by a space:"<<endl;
    
    for(int i=0; i<20; i++){
        cin>>cuurentNumber;
        array1[i]=cuurentNumber;
    }
    
    minimunNumber =minInArray(array1, 20);
    cout<<"The minimum value is "<<minimunNumber<<", and it is located in the following indices: ";
    
    for(int i=0; i<20; i++){
        if(array1[i]==minimunNumber){
            cout<<i+1<<" ";
        }
    }

    cout<<endl;
    return 0;
}


int minInArray(int arr[], int arrSize){
    int min=INT_MAX;
    
    for(int i=0; i<arrSize; i++){
        if(arr[i]<=min){
            min=arr[i];
        }
    }
    
    return min;
    
}

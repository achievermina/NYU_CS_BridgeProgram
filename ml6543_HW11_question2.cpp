//
//  main.cpp
//  HW11_question2
//
//  Created by Mina on 9/23/18.
//  Copyright © 2018 Mina. All rights reserved.
//
/*
 
 Give a recursive implement to the following functions:
 a. int sumOfSquares(int arr[], int arrSize)
 This function is given arr, an array of integers, and its logical size, arrSize. When called,
 it returns the sum of the squares of each of the values in arr.

 
 b. bool isSorted(int arr[], int arrSize)
 This function is given arr, an array of integers, and its logical size, arrSize. When called,
 should return true if the elements in arr are sorted in an ascending order, or false if they are not
 
 */

#include <iostream>
#include <cmath>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int arr[4] = { 2, -1, 3, 10};
    int arr2[4] ={3, 6, 5,7 };
    int arrSize =4;
    
    cout<<"(a)"<<endl<<sumOfSquares(arr, arrSize)<<endl;
    cout<<"(b)"<<endl;
    if(isSorted(arr2, arrSize)==true){
        cout<<"Elements in arr are sorted in an ascending order"<<endl;
    }else{
        cout<<"Elements in arr are NOT sorted in an ascending order"<<endl;
    }

    return 0;
}

int sumOfSquares(int arr[], int arrSize){
    int resSumOfSquares;
    
    if(arrSize==1){
        return pow(arr[0],2);
    }else{
        resSumOfSquares = sumOfSquares(arr, arrSize-1);
        resSumOfSquares += pow(arr[arrSize-1],2);
        return resSumOfSquares;
 
    }
}

bool isSorted(int arr[], int arrSize){
    
    if(arrSize==1){
        return true;
    }else{
        if(isSorted(arr, arrSize-1)==true){
            return (arr[arrSize-2]<=arr[arrSize-1]);
        }else{
            return false;
        }
    }
}


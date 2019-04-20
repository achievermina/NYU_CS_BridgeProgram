//
//  main.cpp
//  HW11_question4
//
//  Created by Mina on 9/25/18.
//  Copyright © 2018 Mina. All rights reserved.
//

#include <iostream>
using namespace std;

int jumpCost(int arr[], int arrSize);
int jumpLowerCost(int arr[], int arrSize);

int main() {
    int arr[6]={0,3,80,6,57,10};
    int n=6, cost;
    
    cost = jumpLowerCost(arr, n);
    cout<<cost<<endl;
    
    return 0;
}

int jumpLowerCost(int arr[], int arrSize){
    int cost1, cost2;
    
    cost1 = jumpCost(arr+1, arrSize-1);
    cost2 = jumpCost(arr, arrSize);
    
    if(cost1>=cost2){
        return cost2;
    }else{
        return cost1;
    }
}



int jumpCost(int arr[], int arrSize){
    int finalcost=0;
    
    if(arrSize==1){
        finalcost += arr[0];
        return finalcost;
    }else{
        if(arrSize==2){
            finalcost = arr[0]+jumpCost(arr+1, arrSize-1);
        }else{
            finalcost = arr[0]+jumpCost(arr+2, arrSize-2);
        }
       return finalcost;
    }
}

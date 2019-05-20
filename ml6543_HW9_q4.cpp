//
//  main.cpp
//  HW9_question4
//
//  Created by Mina on 9/12/18.
//  Copyright © 2018 Mina. All rights reserved.
//

#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    int arrSize=6;
    int arr[6]={5, 2, 11, 7, 6, 4};
    
    oddsKeepEvensFlip(arr, arrSize);
    
    printArray(arr, arrSize);
    
    
    return 0;
}

void printArray(int arr[], int arrSize){ int i;
    for (i = 0; i < arrSize; i++) { cout<<arr[i]<<' ';
    }
    cout<<endl; }


void oddsKeepEvensFlip(int arr[], int arrSize){
    int evenarr[arrSize], oddarr[arrSize];
    int j=0, k=0, n=0;
    
    //get each digit
    for(int i=0; i<arrSize; i++){
        if(arr[i]%2==0){
            evenarr[j]=arr[i];
            j++;
        }else{
            oddarr[k]=arr[i];
            k++;
        }
    }
    
    //redefine arr
    for(int i=0; i<k; i++){
        arr[i]=oddarr[n];
        n++;
    }
    
    for(int i=k; i<arrSize; i++){
        arr[i]=evenarr[j-1];
        j--;
    }
}

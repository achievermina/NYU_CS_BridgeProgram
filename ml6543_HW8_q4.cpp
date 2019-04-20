
#include <iostream>
#include <cstdlib>
using namespace std;

void printArray(int arr[], int arrSize);

const int psw = 91076;

int main() {
    int userinput;
    int psw_digit=0, userinput_digit=0;
    
    int array[10];
    bool check=true;
    
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int number =(rand() % 3) + 1;
        //int number =rand() % 10;
        array[i] = number;
        
    }
    
    
    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "NUM: ";
    printArray(array, 10);
    
    cout << endl;
    cin >> userinput;
    
    int psw_check= psw, userinput_check = userinput;
    
    while (check && psw_check>0) {
        
        
        psw_digit = psw_check % 10;
        userinput_digit = userinput_check % 10;
        
        if (array[psw_digit] == userinput_digit){
            check=true;
        }else{
            check=false;
            cout<<"Your PIN is not correct"<<endl;
        }
        psw_check = psw_check / 10;
        userinput_check =userinput_check / 10;
    }
    
    if(check){
        cout<<"Your PIN is correct"<<endl;
        
    }
    
    
    
    return 0;
}


void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    
}


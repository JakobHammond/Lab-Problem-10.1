//
//  main.cpp
//  p10-4.2
//
//  Created by Jakob Hammond on 11/2/23.
//

#include <iostream>
using namespace std;

bool isCardValid(int digits[], int size);
bool isNumeric(string s);
bool isCorrectLength(string s);
int main(void){
    int digits[16];
    int size = 16;
    int number;
    string numString;
    
    
    while(true){
        cout << "Enter 16-digit credit card # or Q to quit: ";
        
  
        cin >> numString;
        if(numString == "Q") break;
        
        if(isNumeric(numString)){
            if(isCorrectLength(numString)){
                for(int i = 0; i <= size; i++){
                    string first = numString.substr(numString.length() - i);
                    digits[i] = first.front() - 48;
                    
                }
                
            }
            else{
                cout << "Error - card number must contain 16 digits." << endl;
                continue;
            }
        }
        else{
            cout << "Error - card number must contain only digits." << endl;
            continue;
        }
        
        
        
       // for(int i = 0; i < size; i++){
       //     digits[size - i] = number % 10;
       //     number /= 10;
       // }
        
        if(isCardValid(digits, size)) cout << "Card is valid." << endl;
        else cout << "Card is not valid." << endl;
    
    }
    return 1;
}


bool isCardValid(int digits[], int size){
    int firstSum = 0;
    int secondSum = 0;
    for(int i = size - 1; i > 0; i -= 2){
        firstSum += digits[i];
    }
    for(int i = size; i > 0; i -= 2){
        int temp = digits[i] * 2;
        secondSum += temp / 10;
        secondSum += temp % 10;
    }
    if((firstSum + secondSum) % 10 == 0) return true;
    else return false;
}

bool isNumeric(string s){
    for(int i = 1; i < s.length(); i++){
        string first;
        first = s.substr(s.length() - i);
        if(first.front() <= 47 || first.front() >= 58) return false;
    }
    return true;
}

bool isCorrectLength(string s){
    if(s.length() == 16) return true;
    else return false;
}

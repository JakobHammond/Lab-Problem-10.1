//
//  main.cpp
//  p10-1
//
//  Created by Jakob Hammond on 11/2/23.
//

#include <iostream>
using namespace std;

int count_letters(string str);
int main(void){
    
    cout << count_letters("I don't give a Holstein for programmers that can only spell a variable one way. (Dr. Stephany)") << endl;
}

int count_letters(string str){
    int letters = 0;
    for(int i = 0; i <= str.length(); i++){
        string first;
        first = str.substr(str.length() - i);
        if(first.front() <= 57);
        else if((first.front() <= 90 && first.front() >= 49) || (first.front() <= 122 && first.front() >= 81)){
            letters++;
        }
    }
    return letters;
}

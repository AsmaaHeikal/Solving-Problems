//Question 0-sheet 1-Assignment 1:
#include <iostream>
#include<string>
using namespace std;
string WHITESPACE = " \n\r\t\f\v";

int main(){
    string sentence;
    string new_sentence;
    int count_spaces = 0;
    cout<<"Please enter your sentence: ";
    getline(cin,sentence);
    //Line 14 skips the space if it's the first thing in the sentence
    int start = sentence.find_first_not_of(WHITESPACE);
    new_sentence += toupper(sentence[start]);
    for(int i = start+1; i < sentence.length(); i++){
        if(sentence[i] == ' ') {
            count_spaces++;
            if(count_spaces == 1)
                new_sentence+=' ';
        } else
            count_spaces=0;
        if(sentence[i] == ',' || sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?'){
            if(sentence[i-1] == ' '){
                new_sentence[new_sentence.length()-1] = sentence[i];
            } else
                new_sentence+=sentence[i];
        }
        else if(isupper(sentence[i])){
            new_sentence+=tolower(sentence[i]);
        }
        else if(islower(sentence[i]))
            new_sentence+=sentence[i];
        else if(sentence[i]>='0' && sentence[i]<='9')
            new_sentence+=sentence[i];
    }
    cout<<new_sentence;

}

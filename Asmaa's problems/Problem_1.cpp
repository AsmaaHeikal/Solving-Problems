#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter the sentence: ";
    getline(cin,s);
    istringstream ss(s);
    string word;
    while (ss >> word)
    {
        string str;
        string str1;
        bool found=false;
        if(ispunct(word[word.size()-1])){
            found=true;
            for(int i=0;i<word.size()-1;i++){
                str+=word[i];str1+=word[i];
            }
        }
        else {
            for(int i=0;i<word.size();i++){
                str+=word[i];str1+=word[i];
            }
        }
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(str=="he"){
            cout<<str1<<" or she";
            if(found)cout<<word[word.size()-1]<<' ';
            else cout<<' ';
        }
        else if(str=="him"){
            cout<<str1<<" or her";
            if(found)cout<<word[word.size()-1]<<' ';
            else cout<<' ';
        }
        else cout<<word<<' ';
    }
}



// Created by Rana Essam on 10/6/2022.
// purpose : phishing message investigator

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;


int main(){
    map <string, int> existWords;
    cout << "\twelcome to the Phishing Scanner!\n";
    ifstream file;
    file.open("DataBase.txt");
    vector <pair<string, string>> v;
    map <string, int>mp;
    string word, freq;
    while(!file.eof() ){
        file >>word;
        file >> freq;
        mp[word] = stoi(freq) ;
    }
    ifstream  msg;
    string str2 ;
    cout << "Please, enter the message's name:\n ";
    cin >> str2;
    str2 += ".txt";
    msg.open(str2);
    long long score = 0;
    while(! msg.eof()){
        string str;
        msg >> str;
        score += mp[str];
        if(mp[str] != 0){
            existWords[str] += mp[str];
        }
    }
   cout << "The score of this message = "<<  score << " point"<< endl;
    cout << "\n____________________________________________\n";
    for(const auto ptr : existWords){
        cout << "( "<< ptr.first <<  " ) "<< "its count = " << ptr.second/ mp[ptr.first] << " with score = " << ptr.second << endl;
    }
    msg.close();
    file.close();
}


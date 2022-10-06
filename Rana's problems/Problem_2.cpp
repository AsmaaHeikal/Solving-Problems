// Created by Rana Essam on 10/6/2022.
// purpose : split string to vector with given delimiter

#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string target, string delimiter);

int main(){
    vector <string> ans = split("do re mi fa so la ti do", " ");
    for(string str: ans){
        cout << str << " ";
    }
    cout << endl;
    ans = split("10,20,30", ",");
    for(string str: ans){
        cout << str << " ";
    }

}

vector<string> split(string target, string delimiter){
    vector <string> ans;
    target += delimiter;
    size_t l =0;
    size_t r = target.find(delimiter);
    while(r != string::npos){
        ans.push_back(target.substr(l, r-l));
        l= r+1;
        r = target.find(delimiter, r+1);
    }
    return ans;
}


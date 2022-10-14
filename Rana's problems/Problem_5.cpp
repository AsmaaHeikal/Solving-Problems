// Created by Rana Essam on 10/6/2022.
// purpose : Domino chain checker

#include <bits/stdc++.h>
using namespace std;

struct domino{
    int left, right;
};

vector<domino> chain;
map<int, bool>chck;

bool FormChain(vector <domino> dmns){
    //base case
    if(chain.size() == dmns.size()) return true;
    for(int i = 0 ; i < dmns.size() ; i++){
        if(chain.empty() || ((chain[chain.size()-1].right== dmns[i].left) && !(chck[i]))){
          //transition
            chain.push_back(dmns[i]);
            chck[i] = true;
            if(FormChain(dmns))
                return true;
            chain.pop_back();
            chck[i] = false;
        }
    }
    return false;
}

int main(){
    vector<domino> v(6);
    v[0] = {1, 3};
    v[1] = {3, 5};
    v[2] = {3, 7};
    v[3] = {2, 3};
    v[4] = {4, 2};
    v[5] = {5, 4};


    cout << FormChain(v) << endl;
    if(FormChain(v)){
        for(domino d: chain){
            cout << d.left << " | " << d.right << "  " ;
        }

    }
}

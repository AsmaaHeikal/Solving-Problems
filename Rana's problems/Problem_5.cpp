// Created by Rana Essam on 10/6/2022.
// purpose : Domino chain checker

#include <bits/stdc++.h>

using namespace std;

struct dominoT{
    int leftDots ;
    int rightDots;
    dominoT(){}
    dominoT(int leftDots, int rightDots){
        this-> leftDots = leftDots;
        this -> rightDots = rightDots;
    }
};
bool canAppend(dominoT currDominoes, dominoT leftDomino , dominoT rightDomino);
bool FormsDominoChain(vector<dominoT> & dominoes);

int main(){
        vector<dominoT> v(5);
    v[2] = {6,1};
    v[1] = {1, 4};
    v[0] = {2, 6};
    v[3] = {4, 4};
    v[4] = {4, 3};

    if(FormsDominoChain(v))
        cout << "yes" << endl;
    else if(!FormsDominoChain(v))
        cout << "No" << endl;

    vector<dominoT> v2(4);
    v[2] = {6,1};
   // v[1] = {1, 4};
    v[0] = {2, 6};
    v[3] = {4, 4};
    v[1] = {4, 3};

    if(FormsDominoChain(v2))
        cout << "yes" << endl;
    else if(!FormsDominoChain(v2))
        cout << "No" << endl;
}


bool canAppend(dominoT currDominoes, dominoT leftDomino , dominoT rightDomino){
    return (currDominoes.leftDots == rightDomino.rightDots || currDominoes.rightDots == leftDomino.leftDots);
}

bool FormsDominoChain(vector<dominoT> & dominoes){
    static deque<dominoT> ans;

    if(ans.size() == 0){
        ans.push_front(dominoes[0]);
        dominoes.erase(dominoes.begin());
        return FormsDominoChain(dominoes);
    }
    else if(dominoes.size() == 0){
        for(dominoT d: ans){
            cout  << d.leftDots << " | " <<d.rightDots<< "   ";
        }
        return true;
    }
    else {
        for(int i = 0 ; i < dominoes.size() ; i++){
            if(canAppend(dominoes[i], ans[0], ans[ans.size()-1])){
                if(dominoes[i].leftDots == ans[ans.size()-1].rightDots){
                    ans.push_back(dominoes[i]);
                    dominoes.erase(dominoes.begin()+i);
                    return FormsDominoChain(dominoes);
                }
                else{
                    ans.push_front(dominoes[i]);
                    dominoes.erase(dominoes.begin()+i);
                    return FormsDominoChain(dominoes);
                }
            }
        }
    }
    return false ;

}






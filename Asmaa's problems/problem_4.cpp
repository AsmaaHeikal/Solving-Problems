#include <bits/stdc++.h>

using namespace std;

class myBinary{
public:
    static void binaryPrint(int n){
        if(n>1)
            binaryPrint(n/2);
        cout<<n%2;
    }
    static void numbers(const string& prefix, int k){
        if(k==0){
            cout<<prefix<<'\n';
        }else{
            numbers(prefix+'0',k-1);
            numbers(prefix+'1',k-1);
        }
    }
};

int main() {
    myBinary::binaryPrint(5);
    cout<<'\n';
    myBinary::numbers(  "00101",2);
}

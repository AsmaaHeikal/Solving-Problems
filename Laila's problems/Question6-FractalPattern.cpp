#include<iostream>
using namespace std;
//function to print the asterisks:
void print(int n, int shift){
    string s = "";
    //number of shifts inputed
    for (int i = 0; i < shift; i++)
        s += "  ";
    //number of n inputed
    for (int i = 0; i < n; i++)
        s += "* ";
    cout << s << endl;
}
//8,0
void fractal_pattern(int n, int shift){
    //base case
    if(n == 1)
        print(n, shift);
    else if(n >= 2){
        fractal_pattern(n/2, shift);
        print(n, shift);
        fractal_pattern(n/2, shift + n/2);
    }
}
int main(){
    fractal_pattern(8, 0);
}

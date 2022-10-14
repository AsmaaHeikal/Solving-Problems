#include <bits/stdc++.h>

using namespace std;

int main() {
    fstream file1;
    fstream file2;
    string file1Name, file2Name;
    cout << "enter the name of the first file : ";
    cin >> file1Name;
    cout << "enter the name of the second file : ";
    cin >> file2Name;
    file1Name += ".txt";
    file2Name += ".txt";
    file1.open(file1Name,ios::in | ios::app);
    file2.open(file2Name,ios::in | ios::app);

    cout<<"You want to compare : 1-char by char  2- word by word   --->";
    int ans;cin>>ans;
    if(ans==1) {
        char c1, c2;
        int cnt1 = 0, cnt2 = 0;
        while (file1.get(c1)) {
            cnt1++;
        }
        while (file2.get(c2)) {
            cnt2++;
        }
        file1.close();
        file2.close();

        file1.open(file1Name, ios::in | ios::app);
        file2.open(file2Name, ios::in | ios::app);
        int nwLine1 = 0, nwLine2 = 0;
        bool found = false;
        while (file1.get(c1) && file2.get(c2)) {
            if (c1 == '\n')nwLine1++;
            if (c2 == '\n')nwLine2++;
            if (c1 != c2) {
                found = true;
                break;
            }
        }
        file1.close();
        file2.close();

        file1.open(file1Name, ios::in | ios::app);
        file2.open(file2Name, ios::in | ios::app);

        if (found) {
            cout << min(nwLine1, nwLine2) + 1 << '\n';
            int num_line = min(nwLine1, nwLine2) + 1;
            int counter = 0;
            string s;
            while (getline((nwLine1 < nwLine2 ? file1 : file2), s)) {
                counter++;
                if (counter == num_line)
                    cout << s;
            }
        } else {
            if (cnt2 == cnt1) {
                cout << "IDENTICAL\n";
            } else {
                cout << min(nwLine2, nwLine1) + 2 << '\n';
                int num_line = min(nwLine1, nwLine2) + 2;
                int counter = 0;
                string s;
                while (getline((cnt1 > cnt2 ? file1 : file2), s)) {
                    counter++;
                    if (counter == num_line)
                        cout << s;
                }
            }
        }
    }
    else if(ans==2){
        string w1,w2;
        int cnt1 = 0, cnt2 = 0;
        while (file1>>w1) {
            cnt1++;
        }
        while (file2>>w2) {
            cnt2++;
        }
        file1.close();
        file2.close();

        file1.open(file1Name, ios::in | ios::app);
        file2.open(file2Name, ios::in | ios::app);
        int nwLine1 = 0, nwLine2 = 0;
        bool found = false;
        char c1,c2;
        while (file1>>w1 && file2>>w2) {
            c1=file1.get();
            c2=file2.get();
            if (c1 == '\n')nwLine1++;
            if (c2 == '\n')nwLine2++;
            if (w1 != w2) {
                cout<<(nwLine1<nwLine2?w1:w2)<<'\n';
                found = true;
                break;
            }
        }
        file1.close();
        file2.close();

        file1.open(file1Name, ios::in | ios::app);
        file2.open(file2Name, ios::in | ios::app);

        if (found) {
            cout << min(nwLine1, nwLine2) + 1 << '\n';
            int num_line = min(nwLine1, nwLine2) + 1;
            int counter = 0;
            string s;
            while (getline((nwLine1 < nwLine2 ? file1 : file2), s)) {
                counter++;
                if (counter == num_line)
                    cout << s;
            }
        } else {
            if (cnt2 == cnt1) {
                cout << "IDENTICAL\n";
            } else {
                cout << min(nwLine2, nwLine1) + 2 << '\n';
                int num_line = min(nwLine1, nwLine2) + 2;
                int counter = 0;
                string s;
                while (getline((cnt1 > cnt2 ? file1 : file2), s)) {
                    if(!s.empty())counter++;
                    if (counter == num_line)
                        cout << s;
                }
            }
        }
    }
}

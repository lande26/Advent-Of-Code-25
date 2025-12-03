#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "Cannot open input file" << endl;
        return 1;
    }
    int idx = 50; int cnt = 0;
    string s;
    while(getline(file, s)) {
        char direc = s[0];
        int dist = stoi(s.substr(1));

        for(int i =0; i<dist; i++) {
            if(direc=='L') idx = (idx-1)%100;
            else if(direc=='R') idx = (idx+1)%100;

            if(idx<0) idx+=100;
            if(idx==0) cnt++;
        }   
    }
    cout << "Password: " << cnt << endl; return 0;
    // password : 6475
}
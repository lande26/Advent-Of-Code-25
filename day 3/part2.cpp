#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream file("input.txt");
    if (!file) {
        cerr << "Cannot open input file" << endl;
        return 1;
    }
    string s; int sum = 0;
    while(getline(file, s)){
        int mx = 0;
        for(int i = 0; i<s.length(); i++){
            for(int j=i+1; j<s.length(); j++){
                int l = (s[i]-'0')*10+(s[j]-'0');
                mx = max(mx,l);
            }
        }
        sum += mx;
    }
    cout << sum << endl;
    return 0;
}
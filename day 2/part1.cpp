#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll pow10(int n) {
    ll res = 1;
    for(int i = 0; i<n; i++) res*=10;
    return res;
}
int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "Cannot open input file" << endl;
        return 1;
    }
    string s;
    getline(file, s);
    stringstream ss(s);
    string r; ll sum=0;
    while(getline(ss, r, ',')) {
        if(r.empty()) continue;
        size_t idx = r.find('-');
        ll a = stoll(r.substr(0, idx));
        ll b = stoll(r.substr(idx + 1));
        ll mx = to_string(b).size()/2;
        for(int i = 1; i<=mx; i++){
            ll den = pow10(i)+1;
            ll pa = (a+den-1)/den;
            ll pb = b/den;
            pa = max(pa, pow10(i-1));
            pb = min(pb, pow10(i)-1);
            if(pa>pb) continue;
            for(ll j = pa; j<=pb; j++) sum += j*den;
        }
    }
    cout << sum << endl; //20223751480
    return 0;
}
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
        unordered_set<ll> vis;
        ll size = to_string(b).size();
        for(int i = 1; i<=9; i++){
            ll den = pow10(i)-1;
            for(ll k=2; k<=18; k++){
                ll val = i*k;
                if(val>size) break;
                ll ten = pow10(val);
                ll s = (ten-1)/den;
                ll pa = (a+s-1)/s;
                ll pb = b/s;
                ll pmin = pow10(i-1);
                ll pmax = pow10(i)-1;
                if(pa<pmin) pa = pmin;
                if(pb>pmax) pb = pmax;
                if(pa>pb) continue;
                for(ll j = pa; j<=pb; j++){
                    ll v = j * s;
                    if (vis.insert(v).second) {
                        sum += v;
                    }
                }
            }
        }
    }
    cout << sum << endl; 
    return 0;
}
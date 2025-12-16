#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define pii pair<int,int>

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if(!file){
        cerr<<"Cannot open input file"<<endl;
        return 1;
    }

    vector<pair<ll,ll>> ranges;
    vector<ll> ids;
    string s;
    bool sec=false;

    while(getline(file,s)){
        if(!s.empty() && s.back()=='\r') s.pop_back();  // 🔥 FIX

        if(s.empty()){
            sec=true;
            continue;
        }

        if(!sec){
            int p=s.find('-');
            ll l=stoll(s.substr(0,p));
            ll r=stoll(s.substr(p+1));
            ranges.pb({l,r});
        }else{
            ids.pb(stoll(s));
        }
    }

    ll p1=0;
    for(ll x:ids){
        for(auto &r:ranges){
            if(x>=r.ff && x<=r.ss){
                p1++;
                break;
            }
        }
    }

    cout<<"Part 1:"<<p1<<endl;

    sort(all(ranges));
    vector<pair<ll,ll>> m;
    for(auto &r:ranges){
        if(m.empty() || r.ff>m.back().ss+1)
            m.pb(r);
        else
            m.back().ss=max(m.back().ss,r.ss);
    }

    ll p2=0;
    for(auto &r:m) p2+=r.ss-r.ff+1;

    cout<<"Part 2: "<<p2<<endl;
    return 0;
}

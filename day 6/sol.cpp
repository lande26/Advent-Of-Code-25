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

    vector<string> lines;
    string s;
    while(getline(file,s)){
        if(!s.empty() && s.back()=='\r') s.pop_back();
        lines.pb(s);
    }

    while(!lines.empty() && lines.back().empty()) lines.pop_back();
    if(lines.empty()){
        cout<<"Part 1 - Grand total: 0"<<endl;
        cout<<"Part 2 - Grand total: 0"<<endl;
        return 0;
    }

    int h=lines.size()-1;
    int w=0;
    for(auto &x:lines) w=max(w,(int)x.size());
    for(auto &x:lines) x+=string(w-x.size(),' ');

    string ops=lines.back();
    vector<string> nums(lines.begin(),lines.end()-1);

    vector<pair<vector<ll>,char>> probs;
    int st=-1;
    char op=0;

    for(int c=0;c<w;c++){
        bool allsp=true;
        for(auto &r:nums) if(r[c]!=' ') allsp=false;
        bool hasop=(ops[c]=='+'||ops[c]=='*');

        if(!allsp||hasop){
            if(st==-1){
                st=c;
                op=ops[c];
            }
        }else{
            if(st!=-1){
                vector<ll> v;
                for(auto &r:nums){
                    string sub=r.substr(st,c-st);
                    stringstream ss(sub);
                    string t;
                    while(ss>>t) v.pb(stoll(t));
                }
                if(!v.empty()&&op) probs.pb({v,op});
                st=-1; op=0;
            }
        }
    }

    if(st!=-1){
        vector<ll> v;
        for(auto &r:nums){
            string sub=r.substr(st);
            stringstream ss(sub);
            string t;
            while(ss>>t) v.pb(stoll(t));
        }
        if(!v.empty()&&op) probs.pb({v,op});
    }

    ll p1=0;
    for(auto &pr:probs){
        if(pr.ss=='+'){
            ll s=0;
            for(ll x:pr.ff) s+=x;
            p1+=s;
        }else{
            ll m=1;
            for(ll x:pr.ff) m*=x;
            p1+=m;
        }
    }

    cout<<"Part 1 - Grand total: "<<p1<<endl;

    vector<pair<vector<ll>,char>> probs2;
    int ed=w-1;

    while(ed>=0){
        while(ed>=0){
            bool allsp=true;
            for(auto &r:nums) if(r[ed]!=' ') allsp=false;
            if(ops[ed]==' '&&allsp) ed--;
            else break;
        }
        if(ed<0) break;

        int l=ed;
        while(l>=0){
            bool has=false;
            for(auto &r:nums) if(r[l]!=' ') has=true;
            bool hasop=(ops[l]=='+'||ops[l]=='*');
            if(has||hasop) l--;
            else break;
        }
        l++;

        char cop=ops[l];
        vector<ll> v;
        for(int c=ed;c>=l;c--){
            string t;
            for(auto &r:nums) if(r[c]!=' ') t+=r[c];
            if(!t.empty()) v.pb(stoll(t));
        }
        if(!v.empty()&&cop) probs2.pb({v,cop});
        ed=l-1;
    }

    ll p2=0;
    for(auto &pr:probs2){
        if(pr.ss=='+'){
            ll s=0;
            for(ll x:pr.ff) s+=x;
            p2+=s;
        }else{
            ll m=1;
            for(ll x:pr.ff) m*=x;
            p2+=m;
        }
    }

    cout<<"Part 2 - Grand total: "<<p2<<endl;
    return 0;
}

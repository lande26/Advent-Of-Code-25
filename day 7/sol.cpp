#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define ll long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    vector<string> g;
    string s;
    while(getline(file,s)){
        if(!s.empty() && s.back()=='\r') s.pop_back();
        if(!s.empty()) g.pb(s);
    }

    int n=g.size(), m=g[0].size();
    int sr=0, sc=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='S') sr=i, sc=j;

    vector<int> beams={sc};
    ll splits=0;

    for(int r=sr+1;r<n && !beams.empty();r++){
        vector<int> nb;
        for(int c:beams){
            if(g[r][c]=='^'){
                splits++;
                if(c>0) nb.pb(c-1);
                if(c+1<m) nb.pb(c+1);
            }else{
                nb.pb(c);
            }
        }
        sort(all(nb));
        nb.erase(unique(all(nb)),nb.end());
        beams=nb;
    }

    cout<<"Part 1 - Tachyon beam splits: "<<splits<<endl;

    vector<ll> cur(m,0), nxt(m,0);
    cur[sc]=1;

    for(int r=sr;r<n-1;r++){
        fill(all(nxt),0);
        for(int c=0;c<m;c++){
            if(cur[c]==0) continue;
            if(g[r][c]=='^'){
                if(c>0) nxt[c-1]+=cur[c];
                if(c+1<m) nxt[c+1]+=cur[c];
            }else{
                nxt[c]+=cur[c];
            }
        }
        cur=nxt;
    }

    ll timelines=0;
    for(ll x:cur) timelines+=x;

    cout<<"Part 2 - Timelines: "<<timelines<<endl;
    return 0;
}

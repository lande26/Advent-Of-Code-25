#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if(!file){
        cerr<<"Cannot open input file"<<endl;
        return 1;
    }

    vector<string> g;
    string s;
    while(getline(file,s)){
        if(!s.empty()) g.push_back(s);
    }

    int n=g.size(), m=g[0].size();
    vector<pair<int,int>> d={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    int p1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='@'){
                int c=0;
                for(auto &x:d){
                    int ni=i+x.first, nj=j+x.second;
                    if(ni>=0 && ni<n && nj>=0 && nj<m && g[ni][nj]=='@') c++;
                }
                if(c<4) p1++;
            }
        }
    }

    cout<<"Part 1 - Number of accessible rolls of paper: "<<p1<<endl;

    int p2=0;
    bool ok=true;
    while(ok){
        ok=false;
        vector<pair<int,int>> rem;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]=='@'){
                    int c=0;
                    for(auto &x:d){
                        int ni=i+x.first, nj=j+x.second;
                        if(ni>=0 && ni<n && nj>=0 && nj<m && g[ni][nj]=='@') c++;
                    }
                    if(c<4) rem.push_back({i,j});
                }
            }
        }
        for(auto &x:rem){
            g[x.first][x.second]='.';
            p2++;
            ok=true;
        }
    }

    cout<<"Part 2 - Total rolls of paper removed: "<<p2<<endl;
    return 0;
}

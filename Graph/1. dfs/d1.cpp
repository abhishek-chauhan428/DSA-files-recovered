#include <bits/stdc++.h>
using namespace std;


void dfs(int node){
    vis[node] = 1;

    for(auto x: g[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int n, m;   // n nodes and m edges
vector<vector<int>> g;     // this is adjecency matrix 
vector<int> vis;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    g.resize(n+1);

    for(int i=0; i<m; i++){     // we have all the edges given
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        
        // if undirected 
        g[b].push_back(a);
    }
    vis.assign(n+1, 0);

    dfs(1);
}


/*

everythign that is reachable from graph will be touched exactly once - quality of dfs
*/
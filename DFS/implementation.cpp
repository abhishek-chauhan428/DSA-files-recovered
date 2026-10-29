#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node){
    vis[node] = 1;

    for(auto x : g[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    g.resize(n + 1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        // if undirected
        g[b].push_back(a);
    }

    vis.assign(n + 1, 0);

    dfs(1);
}

/*
everythign that is reachable from graph will be touched exactly once - quality of dfs
*/

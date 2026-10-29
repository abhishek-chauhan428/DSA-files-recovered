
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> dist;

void bfs(int sc_node){
    queue<int> q;

    vis[sc_node] = 1;
    dist[sc_node] = 0;
    q.push(sc_node);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto v : g[node]){
            if(!vis[v]){
                vis[v] = 1;
                dist[v] = dist[node] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> n >> m;

    g.resize(n + 1);
    vis.resize(n + 1, 0);
    dist.resize(n + 1, -1);

    // Undirected graph
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int source;
    cin >> source;

    bfs(source);

    cout << "Distance from source:\n";
    for(int i = 1; i <= n; i++){
        cout << "Node " << i << " : " << dist[i] << '\n';
    }

    return 0;
}
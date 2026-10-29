#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> g;
int n, a, b;
vector<int> arr;
vector<int> dist, vis;

void dijkstra(int node){
    priority_queue<pair<int,int>> pq;
    pq.push({0, node});

    dist[node] = 0;

    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();

        if(vis[v]) continue;

        d = -d;
        vis[v] = 1;

        for(auto x : g[v]){
            if(dist[x.first] > d + x.second){
                dist[x.first] = d + x.second;
                pq.push({-dist[x.first], x.first});
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    arr.resize(n);

    map<int,int> mp;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]] = 0;
    }

    int num_size = mp.size();

    int node_num = n;

    for(auto &x : mp){
        x.second = node_num++;
    }

    cin >> a >> b;

    int st;
    cin >> st;

    int totalNodes = n + num_size;

    g.assign(totalNodes, vector<pair<int,int>>());
    dist.assign(totalNodes, 1e9);
    vis.assign(totalNodes, 0);

    for(int i = 0; i < n; i++){

        if(i != 0){
            g[i].push_back({i - 1, a});
        }

        if(i != n - 1){
            g[i].push_back({i + 1, a});
        }

        int virtualNode = mp[arr[i]];

        g[i].push_back({virtualNode, b});
        g[virtualNode].push_back({i, 0});
    }

    dijkstra(st);

    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }

    cout << '\n';

    return 0;
}
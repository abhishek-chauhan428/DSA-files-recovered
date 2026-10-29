#include <bits/stdc++.h>
using namespace std;

int n, m, a;
# define int  long long
vector<vector<pair<int,int>>> g;
vector<int> vis, dist;


void bfs(int a){
    priority_queue<pair<int,int>> pq;
    pq.push({-0, a});
    dist[a] = 0;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(vis[x.second])  continue;
        vis[x.second]    = 1;

        for(auto [w, ch]: g[x.second]){
            if(dist[ch]>dist[x.second]+w) {
                dist[ch] = dist[x.second]  + w;
                pq.push({-dist[ch], ch});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.assign(n+1, vector<pair<int,int>>());
    vis.assign(n+1, 0)  ;
    dist.assign(n+1, 1e18);
    
    for(int i=0; i<m; i++){ 
        int x, y, d;
        cin >> x >> y >> d;
        g[x].push_back({d, y})    ;
        g[y].push_back({d, x});
    }

    cin >> a;
    bfs(a);

    int ans = LLONG_MIN;
    for(int i=1; i<=n; i++){
        for(auto x: g[i]){
            int n1 = i, n2 = x.second, w =x.first;
            if(abs(dist[n1]-dist[n2])==w){
                ans = max(ans, min(dist[n1],dist[n2])+w);
            }
            else{
                ans = max(ans, ((dist[n1]+dist[n2]+w)/2));
            }
        }
    }

    cout << ans;

    return 0;
}
/*
Problem: Last Moment of Fire

You are given a connected undirected weighted graph.

Each edge (u, v, d) is a thread of length d.
Fire starts at node A at time 0 and spreads at 1 unit/sec.

Find T = the time when all threads are completely burned.
Print 10 * T.

Input:
4
4
1 2 2
2 3 4
3 4 3
1 4 7
1

Output:
80

Explanation:
Fire starts at node 1.

Shortest fire arrival times:
1 -> 0
2 -> 2
3 -> 6
4 -> 7

For edge (3,4) of length 3:
Both ends are burning, so they meet at:

    T = (6 + 7 + 3) / 2 = 8

Thus the last thread burns at T = 8.

Answer = 10 * 8 = 80.
*/
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
# define f first
# define s second
# define int long long


int n, m;
vector<vector<pii>> g;
vector<int> dist;
bool isNegCycle = false;

void bellmanFord(int node){
    dist[node] = 0;

    for(int i=1; i<=n-1; i++){

        for(int i=1; i<=n; i++){
            auto x = g[i];
            for(auto y: x){
                int p = i;
                int ch = y.f;
                int w = y.s;
                dist[ch] = min(dist[ch], dist[p]+w);
            }
        }
    }

    for(int i=1; i<=n; i++){
        auto x = g[i];
        for(auto y: x){
            int p = i, ch = y.f;
            int w = y.s;
            if(dist[ch]>dist[p]+w){
                isNegCycle = true;
            }
        }
    }

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.assign(n+1, vector<pii> ());

    dist.assign(n+1, 1e18)  ;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }


    bellmanFord(1);

    if(isNegCycle) cout << "YES";
    else cout<< "NO";

    return 0;
}

/* 


    NOTE: Bellman Ford wont work in undirected graph with an -ve edge as it forms an two node -ve cycle 

    Follow up:- print all node that are part of a negative cycle ??


┌──────────────────────────────┐
│ 1. Run n-1 iterations        │
│    Find shortest distances   │
└──────────────┬───────────────┘
               ↓
┌──────────────────────────────┐
│ 2. Run ONE extra iteration   │
│    Can anything improve?     │
└──────────────┬───────────────┘
               ↓
          YES / NO
           /    \
         NO      YES
         ↓        ↓
       DONE    Negative cycle
                  ↓
┌──────────────────────────────┐
│ 3. Move parent n times       │
│    → guaranteed inside cycle │
└──────────────┬───────────────┘
               ↓
┌──────────────────────────────┐
│ 4. Follow parent until       │
│    we return to x            │
└──────────────────────────────┘


*/

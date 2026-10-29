#include <bits/stdc++.h>
using namespace std;

# define int long long 

int n, m;
vector<vector<int>> g, dist;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    g.assign(n+1, vector<int>(n+1)), dist.assign(n+1, vector<int>(n+1, 1e18));

    for(int i=0; i<m; i++){
        int a, b, x;
        cin >> a >> b >> x;
        g[a][b] = x;
        g[b][a]  = x;
        dist[a][b] = x, dist[b][a] = x;
    }
    for(int i=1; i<=n; i++) dist[i][i]  = 0 ;
    
    for(int k=1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y;
        cout << dist[x][y] << "\n";
    }
    return 0;
}

/*
    Problem:
    You are given an undirected weighted graph with n vertices and m edges.

    Each edge is given as:
        a b w
    meaning there is an edge between a and b with weight w.

    You are also given q queries. Each query contains:
        x y

    For every query, find the minimum distance from vertex x to vertex y.

    If there is no path between x and y, print -1.
*/

/*
    Floyd-Warshall Approach:

    - Since we need the shortest distance between EVERY pair of vertices,
      we use the Floyd-Warshall algorithm.

    - Instead of an adjacency list, we use a 2D distance matrix:
      
          dist[i][j] = current shortest known distance from i to j.

    - Initially:
        1. dist[i][i] = 0
        2. If there is a direct edge i -> j with weight w,
           dist[i][j] = w
        3. If there is no direct edge, dist[i][j] = INF

    - For an undirected graph:
          dist[i][j] = w
          dist[j][i] = w

    Main Idea:
    ----------
    For every vertex k, we check whether using k as an intermediate
    vertex can give us a shorter path from i to j.

                i ---------> j
                 \           /
                  \         /
                   ---> k <---

    There are only two possibilities for the shortest path from i to j:

        1. It does NOT go through k:
              dist[i][j]

        2. It DOES go through k:
              dist[i][k] + dist[k][j]

    Therefore:

        dist[i][j] = min(dist[i][j],
                         dist[i][k] + dist[k][j])


    Why does this give the correct answer?
    ---------------------------------------
    We gradually allow more vertices to be used as intermediate vertices.

        k = 1  -> paths can use vertex 1 as an intermediate
        k = 2  -> paths can use vertices 1, 2
        k = 3  -> paths can use vertices 1, 2, 3
        ...
        k = n  -> all vertices can be intermediate vertices

    At every step, we compare:
    
        "keep the old shortest path"
    
    with
    
        "take a path from i -> k -> j"

    and keep whichever is smaller.

    Thus, after all n vertices have been considered as intermediate
    vertices, dist[i][j] contains the shortest possible path from
    i to j.

    Finally, a query (x, y) can be answered directly using:

        dist[x][y]

    because the matrix now contains the shortest distance between
    every pair of vertices.

    Complexity:
        Time  : O(n^3)
        Space : O(n^2)
*/
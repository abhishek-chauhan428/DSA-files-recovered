#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int, int>>> g;
vector<int> dis;

void BFS01(int sc) {
    deque<int> dq;

    for (int i = 1; i <= n; i++) {
        dis[i] = 1e9;
    }

    dis[sc] = 0;
    dq.push_back(sc);

    while (!dq.empty()) {
        int xx = dq.front();
        dq.pop_front();

        for (auto v : g[xx]) {
            int neigh = v.first;
            int weigh = v.second;

            if (dis[neigh] > dis[xx] + weigh) {
                dis[neigh] = dis[xx] + weigh;

                if (weigh == 0) {
                    dq.push_front(neigh);
                } else {
                    dq.push_back(neigh);
                }
            }
        }
    }
}

void solve() {
    int m;
    cin >> n >> m;

    g.resize(n + 1);
    dis.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    int sc;
    cin >> sc;

    BFS01(sc);

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}





/*
    0-1 BFS
    --------
    We are given a graph where every edge has a weight of either 0 or 1.

    Goal:
    Find the shortest distance from a given source node to every other node.

    Why not normal BFS?
    -------------------
    Normal BFS works when every edge has the same weight (usually 1).
    Here, edges can have weight 0 or 1, so normal BFS is not enough.

    Why 0-1 BFS?
    ------------
    We use a deque:
      - If an edge has weight 0 -> push the node to the FRONT.
      - If an edge has weight 1 -> push the node to the BACK.

    This keeps nodes with smaller current distances toward the front,
    allowing us to find shortest paths efficiently.

    Time Complexity:
        O(V + E)

    Space Complexity:
        O(V + E)
*/
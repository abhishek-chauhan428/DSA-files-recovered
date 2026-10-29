
/*
    ***My observation***
NOTE:- 1. Even cycles → can be bipartite.     2.Odd cycles → never bipartite.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> color;
bool is_bipartite = true;

void dfs(int node, int c) {
    vis[node] = 1;
    color[node] = c;

    for (auto x : g[node]) {
        if (!vis[x]) {
            dfs(x, 3 - c);          // opposite color
        }
        else {
            if (color[x] == color[node]) {
                is_bipartite = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    g.resize(n + 1);

    // Undirected graph
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vis.assign(n + 1, 0);
    color.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 1);      // start each component with color 1
        }
    }

    if (is_bipartite)
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is Not Bipartite\n";
}


/*
PROBLEM: Check if an Undirected Graph is Bipartite

Given n vertices and m undirected edges, determine whether the graph
can be colored using only 2 colors such that no two adjacent vertices
have the same color.

Example Input:
5 4
1 2
2 3
3 4
4 5

Graph:
1 --- 2 --- 3 --- 4 --- 5

Output:
Graph is Bipartite

Approach:
- Run DFS on every connected component.
- Color the current node 1 or 2.
- Give every neighbor the opposite color.
- If two adjacent nodes ever have the same color, the graph is not bipartite.

Time: O(n + m)
*/




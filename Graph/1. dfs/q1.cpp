#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> comp;

void dfs(int node, int id) {
    comp[node] = id;

    for (auto x : g[node]) {
        if (comp[x] == 0) {
            dfs(x, id);
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

    comp.assign(n + 1, 0);

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (comp[i] == 0) {
            cnt++;
            dfs(i, cnt);
        }
    }

    cout << "Number of connected components = " << cnt << "\n";

    for (int i = 1; i <= n; i++) {
        cout << "Vertex " << i << " belongs to component " << comp[i] << "\n";
    }
}



/*
PROBLEM: Connected Components (Undirected Graph)

Given n vertices and m edges, find:
1. The number of connected components.
2. The component ID of each vertex.

Example Input:
8 7
1 2
2 3
3 1
3 4
5 6
6 7
7 5

Graph:

      1
     / \
    2---3
         |
         4

    5---6
     \ /
      7

    8

Output:
Components = 3

Component 1: {1,2,3,4}
Component 2: {5,6,7}
Component 3: {8}

Approach:
- Start DFS from every unvisited node.
- All nodes reached in one DFS belong to the same component.

Time: O(n + m)
*/
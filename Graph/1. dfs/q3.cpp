#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;
bool cycle = false;

void dfs(int node, int parent) {
    vis[node] = 1;

    for (auto x : g[node]) {
        if (!vis[x]) {
            dfs(x, node);
        }
        else if (x != parent) {  // if it is visited and then it should be equal to the parent of the node for that to be a cycle
            cycle = true;
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

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }

    if (cycle)
        cout << "Cycle Exists\n";
    else
        cout << "No Cycle\n";
}


/*
PROBLEM: Detect a Cycle in an Undirected Graph

Given n vertices and m undirected edges, determine whether the graph
contains at least one cycle.

Example Input:
6 6
1 2
2 3
3 1
3 4
4 5
5 6

Graph:
    1
   / \
  2---3---4---5---6

Output:
Cycle Exists

Approach:
- Run DFS on every connected component.
- Track the parent of each node.
- If a visited neighbor is NOT the parent, a cycle is found.

Time: O(n + m)
*/
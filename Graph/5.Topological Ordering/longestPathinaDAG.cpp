#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
vector<int> topo;
vector<int> dp;

int n, m;

void dfs_topo(int node)
{
    vis[node] = 1;

    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs_topo(v);
        }
    }

    topo.push_back(node);
}

int main()
{
    cin >> n >> m;

    g.resize(n + 1);
    vis.assign(n + 1, 0);
    dp.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
    }

    // Step 1: Topological Sort
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs_topo(i);
        }
    }

    reverse(topo.begin(), topo.end());

    // Step 2: Longest Path DP
    int ans = 0;

    for (auto node : topo)
    {
        for (auto v : g[node])
        {
            dp[v] = max(dp[v], dp[node] + 1);
        }

        ans = max(ans, dp[node]);
    }

    cout << ans << '\n';
}


/*
Problem: Longest Path in a DAG

Graph:

        1
       / \
      2   3
       \ /
        4
        |
        5
        |
        6

Edges:
1 -> 2
1 -> 3
2 -> 4
3 -> 4
4 -> 5
5 -> 6

Longest Path:
1 -> 2 -> 4 -> 5 -> 6

Length = 4 edges

DP values after processing:
Node:  1  2  3  4  5  6
DP:    0  1  1  2  3  4

Approach:
1. Find the topological order using DFS.
2. Process nodes in topological order.
3. For every edge u -> v:
      dp[v] = max(dp[v], dp[u] + 1)
4. The maximum dp value is the answer.

Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/
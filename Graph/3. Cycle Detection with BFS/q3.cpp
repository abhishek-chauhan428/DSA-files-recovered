#include<bits/stdc++.h>
using namespace std;


vector<int> col, parent, prefix, order;


void dfs(int node, int par, vector<vector<int>>& adj) {
    parent[node] = par;
    col[node] = 2;


    for (auto child : adj[node]) {
        if (col[child] == 1) {
            dfs(child, node, adj);
        } else if (col[child] == 2) {
            // back edge detected
            prefix[node]++;
            if (parent[child] != 0) // avoid accessing prefix[0]
                prefix[parent[child]]--;
        }
        // col[child] == 3 => already processed
    }


    col[node] = 3;
    order.push_back(node);
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);


    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }


    col.resize(n + 1, 1);
    parent.resize(n + 1, 0);
    prefix.resize(n + 1, 0);


    for (int i = 1; i <= n; i++) {
        if (col[i] == 1) {
            dfs(i, 0, adj);
        }
    }


    // reverse(order.begin(), order.end());
    for (auto it : order) {
        prefix[parent[it]] += prefix[it];
    }


    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (prefix[i] > 0) {
            cnt++;
        }
    }


    cout << cnt << endl;
}


/*
Problem: Find Vertices That Are Part of a Cycle

You are given a directed graph with n vertices and m directed edges.
The graph may be disconnected and may contain one or more cycles.

Your task is to determine which vertices are part of at least one
directed cycle and print the total number of such vertices.

Input:
- The first line contains two integers n and m:
    n = number of vertices
    m = number of directed edges
- The next m lines contain two integers u and v,
  representing a directed edge from u to v.

Output:
- Print the number of vertices that are part of at least one cycle.

Approach:
- Perform DFS using 3-coloring:
    1 -> unvisited
    2 -> currently in the DFS recursion stack
    3 -> completely processed
- If during DFS we find an edge from the current vertex to a vertex
  whose color is 2, we have found a back edge.
- A back edge indicates the presence of a directed cycle.
- The prefix array is used to mark the vertices belonging to the
  corresponding DFS-tree path of the detected cycle.
- After DFS is complete, propagate the prefix values through the
  DFS tree.
- Every vertex with prefix[i] > 0 is considered to be part of a cycle.
- Finally, count and print such vertices.

Example:

Input:
5 5
1 2
2 3
3 4
4 2
4 5

Graph:

1 -> 2 -> 3 -> 4 -> 5
     ^         |
     |_________|

The cycle is:
2 -> 3 -> 4 -> 2

Vertices that are part of a cycle:
2, 3, 4

Output:
3

Explanation:
There are 3 vertices that belong to a directed cycle.
*/



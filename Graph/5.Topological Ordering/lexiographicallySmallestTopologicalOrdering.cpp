#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> indegree;
vector<int> topo;   // global

void kahnTopologicalSort(int vertices)
{
    priority_queue<int> p;  // max heap

    // Put all indegree-0 nodes into the heap
    // using negative values
    for (int i = 0; i < vertices; ++i)
    {
        if (indegree[i] == 0)
        {
            p.push(-i);
        }
    }

    while (!p.empty())
    {
        int current = -p.top();
        p.pop();

        topo.push_back(current);

        // Remove current's outgoing edges
        for (int neighbor : g[current])
        {
            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
            {
                p.push(-neighbor);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    g.resize(n);
    indegree.assign(n, 0);

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;

        g[l].push_back(r);
        indegree[r]++;
    }

    kahnTopologicalSort(n);

    // Print topo in main
    for (int node : topo)
    {
        cout << node << " ";
    }

    return 0;
}
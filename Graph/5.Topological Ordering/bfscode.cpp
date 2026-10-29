// NOTE:- Topological Ordering: A linear ordering of vertices in a DAG where for every edge u → v, u appears before v.
// NOTE:- Kahn’s Algorithm finds a topological ordering of a DAG by repeatedly removing nodes with in-degree 0.ee

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> indegree;
vector<int> topo;

void kahnTopologicalSort(int vertices) {
    queue<int> q;

    for (int i = 0; i < vertices; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        topo.push_back(current);

        for (int neighbor : g[current]) {           // clearly maintaining the indegree
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    indegree.assign(n, 0);

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
        indegree[r]++;
    }

    kahnTopologicalSort(n);

    if(topo.size()!=n){
        cout << "there is no cycle";
        return;
    }

    for(int x: topo) cout << x << " ";

    return 0;
}
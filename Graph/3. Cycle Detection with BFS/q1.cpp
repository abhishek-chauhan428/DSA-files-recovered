#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
bool is_cycle = 0;

void dfs(int node){
    col[node]=2;
    for(auto v:g[node]){

         // if(v==par[node]) continue; -> do that for undirected graph.
         
        if(col[v]==1){
            // node - v is a forward edges
            dfs(v);
        }else if(col[v]==2){
            // node - v is a back edge
            // We found a cycle !!
            is_cycle = 1;
        }else if(col[v]==3){
            // node - v is a cross edge
            // unimportant
        }
    }
    col[node]=3;
}

int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i);
        }
    }
}

 /*Problem: Detect Cycle in an Undirected Graph

 You are given an undirected graph with n vertices and m edges.
 Determine whether the graph contains a cycle.

 The graph may be disconnected.

 Input:
 - First line contains n and m.
 - Next m lines contain two integers x and y,
   representing an undirected edge between x and y.

 Output:
 - Print YES if the graph contains a cycle.
 - Otherwise, print NO.

 Example:
 Input:
 5 5
 1 2
 2 3
 3 4
 4 2
 4 5
 Output:
 YES
 The cycle is: 2 -> 3 -> 4 -> 2
 */




// code for undirected graph

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
bool is_cycle = 0;

// CHANGE 1:
// Add 'parent' so that we can ignore the edge
// going back to the node from which we came.
void dfs(int node, int parent){
    col[node]=2;

    for(auto v:g[node]){

        // CHANGE 2:
        // In an undirected graph, every edge is stored
        // in both directions. So ignore the edge
        // from node back to its parent.
        if(v == parent){
            continue;
        }

        if(col[v]==1){
            // node - v is a forward/tree edge
            dfs(v, node);
        }
        else if(col[v]==2){
            // node - v is a back edge
            // We found a cycle !!
            is_cycle = 1;
        }
        // else if(col[v]==3){
        //     // In an undirected graph, a visited non-parent
        //     // node also indicates a cycle.
        //     is_cycle = 1;
        // }
    }

    col[node]=3;
}

int main(){
    int n,m;
    cin>>n>>m;

    g.resize(n+1);
    col.assign(n+1,1);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        // CHANGE 3:
        // Undirected edge => add both directions.
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(col[i]==1){
            // CHANGE 4:
            // Initially there is no parent, so use -1.
            dfs(i, -1);
        }
    }
}
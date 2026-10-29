#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
vector<int> parent;

bool is_cycle = 0;
vector<int> any_cycle;

void dfs(int node, int par){
    parent[node] = par;
    col[node] = 2;

    for(auto v:g[node]){

        // for undirected graph
        //if(v == parent[node]) continue;

        if(col[v] == 1){
            // node - v is a forward edge
            dfs(v,node);
        }
        else if(col[v] == 2){
            // node - v is a back edge
            // We found a cycle !!

            if(is_cycle == 0){
                int temp = node;

                while(temp != v){
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }

                any_cycle.push_back(temp);

                reverse(any_cycle.begin(), any_cycle.end());
            }

            is_cycle = 1;
        }
        else if(col[v] == 3){
           // node - v is a cross edge
        }
    }

    col[node] = 3;
}

int main(){
    int n,m;
    cin >> n >> m;

    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,-1);

    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;

        // undirected graph
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(col[i] == 1){
            dfs(i,-1);
        }
    }

    if(is_cycle){
        cout << "Cycle: ";

        for(auto v:any_cycle){
            cout << v << " ";
        }

        // Print first vertex again to show the complete cycle
        cout << any_cycle[0] << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    return 0;
}




 /*Problem: Print Any Cycle in an Undirected Graph

 You are given an undirected graph with n vertices and m edges.
 Determine whether the graph contains a cycle.

 If a cycle exists, print any one cycle.
 Otherwise, print "No Cycle".

 Input:
 - First line contains n and m.
 - Next m lines contain two integers x and y,
   representing an undirected edge between x and y.

 Output:
 - Print any cycle if one exists.
 - Otherwise, print "No Cycle".

 Example:

 Input:
 5 5
 1 2
 2 3
 3 4
 4 2
 4 5

 Output:
 Cycle: 2 3 4 2
 */


 // NOTE: we can not print everycycle as time complexity becomes n^2 - 


 
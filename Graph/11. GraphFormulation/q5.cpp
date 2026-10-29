#include <bits/stdc++.h>
using namespace std;

int n, m;
using state  =  pair<int,int> ;

vector<vector<char>> grid;
vector<vector<int>> dist, num_path;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isvalid(int x, int y)  {
    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]!='#') return 1;
    return 0;
}

void bfs(state node){
    queue<state> q;
    q.push(node);
    dist[node.first][node.second] = 0;
    
    while(!q.empty()){
        auto xx = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int x = dx[i] + xx.first, y = dy[i] + xx.second;
            if(isvalid(x, y)){  
                if(dist[x][y]==1e9) {   // unvisited cell
                    dist[x][y] = dist[xx.first][xx.second]+1;
                    q.push({x, y});
                    num_path[x][y] = num_path[xx.first][xx.second];
                }
                else if(dist[x][y]==dist[xx.first][xx.second]+1){           // dist is already set but i can also reach the ndoe with the same dist - toh mera wala bhi no. of path add kar lo
                    num_path[x][y] += num_path[xx.first][xx.second];
                }
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.assign(n, vector<char>(m))  ;
    dist.assign(n, vector<int>(m, 1e9));
    num_path.assign(n, vector<int>(m, 0))   ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    // 0, 0 will be me start node and (n-1, 0) will be end node;
    num_path[0][0] = 1;

    bfs({0, 0}) ;


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << dist[i][j] << ", " << num_path[i][j];
            cout << "\n";
        }
    }


    return 0;
}



/*
Problem Statement:

You are given a grid containing:
    'S' -> Start cell
    'E' -> End/Destination cell
    '.' -> Open cell
    '#' -> Blocked cell

You can move from an open cell to any of its 4 neighbouring cells:
    - Up
    - Down
    - Left
    - Right

You cannot move into a blocked cell.

Each move from one cell to an adjacent cell has a cost of 1.

Your task is to find:
    1. The minimum cost (shortest distance) from S to E.
    2. The number of distinct paths that achieve this minimum cost.

Two paths are considered different if they visit the cells in a different order.

Example:

    S . # . .
    . . . . .
    # # # # .
    . . . . .
    E # . . .

For every cell, maintain:
    dist[i][j] = shortest distance from S to (i, j)
    ways[i][j] = number of shortest paths from S to (i, j)

During relaxation from u -> v:

    If dist[v] > dist[u] + 1:
        dist[v] = dist[u] + 1
        ways[v] = ways[u]

    Else if dist[v] == dist[u] + 1:
        ways[v] += ways[u]

Finally:
    dist[E]  = length of the shortest path
    ways[E]  = number of shortest paths

If E is unreachable, report that no path exists.

Since every edge has the same weight (1), this problem can be
solved using BFS with shortest-path counting.
*/
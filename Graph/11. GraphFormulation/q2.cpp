#include <bits/stdc++.h>
using namespace std;


int n, m;
string arr[1000];
using state = pair<int, int> ;
int dist[1000][1000];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool isvalid(int x, int y) {
    if(x>=0 && y>=0 && x<n && y<m) return 1;
    return 0;
}


void bfs01(state node){
    deque<state> q;
    q.push_back(node);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) dist[i][j] = 1e9;
    }
    dist[node.first][node.second] = 0;
    while(!q.empty()){
        auto xx = q.front(); q.pop_front();

        for(int i=0; i<4; i++){
            int x = xx.first + dx[i], y = xx.second + dy[i];
            if(isvalid(x, y)){
                int w = 0;
                if(arr[x][y]=='#') w = 1;
                if(dist[x][y]>dist[xx.first][xx.second]+w){
                    dist[x][y] = dist[xx.first][xx.second]+w;
                    if(w==0) q.push_front({x,y});
                    else q.push_back({x, y});
                }
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    pair<int,int> st, en;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        for(int j=0; j<m; j++){
            if(arr[i][j]=='S') st = {i, j};
            if(arr[i][j]=='E') en = {i, j};
        }
    }

    bfs01(st);
    cout << dist[en.first][en.second];  

    return 0;
}


/*
    Problem Statement:
    ------------------

    You are given a 2D grid representing a maze.

    Each cell of the grid is either:
        - 'S' : Starting cell
        - 'F' : Final/Destination cell
        - '#' : A wall
        - '.' : An empty cell

    You can move from a cell to any of its 4 neighbouring cells:
        - Up
        - Down
        - Left
        - Right

    You are allowed to break walls while moving through the maze.

    Your task is to find the MINIMUM NUMBER OF WALLS that need
    to be broken in order to reach the destination cell 'F'
    starting from 'S'.

    Important:
    ----------
    - Moving to an empty cell costs 0 (no wall is broken).
    - Moving into a wall costs 1 (that wall must be broken).
    - We only care about minimizing the number of walls broken,
      NOT the total number of moves.

    Example:

        S . # .
        # # . .
        . . # F

    We need to find a path from S to F that breaks the
    minimum possible number of walls.

    This can be viewed as a graph problem:
        - Each grid cell is a node.
        - Moving between adjacent cells is an edge.
        - Edge cost = 0 if the next cell is empty.
        - Edge cost = 1 if the next cell is a wall.

    Goal:
        Find the minimum cost required to reach 'F' from 'S'.

    Hint:
        Since every edge has a cost of either 0 or 1,
        0-1 BFS can be used to find the minimum cost efficiently.
*/
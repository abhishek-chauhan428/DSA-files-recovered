#include <bits/stdc++.h>
using namespace std;

using state = pair<int, int>;

vector<vector<char>> grid;
vector<vector<int>> vis, distP, distM;
vector<state> monster, exits;
int n, m;

int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#') return 1;
    return 0;
}

vector<state> neighbour(state node){

    vector<state> ans;
    for(int i=0; i<4; i++){
        int x = node.first + dx[i];
        int y = node.second + dy[i];
        if(isValid(x, y)) ans.push_back({x, y});
    }

    return ans;
}


void bfsM(){
    queue<state> q;
    for(auto x: monster){
        q.push(x);
        distM[x.first][x.second] = 0;
        vis[x.first][x.second] = 1;
    }

    while(!q.empty()){
        state node = q.front();
        q.pop();
        for(auto x: neighbour(node)){
            if(!vis[x.first][x.second]){            // pahle visted hoga wahe min dist dega - every node is touched once only 
                q.push(x);
                distM[x.first][x.second] = distM[node.first][node.second] + 1;
                vis[x.first][x.second] = 1;
            }
        }
    }
}

void bfs(state node){
    queue<state> q;
    q.push(node);
    distP[node.first][node.second]  = 0;
    vis[node.first][node.second]  = 1;
    while(!q.empty()){
        state t = q.front();
        q.pop();
        for(auto x: neighbour(t)){
            if(!vis[x.first][x.second]){
                q.push(x);
                distP[x.first][x.second] = distP[t.first][t.second] + 1;
                vis[x.first][x.second] = 1;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    grid.assign(n, vector<char>(m));

    vis.assign(n, vector<int>(m, 0));
    distP.assign(n, vector<int>(m, 1e9));
    distM.assign(n, vector<int>(m, 1e9));
    monster.assign({});

    int x = -1, y = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            if(grid[i][j]=='M'){
                monster.push_back({i, j});
            }
            if(grid[i][j] == 'A'){
                x = i, y = j;
            }
            if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]!='#') exits.push_back({i, j});
        }
    }

    bfsM();
    vis.assign(n, vector<int>(m, 0));
    bfs({x, y});

    int ans = INT_MAX;
    for(auto x: exits){
        if(distP[x.first][x.second]<distM[x.first][x.second]){
            ans = min(ans, distP[x.first][x.second]);
        }
    }

    if(ans!=INT_MAX){
        cout << "YES";
        cout << "moves required :- " <<  ans;
    }
    else cout << "NO";


    return 0;
}

/*
Problem: Escape from the Monsters

You are given an n × m grid containing:
- 'A' : the player
- 'M' : monsters
- '#' : walls
- '.' : empty cells

The player and all monsters can move one cell at a time in the
four directions (up, down, left, right), but cannot move through walls.

The player escapes if they reach any boundary cell of the grid.
A cell is safe for the player only if the player reaches it strictly
before any monster.

Determine whether the player can escape and, if possible, print the
minimum number of moves required.

Input:
- First line: n m
- Next n lines: the grid

Output:
- Print "YES" followed by the minimum number of moves if escape is possible.
- Otherwise, print "NO".

Example:
Input:
5 6
######
#A...#
#.#M.#
#.M#.#
#....#

Output:
YES
3
*/

// NOTE: - Multisource bfs is used to calculate the shortest distance to nearest source node for every node 
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> arr;
using state = pair<int, int>;

vector<vector<int>> vis;
vector<vector<int>> dis;

bool is_valid(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#'){
        return 1;
    }
    return 0;
}

// For 4-direction movement
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

/*
// Uncomment these instead for Knight moves

int dx[] = {2,1,-1,-2,-2,-1,1,2};

int dy[] = {-1,-2,-2,-1,1,2,2,1};
*/

vector<state> neighbours(state node){
    vector<state> neighs;

    for(int k = 0; k < 4; k++){
        int x = node.first + dx[k];
        int y = node.second + dy[k];

        if(is_valid(x, y)){
            neighs.push_back({x, y});
        }
    }

    return neighs;
}

void bfs(state st_node){

    vis.assign(n, vector<int>(m, 0));
    dis.assign(n, vector<int>(m, 1e9));

    queue<state> q;

    vis[st_node.first][st_node.second] = 1;
    dis[st_node.first][st_node.second] = 0;

    q.push(st_node);

    while(!q.empty()){

        state node = q.front();
        q.pop();

        for(state v : neighbours(node)){
            if(!vis[v.first][v.second]){

                vis[v.first][v.second] = 1;
                dis[v.first][v.second] =
                    dis[node.first][node.second] + 1;

                q.push(v);
            }
        }
    }
}

int main(){

    cin >> n >> m;



arr.resize(n, vector<char>(m));

state st, fin;   // setting the start and the end point

for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        cin >> arr[i][j];

        if(arr[i][j] == 'S'){
            st = {i, j};
        }

        if(arr[i][j] == 'F'){
            fin = {i, j};
        }
    }
}
    bfs(st);

    if(dis[fin.first][fin.second] == 1e9)
        cout << -1 << "\n";
    else
        cout << dis[fin.first][fin.second] << "\n";

    return 0;
}


/* Shortest Path in a Maze

You are given a grid of size N × M representing a maze.

- 'S' represents the starting position.
- 'F' represents the destination.
- '.' represents an empty cell that can be visited.
- '' represents a wall that cannot be crossed.

You can move only in four directions: up, down, left, and right.

Your task is to find the length of the shortest path from S to F. If no such path exists, print -1.

 Input
- The first line contains two integers N and M.
- The next N lines each contain a string of length M describing the maze.

 Output
Print a single integer — the length of the shortest path from S to F. If it is impossible to reach F, print -1.

 Sample Input
6 6
S.#...
..#...
#.#.#.
.....#
####..
F.....

 Sample Output
9

 Constraints
1 ≤ N, M ≤ 1000 */



/*
Followups:-

TODO
1. find the shortest dist of each and every node from the start node - if node is not reachable then take it 100
TODO
2. for the  shortest path to the Final point print the part from the starting node
TODO
3. What if we have we cannot do normal move - we can only do I knight move ( int dx[] = {2,1,-1,-2,-2,-1,1,2}, int dy[] = {-1,-2,-2,-1,1,2,2,1})


*/ 
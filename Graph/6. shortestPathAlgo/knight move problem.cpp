#include <bits/stdc++.h>
using namespace std;

int n, m;

int x, y;       // knight position
int a, b;       // final position

vector<vector<int>> dis;

using state = pair<int, int>;


// For Knight moves
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};

int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};


bool is_valid(int x, int y){

    if(x >= 0 && x < n && y >= 0 && y < m){
        return 1;
    }

    return 0;
}


vector<state> neighbours(state node){

    vector<state> neighs;

    for(int k = 0; k < 8; k++){

        int x = node.first + dx[k];
        int y = node.second + dy[k];

        if(is_valid(x, y)){
            neighs.push_back({x, y});
        }
    }

    return neighs;
}


void bfs(state st_node){

    dis.assign(n, vector<int>(m, 1e9));

    queue<state> q;

    q.push(st_node);
    dis[st_node.first][st_node.second] = 0;


    while(!q.empty()){

        state node = q.front();
        q.pop();


        for(state v : neighbours(node)){

            if(dis[v.first][v.second] >
               dis[node.first][node.second] + 1){

                dis[v.first][v.second] =
                    dis[node.first][node.second] + 1;

                q.push(v);
            }
        }
    }
}


int main(){

    cin >> n >> m;

    // setting the knight position and the final position

    cin >> x >> y;
    cin >> a >> b;


    state st = {x, y};
    state fin = {a, b};


    bfs(st);


    if(dis[fin.first][fin.second] == 1e9)
        cout << -1 << "\n";
    else
        cout << dis[fin.first][fin.second] << "\n";


    return 0;
}


/*
Knight Shortest Path

You are given a chess board of size N × M.

- The knight is initially at position (x, y).
- The final destination is (a, b).

The knight can move according to the standard chess knight movement:

    (x + 2, y + 1)
    (x + 2, y - 1)
    (x - 2, y + 1)
    (x - 2, y - 1)
    (x + 1, y + 2)
    (x + 1, y - 2)
    (x - 1, y + 2)
    (x - 1, y - 2)

Your task is to find the minimum number of moves required
for the knight to reach the final position.

If the final position cannot be reached, print -1.

Input
- The first line contains two integers N and M.
- The second line contains two integers x and y.
- The third line contains two integers a and b.

Output
Print the minimum number of knight moves required.
If it is impossible to reach the destination, print -1.
*/


/*
Followups:-

TODO
1. find the shortest dist of each and every node from the start node
   - if node is not reachable then take it 100

TODO
2. for the shortest path to the Final point,
   print the path from the starting node

TODO
3. What if we have obstacles on the chess board?
   - Some cells cannot be visited by the knight.

TODO
4. What if every knight move has a different cost?
   - Can we still use normal BFS?
   - Think about 0-1 BFS / Dijkstra.
*/
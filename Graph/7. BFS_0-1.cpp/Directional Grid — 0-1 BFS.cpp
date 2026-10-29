#include <bits/stdc++.h>
using namespace std;

int n, m;

int x, y;       // start position
int a, b;       // final position

vector<vector<int>> dis;
vector<string> grid;

using state = pair<int, int>;
using edge = pair<state, int>;


// For Up, Down, Left, Right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


bool is_valid(int x, int y){

    if(x >= 0 && x < n && y >= 0 && y < m){
        return 1;
    }

    return 0;
}


int direction(char ch){

    if(ch == 'U')
        return 0;

    if(ch == 'D')
        return 1;

    if(ch == 'L')
        return 2;

    return 3;        // R
}


vector<edge> neighbours(state node){

    vector<edge> neighs;

    int dir = direction(grid[node.first][node.second]);

    for(int k = 0; k < 4; k++){

        int x = node.first + dx[k];
        int y = node.second + dy[k];

        if(is_valid(x, y)){

            int cost;

            if(k == dir)
                cost = 0;
            else
                cost = 1;

            neighs.push_back({{x, y}, cost});
        }
    }

    return neighs;
}


void bfs(state st_node){

    dis.assign(n, vector<int>(m, 1e9));

    deque<state> dq;

    dq.push_front(st_node);
    dis[st_node.first][st_node.second] = 0;


    while(!dq.empty()){

        state node = dq.front();
        dq.pop_front();


        for(edge e : neighbours(node)){

            state v = e.first;
            int cost = e.second;


            if(dis[v.first][v.second] >
               dis[node.first][node.second] + cost){      // we need to relax the edge

                dis[v.first][v.second] =
                    dis[node.first][node.second] + cost;   // ** Edge Relaxing **


                if(cost == 0){

                    dq.push_front(v);

                }
                else{

                    dq.push_back(v);
                }
            }
        }
    }
}


int main(){

    cin >> n >> m;

    // setting the start position and the final position

    cin >> x >> y;
    cin >> a >> b;


    // input the arrow grid

    grid.resize(n);

    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }


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
===========================================================
                 MINIMUM COST PATH
                    (0-1 BFS)
===========================================================

You are given an n x m grid. Each cell contains an arrow
pointing in one of four directions:

    →  ←  ↑  ↓

You are also given a START cell and a DESTINATION cell.

From any cell, you can move to any of its four adjacent
cells, as long as the new cell is inside the grid.

Cost of a move:
    - 0 : if you move in the direction of the arrow
          in the current cell.
    - 1 : if you move in any other direction.

Find the minimum total cost required to travel from the
START cell to the DESTINATION cell.

-----------------------------------------------------------
Example
-----------------------------------------------------------

Grid:

        C0   C1   C2   C3
      ┌────┬────┬────┬────┐
 R0   │ →  │ →  │ →  │ ↓  │
      ├────┼────┼────┼────┤
 R1   │ ↓  │ ←  │ ↑  │ ↓  │
      ├────┼────┼────┼────┤
 R2   │ →  │ →  │ ←  │ ↓  │
      ├────┼────┼────┼────┤
 R3   │ →  │ →  │ ↑  │ ←  │
      └────┴────┴────┴────┘

START       = (0, 0)
DESTINATION = (3, 3)

For example, if you are at a cell containing:

    →

Moving right  → costs 0
Moving left   ← costs 1
Moving up     ↑ costs 1
Moving down   ↓ costs 1

-----------------------------------------------------------
Goal
-----------------------------------------------------------

Return the minimum cost to reach the DESTINATION from
the START.

Since every move has a cost of either 0 or 1, this problem
can be solved efficiently using 0-1 BFS.

-----------------------------------------------------------
Complexity

Time  : O(n × m)
Space : O(n × m)

===========================================================
*/





/*
My follow ups :-
1. how to identify if we can exit the grid or not 
    observation : - if we stuck in a loop then we will not exit the grid - 
                    1st approach - make a set
                    2nd approach - treet it like a linked list and check if cycle exist
                    3rd approach - if it can exist the grid following the arrows - it should take atmost n*m moves to do it - so run along the path and check if after n*m moves if it exit the grid

*/
#include <bits/stdc++.h>
using namespace std;


int n, m, k;
string arr[1000];
using state = pair<pair<int, int>, int> ;
int dist[1000][1000][11]; // 10 for k;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool isvalid(int x, int y) {
    if(x>=0 && y>=0 && x<n && y<m) return 1;
    return 0;
}


void bfs01(state node){
    queue<state> q;
    q.push(node);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int t=0; t<k; t++) dist[i][j][t] = 1e9 ;
        }
    }
    dist[node.first.first][node.first.second][node.second] = 0;
    while(!q.empty()){
        auto xx = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int x = xx.first.first + dx[i], y = xx.first.second + dy[i];
            if(isvalid(x, y)){
                int nwall = xx.second + arr[x][y]=='#';
                if(nwall<=k){
                    if(dist[x][y][nwall]<dist[xx.first.first][xx.first.second][xx.second]+1) {
                        dist[x][y][nwall] = dist[xx.first.first][xx.first.second][xx.second]+1;
                        q.push({{x, y}, nwall});
                    }
                }
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    pair<int,int> st, en;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        for(int j=0; j<m; j++){
            if(arr[i][j]=='S') st = {i, j};
            if(arr[i][j]=='E') en = {i, j};
        }
    }

    bfs01({st, 0});
    int ans = INT_MAX;
    for(int i=0; i<=k; i++){
        ans = min(ans, dist[en.first][en.second][i]);
    }

    cout << ans;

    return 0;
}


// NOTE: time commplexity is n*m*k;

// NOTE: The graph we are tying to build is actualla 3d graph ???



/*
    Part 2: Minimum Number of Steps
    --------------------------------

    You are given a 2D grid representing a maze.

    Each cell is either:
        - 'S' : Starting cell
        - 'F' : Final/Destination cell
        - '#' : A wall
        - '.' : An empty cell

    You can move from a cell to any of its 4 neighbouring cells:
        - Up
        - Down
        - Left
        - Right

    You are allowed to break at most K walls.

    Your task is to find the MINIMUM NUMBER OF STEPS required
    to reach 'F' from 'S', while breaking at most K walls.

    Important:
    ----------
    - Moving to an empty cell does not consume a wall break.
    - Moving into a wall requires breaking that wall.
    - You can break at most K walls in total.
    - Every move counts as 1 step.
    - Among all possible paths that break <= K walls,
      choose the one with the minimum number of steps.

    State:
    ------
    To solve this, the state needs to keep track of:

        (row, column, walls_broken)

    because reaching the same cell with a different number
    of walls already broken represents a different state.

    Goal:
        Minimize the number of steps required to reach 'F'
        while keeping walls_broken <= K.

    Hint:
        Since every movement costs exactly 1 step,
        BFS can be used.

        The BFS state can be represented as:

            (r, c, walls_broken)

        We should not visit the same state more than once.
*/
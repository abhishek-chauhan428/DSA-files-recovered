#include <bits/stdc++.h>
using namespace std;

int n, m;
using state = pair<int,int>;
using edge = pair<int, state> ;
vector<vector<int>> g, dist1, dist2, dist3, dist;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1 , 1};

bool isvalid(int x, int y){
    if(x>=0 && y<m && y>=0 && x<n) return 1;
    return 0;
}

void bfs(int comp){
    deque<state> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(g[i][j]==comp){
                q.push_back({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto x = q.front();
        q.pop_front();
        for(int i=0; i<4; i++){
            int xx = dx[i]+ x.first;
            int yy = dy[i] + x.second;
            if(isvalid(xx, yy)){
                int w = 1;
                if(g[xx][yy]>0 ){       // it will have weight 0 - 
                    w = 0;
                }
                if(dist[xx][yy]>dist[x.first][x.second]+w){
                    dist[xx][yy] = dist[x.first][x.second] + w;
                    if(w==0)    q.push_front({xx,yy});
                    else q.push_back({xx, yy});
                }

            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.assign(n, vector<int>(m));
    dist.assign(n, vector<int>(m, 1e9));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
        }
    }

    bfs(1);
    dist1 = dist;
     dist.assign(n, vector<int>(m, 1e9));
    bfs(2);
    dist2 = dist;
     dist.assign(n, vector<int>(m, 1e9));
    bfs(3);
    dist3 = dist;

    int ans = INT_MAX;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int val = dist1[i][j] + dist2[i][j] + dist[i][j];
            if(g[i][j]==0)   val-=2;
            ans = min(ans, val);
        }
    }

    cout << ans;

    return 0;
}


/*
Problem: Connect Three Islands

You are given an N x M grid representing a water body.

The grid contains exactly three islands, represented by:
    1 -> Island 1
    2 -> Island 2
    3 -> Island 3

All remaining cells contain:
    0 -> Water

Cells are connected using 4-directional adjacency:
up, down, left, and right.

You can convert any water cell (0) into a bridge cell.
The cost of building a bridge is 1 for every water cell converted.

Find the minimum number of water cells that need to be converted
so that all three islands become connected.

Note:
- Existing island cells cannot be changed.
- Only water cells (0) can be converted into bridges.
- All three islands must belong to the same connected component.
- The bridge does not have to directly connect every pair of islands.

Input:
    The first line contains two integers N and M.
    The next N lines contain M integers representing the grid.

Example Input:
    4 5
    1 1 0 0 2
    1 0 0 2 2
    0 0 3 3 2
    0 3 3 0 0

Output:
    Print the minimum number of water cells that need to be
    converted into bridge cells.

Example Output:
    2

Explanation:
    By converting the minimum number of water cells into bridges,
    islands 1, 2, and 3 can be connected into a single component.
*/



// ** My observation : - there always exist a cell such that if you build bridge to all 3 island you get the optimal solution
// ** if we are moving from an island cell to island cell - no need of bridge - zero cost 
#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<vector<pair<int,int>>> g;
int n, m;
int sum;
int n;

void mst(int node){
    priority_queue<pair<int,int>> pq;
    pq.push({0,node});
    while(!pq.empty()){
        auto v = pq.top(); pq.pop();
        int node = v.second, wt = v.first;
        if(vis[node]) continue;

        // add it to mst;
        vis[node] = 1;
        sum+=wt;
        for(auto x: g[node]){
            if(!vis[x.first]){
                pq.push({-x.second, x.first});
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n;
    vis.assign(n, 0)    ;


    return 0;
}
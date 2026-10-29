#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,pair<int,int>>>> g;

int c[1001];

int dist[1001][1001];
int visited[1001][1001];
int n, m, k;

void dijkstra(pair<int,int> st){

    priority_queue<pair<int,pair<int,int>>> pq;

    dist[st.first][st.second] = 0;
    pq.push({0,st});

    while(!pq.empty()){
        auto val = pq.top();pq.pop();

        int cur_dist = -val.first;
        int cur_city = val.second.first;
        int cur_petrol = val.second.second;

        // check visited
        if(visited[cur_city][cur_petrol]==1)continue;
        visited[cur_city][cur_petrol]=1;
        // -- very crucial.

        // try and go to neighbour
        for(auto v:g[cur_city]){

            // pre-condition
            if(cur_petrol>=v.second.first){

                // relax dijkstra
                if(dist[v.first][cur_petrol-v.second.first]>cur_dist){
                    dist[v.first][cur_petrol-v.second.first] = cur_dist;

                    pq.push({-dist[v.first][cur_petrol-v.second.first],
                             {v.first,cur_petrol-v.second.first}});
                }
            }
        }

        // refill

        // relax dijkstra
// refill

        if(cur_petrol<k){

            // relax dijkstra
            if(dist[cur_city][cur_petrol+1]>cur_dist+c[cur_city]){
                dist[cur_city][cur_petrol+1] = cur_dist+c[cur_city];

                pq.push({-dist[cur_city][cur_petrol+1],
                        {cur_city,cur_petrol+1}});
            }
        }
    }
}

void solve(){


    cin>>n>>m>>k;

    g.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    int st_node = 1 ,en_node = n;

    for(int i=0;i<m;i++){
        int p,d;
        int a,b;
        cin>>a>>b;
        cin>>p>>d;

        g[a].push_back({b,{p,d}});
        g[b].push_back({a,{p,d}});
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dist[i][j] = INT_MAX;
            visited[i][j] = 0;
        }
    }

    dijkstra({st_node,0});

    int ans = INT_MAX;

    for(int i=0;i<=k;i++){
        ans = min(ans,dist[en_node][i]);
    }

    if(ans==INT_MAX)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}

int main(){

    solve();

    return 0;
}
/*
Problem Statement:

You are given a network of n cities connected by m bidirectional roads.

Each city has a petrol price.

INPUT:

The first line contains three integers:
    n, m, k

where:
    n = number of cities
    m = number of roads
    k = maximum petrol tank capacity

The second line contains n integers:
    c[1], c[2], ..., c[n]

where:
    c[i] = cost of 1 unit of petrol in city i.

The next m lines describe the roads.

Each line contains four integers:
    a, b, p, d

where:
    a and b = two cities connected by the road
    p and d = information related to the road/petrol requirement
              (as given in the problem)

A road can be travelled in both directions.

Initially:
    - We are at city 1.
    - Our petrol tank is empty.
    - The maximum capacity of the tank is k.

At any city, we can buy petrol at the petrol price of that city.
We can buy any amount of petrol as long as the tank capacity
does not exceed k.

To travel from one city to another using a road, we must have
enough petrol to cover the petrol required by that road.

The petrol used for travelling is deducted from our tank.

OBJECTIVE:

We have to reach city n from city 1 while spending the minimum
possible amount of money on petrol.

OUTPUT:

Print the minimum amount of money required to reach city n.

If it is impossible to reach city n, print -1.

IMPORTANT:

The answer depends not only on which path we choose, but also
on where and how much petrol we buy.

Therefore, we consider the state as:

    (current_city, petrol_remaining)

For example:

    (2, 5)

means that we are currently at city 2 with 5 units of petrol
remaining in the tank.

We can solve this problem using Dijkstra's algorithm where each
(city, petrol_remaining) pair is treated as a separate state.

    dist[city][petrol]

represents the minimum money required to reach that city with
that amount of petrol remaining.
*/
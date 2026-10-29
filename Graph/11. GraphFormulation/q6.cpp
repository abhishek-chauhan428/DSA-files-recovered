
#include <bits/stdc++.h>
using namespace std;

int n;
int s, e;
set<int> st;
vector<int> dist;

int stringtono(string s){
    int val = 0;
    for(int i=n-1; i>=0; i--){
        int bit = s[i]=='1';
        val+=bit<<(n-i-1);
    }
    return val;
}


void bfs(int node){
    queue<int> q;
    q.push(node);
    dist[node]  =0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int i=0; i<n; i++){
            int x = v^(1<<i); //flip the ith bit
            if(st.find(x)==st.end()){
                if(dist[x]==1e9) {
                    dist[x] = dist[v]+1;
                    q.push(x);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    string ss, t;
    cin >> ss >>t;
    s = stringtono(ss), e = stringtono(t);
    int k;
    cin >> k;
    dist.assign(1<<n, 1e9);

    for(int i=0; i<k; i++){
        string x; 
        cin >> x;
        st.insert(stringtono(x));
    }

    bfs(s);
    cout << dist[e];

    
     
    return 0;
}
/*
    Problem Statement:

    You are given two binary strings, start and target, of the same length n.

    In one move, you can flip exactly one bit of the current string:
        - '0' becomes '1'
        - '1' becomes '0'

    You are also given a set of forbidden binary strings.

    You are NOT allowed to visit any forbidden string during the transformation.

    Find the minimum number of moves required to transform start into target.

    If it is impossible to reach target without visiting a forbidden string,
    return -1.

    Example:

    start = "101"
    target = "000"
    forbidden = {"100", "001"}

    One possible transformation is:

        101 -> 111 -> 110 -> 010 -> 000

    Each move flips exactly one bit, and none of the forbidden strings
    are visited.

    Therefore, the answer is:

        4


    Input:

    - An integer n representing the length of the strings.
    - A binary string start.
    - A binary string target.
    - An integer k representing the number of forbidden strings.
    - k binary strings representing the forbidden strings.


    Output:

    Print the minimum number of moves required to reach target from start.

    If target cannot be reached without visiting a forbidden string,
    print -1.
    n<=20;
*/
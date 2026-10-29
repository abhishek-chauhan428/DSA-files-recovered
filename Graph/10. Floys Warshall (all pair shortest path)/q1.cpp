#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> a(n, vector<int>(n, 1e18));
        for(auto v: edges) {
            int x= v[0], y = v[1], w = v[2];
            a[x][y] = w, a[y][x] = w;
        }
        for(int i=0; i<n ;i++) a[i][i] = 0;


        for(int k=0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j=0; j<n; j++){
                    a[i][j] = min(a[i][j], a[i][k]+ a[k][i]);
                }
            }
        }
        int mn = INT_MAX;
        int city = -1;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(a[i][j]!=1e18){
                    if(a[i][j]<distanceThreshold) cnt++;
                }
            }
            if(cnt <= mn){
                mn = cnt; city = i+1;
            }
        }

        return city;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}
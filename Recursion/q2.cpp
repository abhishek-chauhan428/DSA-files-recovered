#include <bits/stdc++.h>
using namespace std;
int n;
int curr;
int arr[10];
int sol[10];

void gen(int i) {
    if (i==n) {
        for(int i=0; i<curr;i++) cout << sol[i] << "\n";
        cout << "\n";
        return ;
    }
    gen(i+1);
    sol[curr] = arr[i];
    curr++;
    gen(i+1);
    curr--;
    arr[i] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}
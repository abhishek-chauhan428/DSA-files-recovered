#include <bits/stdc++.h>
using namespace std;


void tower_hanoi(int x, char source, char target, char aux) {
    if(x==0) {
        return ;
    }

    tower_hanoi(x-1, source, aux, target);
    cout << "Move Disc " << x << " from " << source << " to " << target << "\n";
    tower_hanoi(x-1, aux, target, source);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tower_hanoi(3, 'A', 'B', 'C');

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long
using i128 = __int128_t;
using u128 = __uint128_t;

string trim(const string&s){int l=0,r=s.size()-1;while(l<s.size()&&isspace(s[l]))l++;while(r>=l&&isspace(s[r]))r--;return s.substr(l,r-l+1);}
vector<string> split(string s,char d){vector<string>v;stringstream ss(s);string w;while(getline(ss,w,d))v.push_back(w);return v;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int power(int a,int b,int mod){if(!b)return 1;int x=power(a,b/2,mod);x=x*x%mod;return b&1?x*a%mod:x;}
int highestOneBit(int x){return 1LL<<(63-__builtin_clzll(x));}
int ceil_div(int x,int y){return x/y+(x%y!=0);}
constexpr bool multipleTestCases = true;

void solve(){
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    if(multipleTestCases) cin >> tt;

    while(tt--){
        solve();
        if(multipleTestCases) cout << "\n";
    }

    return 0;
}
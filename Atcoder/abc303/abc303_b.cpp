#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 55;
int p[N][N], a[N];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j) cin >> a[j];
        for(int j = 2; j <= n; ++j) 
            p[a[j - 1]][a[j]]++, p[a[j]][a[j - 1]]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j)continue;
            if(p[i][j] == 0) ++ans;
        }
    }
    cout << ans / 2 << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}

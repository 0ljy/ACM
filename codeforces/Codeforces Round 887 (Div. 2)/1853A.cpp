//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    int n;
    cin >> n;
    vector<int>a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 2; i <= n; ++i){
        if(a[i] < a[i - 1]){
            cout << 0 << '\n';
            return;
        }
    }
    int x = inf;
    for(int i = 2; i <= n; ++i) x = min(a[i] - a[i - 1], x);
    if(x < 0) cout << 0 << '\n';
    else{
        cout << x / 2 + 1 << '\n';
    }

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}

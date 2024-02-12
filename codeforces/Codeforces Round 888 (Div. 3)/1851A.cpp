// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define int long long
using PII = pair<int, int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    int n, m, k, h;
    cin >> n >> m >> k >> h;
    --m;
    vector<int>a(n);
    for(int i(0); i < n; ++i) cin >> a[i];
    int ans(0);
    for(int i(-m); i <= m; ++i){
        if(i == 0) continue;
        ans += count(ALL(a), h + i * k);
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

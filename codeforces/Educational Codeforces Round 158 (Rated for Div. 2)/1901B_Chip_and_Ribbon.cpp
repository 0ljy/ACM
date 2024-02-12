#include<bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] > a[i - 1]) 
        ans += a[i] - a[i - 1];
    }

    std::cout << ans - 1 << '\n';

    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
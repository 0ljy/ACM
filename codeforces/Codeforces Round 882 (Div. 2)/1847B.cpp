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

const int N = 2e5 + 5;
int a[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int k = a[1];
    int ans = 0;
    if(k == 0)++ans;
    for(int i = 2; i <= n; ++i) {
        if(k == 0) k = a[i];
        else k &= a[i];
        if(k == 0)++ans;
    }
    
    cout << max(ans, 1ll) << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}

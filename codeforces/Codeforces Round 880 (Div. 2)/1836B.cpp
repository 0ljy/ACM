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

void solve(){
	int n, k ,g;
	cin >> n >> k >> g;
	int ans = k * g;
	int rk = (g - 1) / 2;
	int mk = (g + 1) / 2;
	k = k * g - rk * (n - 1);
	if(k % g >= mk) k = (1 + k / g) * g;
	else k = k / g * g;
	if(k >= 0)cout << ans - k << '\n';
	else cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}

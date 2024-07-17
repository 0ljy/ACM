#include <bits/stdc++.h>

enum OPTION {
    Nature,
    Single,
    Double,
};
class StringHash {
    #define int long long
private:
    std::vector<int> hashcode_1, hashcode_2, p_1, p_2;
    int base_1 = 131; 
    int base_2 = 133331;
    OPTION op;
    int mod_1;
    int mod_2;
    constexpr bool isprime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }
    constexpr int findPrime(int n) {
        while (!isprime(n)) n++;
        return n;
    }
    void init_nature(const std::string &s) {
        p_1[0] = hashcode_1[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hashcode_1[i] = hashcode_1[i - 1] * base_1 + s[i - 1];
            p_1[i] = p_1[i - 1] * base_1;
        }
    }
    void init_single(const std::string &s) {
        p_1[0] = hashcode_1[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hashcode_1[i] = (1LL * hashcode_1[i - 1] * base_1 + s[i - 1]) % mod_1;
            p_1[i] = 1LL * p_1[i - 1] * base_1 % mod_1;
        }
    }
    void init_double(const std::string &s) {
        hashcode_2.assign(s.size() + 1, {});
        p_2.assign(s.size() + 1, {});
        p_1[0] = p_2[0] = hashcode_1[0] = hashcode_2[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hashcode_1[i] = (1LL * hashcode_1[i - 1] * base_1 + s[i - 1]) % mod_1;
            hashcode_2[i] = (1LL * hashcode_2[i - 1] * base_2 + s[i - 1]) % mod_2;
            p_1[i] = 1LL * p_1[i - 1] * base_1 % mod_1;
            p_2[i] = 1LL * p_2[i - 1] * base_2 % mod_2;
        }
    }
    std::pair<int, int> get_nature(int l, int r) {
        return {hashcode_1[r] - hashcode_1[l - 1] * p_1[r - l + 1], 0LL};
    }
    std::pair<int, int> get_single(int l, int r) {
        return {(hashcode_1[r] + (mod_1 - hashcode_1[l - 1]) * p_1[r - l + 1]) % mod_1, 0LL};
    }
    std::pair<int, int> get_double(int l, int r) {
        return {(hashcode_1[r] + 1LL * (mod_1 - hashcode_1[l - 1]) * p_1[r - l + 1]) % mod_1,
        (hashcode_2[r] + 1LL * (mod_2 - hashcode_2[l - 1]) * p_2[r - l + 1]) % mod_2};
    }
public:
    StringHash(const std::string &s, OPTION option) : op(option), hashcode_1(s.size() + 1), p_1(s.size() + 1){
        static int MOD_1;
        static int MOD_2;
        if(!MOD_1) {
            std::mt19937_64 rnd(time(0));
            MOD_1 = findPrime(rnd() % 900000000 + 100000000);
            MOD_2 = findPrime(rnd() % 900000000 + 100000000);
        }
        mod_1 = MOD_1;
        mod_2 = MOD_2;
        if(op == Nature) init_nature(s);
        else if(op == Single) init_single(s);
        else if(op == Double) init_double(s);
    }
    std::pair<int, int> get(int l, int r) {
        ++l, ++r;
        if(op == Nature) return get_nature(l, r);
        else if(op == Single) return get_single(l, r);
        else if(op == Double) return get_double(l, r);
        return {0, 0};
    }
    std::pair<int, int> getAll() {
        if(op == Double) return {hashcode_1.back(), hashcode_2.back()};
        else return {hashcode_1.back(), 0};
    }
    #undef int
};

template<const int T>
struct ModInt {
	constexpr ModInt(int x = 0) : x(x % T) {}
	constexpr int val() { return x; }
	constexpr ModInt operator+ (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < T ? x0 : x0 - T); }
	constexpr ModInt operator- (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + T : x0); }
	constexpr ModInt operator* (const ModInt &a) const { return ModInt(1LL * x * a.x % T); }
	constexpr ModInt operator/ (const ModInt &a) const { return *this * a.inv(); }
	constexpr bool operator== (const ModInt &a) const { return x == a.x; };
	constexpr bool operator!= (const ModInt &a) const { return x != a.x; };
	constexpr void operator+= (const ModInt &a) { x += a.x; if (x >= T) x -= T; }
	constexpr void operator-= (const ModInt &a) { x -= a.x; if (x < 0) x += T; }
	constexpr void operator*= (const ModInt &a) { x = 1LL * x * a.x % T; }			
	constexpr void operator/= (const ModInt &a) { *this = *this / a; }
	constexpr friend ModInt operator+ (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < T ? x0 : x0 - T); }
	constexpr friend ModInt operator- (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + T : x0); }			
	constexpr friend ModInt operator* (int y, const ModInt &a){ return ModInt(1LL * y * a.x % T);}
	constexpr friend ModInt operator/ (int y, const ModInt &a){ return ModInt(y) / a;}
	constexpr friend std::ostream &operator<< (std::ostream &os, const ModInt &a) { return os << a.x;}
	constexpr friend std::istream &operator>> (std::istream &is, ModInt &t){return is >> t.x;}						
	constexpr ModInt operator^ (long long n) const {
        ModInt res(1), mul(x);
        while(n){
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
	}
private:
	int x;
	constexpr ModInt inv() const {
		int a = x, b = T, u = 1, v = 0;
		while (b) {
			int t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += T;
		return u;
	}
};
constexpr int mod = 998244353;
using Mint = ModInt<mod>;


void solve() {
    std::string s, rs;
    std::cin >> s;
    int n = s.size();
    rs = s;
    std::reverse(rs.begin(), rs.end());
    Mint ans = 0;
    StringHash X(s, Single), Y(rs, Single);
    Mint last = 0;
    for(int i = 0; i < n; ++i) {
        
        if(i % 2 == 0) last = last * 26 + s[i / 2] - 'a';
        ans += last;

        if(X.get(0, i) == Y.get(n - i - 1, n - 1)) {
            ans += 1;
        } else {
            if(i % 2 == 0) {
                int l = 0, r = i / 2, pos = 0;
                int M = i / 2, M1 = n - 1 - M;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    if(X.get(M - mid, M + mid) == Y.get(M1 - mid, M1 + mid)) l = mid + 1, pos = mid;
                    else r = mid - 1;
                }
                if(s[M - pos - 1] < s[M + pos + 1]) ans += 1;
            } else {
                int l = 0, r = i / 2, pos = -1;
                int M = i / 2, M1 = n - 1 - M;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    if(X.get(M - mid, M + mid + 1) == Y.get(M1 - mid - 1, M1 + mid)) l = mid + 1,  pos = mid;
                    else r = mid - 1;
                }
                if(s[M - pos - 1] < s[M + pos + 2]) ans += 1;
            }
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
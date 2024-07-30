#include <bits/stdc++.h>
#include <type_traits>

template <class T>
constexpr void radix_sort(std::vector<T> &a) {
    T p[20] = {1};
    if constexpr(std::is_same<T, int>::value) {
        for(int i = 1; i < 10; ++i) p[i] = p[i - 1] * 10;
    } else if constexpr(std::is_same<T, long long>::value) {
        for(int i = 1; i < 19; ++i) p[i] = p[i - 1] * 10;
    } else assert(0);

    std::array<std::vector<T>, 10> bucket;
    std::vector<T> list = a;

    for(int i = 0; ; ++i) {
        bool f = 0;
        for(auto j:list) {
            T x = j / p[i];
            if(x != 0) f = 1;
            bucket[x % 10].push_back(j);
        }
        list.clear();
        for(auto &j:bucket) for(auto &k:j) list.push_back(k);
        for(auto &j:bucket) j.clear();
        if(!f) break;
    }
    a = std::move(list);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    radix_sort(a);
    for(int i = 0; i < n; ++i) std::cout << a[i] << ' ';
}
#include <bits/stdc++.h>
#include <format>

#define int long long
#define rep(i,b,e)for(int i=b;i<e;++i)
#define RETURN(x)do{return x,void();}while(0)
#define All(x)x.begin(),x.end()
#define pb(x)push_back(x)
#define eb(x)emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX
template<class T>using vec=std::vector<T>;using str=std::string;template<class K,class V>using umap=std::unordered_map<K,V>;template<class T>using uset=std::unordered_set<T>;template<class K,class V>std::istream&operator>>(std::istream&in,std::pair<K,V>&v){in>>v.first>>v.second;return in;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::pair<K,V>&v){out<<'{'<<v.first<<","<<v.second<<'}';return out;}template<class T>std::istream&operator>>(std::istream&in,std::vector<T>&v){for(auto&i:v)in>>i;return in;}template<class T>std::ostream&operator<<(std::ostream&out,const std::vector<T>&v){for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];return out;}template<class T>std::ostream&operator<<(std::ostream&out,const std::set<T>&s){out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp){out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<i->first<<","<<i->second<<"}\n";return out;}using Pii=std::pair<int,int>;template<class T>using vvec=std::vector<std::vector<T>>;template<class K,class V>struct std::hash<std::pair<K,V>>{size_t operator()(const std::pair<K,V>&p)const{return std::hash<K>{}(p.first)^std::hash<V>{}(p.second);}};template<class T>using min_heap=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using max_heap=std::priority_queue<T>;
#define vec(type,x,sz,val)std::vector<type>x(sz,val);
#define vvec(type,x,sz1,sz2,val)std::vector<std::vector<type>>x(sz1,std::vector<type>(sz2,val));
#if defined(_WIN64)
#define log(...)print(#__VA_ARGS__" ::",__VA_ARGS__)<<std::endl
template<class...Ts>auto&print(Ts...ts){return((std::cerr<<ts<<" "),...);}
#define sure(x)if(!(x)){std::cerr<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define sure(x)111
#define log(...)111
#endif

int op(str option, int a, int b) {
    std::cout << std::format("{} {} {}", option, a, b) << std::endl;
    int val;
    std::cin >> val;
    return val;
}
int getsum(int a, int b) {
    return op("and", a, b) + op("or", a, b);
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    vec<int> add;
    vec<Pii> val(n);
    val[0] = {0, 1};
    rep(i, 1, n) {
        val[i] = {getsum(1, i + 1), i + 1};
    }
    int sum = getsum(2, 3);
    int x = (val[1].first + val[2].first - sum) / 2;
    val.front().first = x;
    rep(i, 1, n) val[i].first -= x;
    std::ranges::sort(val);
    std::cout << "finish " << val[k - 1].first << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

/*
1 1 1 1
x 2-x x 2-x


*/


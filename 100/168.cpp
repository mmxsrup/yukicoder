#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int n;
ll X[1010], Y[1010];
ll d[1010][1010];

class DisjointSet{
    public:
        vector<int> rank, p;//rank:木の高さ p:親の頂点番号
        DisjointSet(){}
        DisjointSet(int size){//頂点の数
            rank.resize(size, 0);
            p.resize(size, 0);
            rep(i, size) makeSet(i);
        }
        void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
        }
        bool same(int x, int y){return findSet(x) == findSet(y);}
        void unite(int x, int y){link(findSet(x), findSet(y));}
        void link(int x, int y){
            if(rank[x] > rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
        int findSet(int x){
            if(x != p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};

bool solve(ll len){
	DisjointSet ds = DisjointSet(n);
	rep(i, n)rep(j, n){
		if(d[i][j] <= len * len){
			ds.unite(i, j);
		}
	}
	return ds.same(0, n - 1);
}

int main(void){
	cin >> n;
	rep(i, n) cin >> X[i] >> Y[i];
	rep(i, n)rep(j, n){
		d[i][j] = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
	}

	ll left = 0, right = 1e10;
	while(right - left > 1){
		ll mid = (left + right) / 2;
		if(solve(mid)){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	// printf("%lld %lld\n", left, right);
	ll ans = left;
	for (int i = 0; i <= 11; ++i){
		if(ans % 10 == 0){
			if(solve(ans)) break;
		}
		ans++;
	}
	printf("%lld\n", ans);
	return 0;
}
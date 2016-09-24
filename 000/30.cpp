#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
const int INF = 1e9;

int n, m;
vector<pair<int, int> > G[110];
vector<pair<int, int> > rG[110];

int dp[110];

int dfs(int u){
	if(u == n - 1){
		return dp[u] = 1;
	}
	if(dp[u]) return dp[u];

	int ret = 0;
	for(auto v : G[u]){// u -> v.first
		ret += dfs(v.first) * v.second;
	}
	return dp[u] = ret;
}

int main(void){
	cin >> n >> m;
	rep(i, m){
		int p, q, r; cin >> p >> q >> r;
		p--; r--;
		//p -> r
		G[p].push_back(make_pair(r, q));
		rG[r].push_back(make_pair(p, q));

	}
	rep(i, 110) dp[i] = 0;

	rep(i, n){
		dfs(i);
	}

	rep(i, n - 1){
		if(rG[i].size() != 0){
			printf("0\n");
		}else{
			printf("%d\n", dp[i]);
		}
	}
	return 0;
}
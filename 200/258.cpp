#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

int n, v[1010];
//dp[i][j] := i番目のお寿司までを考えて、j=1の時は、i番目の寿司を食べ、
//j=0の時は、i番目の寿司を食べていない

int dp[1010][2];
int main(void){
	int n, v[1010];
	cin >> n;
	rep(i, n) cin >> v[i];
	rep(i, 1010)rep(j, 2) dp[i][j] = 0;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < 2; ++j){
			if(j == 0){//前回の寿司を食べていない
				dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);//食べない　-(1)
				dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + v[i]);//食べる -(2)
			}else{
				dp[i + 1][0] = max(dp[i + 1][0], dp[i][1]);//食べれない -(3)
			}
		}
	}

	int ans, f;
	vector<int> g;
	if(dp[n][0] > dp[n][1]){
		ans = dp[n][0];
		f = 0;
	}else{
		ans = dp[n][1];
		f = 1;
		g.push_back(n);
	}

	//dpの漸化式を逆にたどる
	for (int i = n - 1; i >= 0; --i){
		if(f == 0){//次は、f=0 or f=1
			if(dp[i + 1][f] == dp[i][0]){//i番目を食べない -(1)s
				f = 0;
			}else if(dp[i + 1][f] == dp[i][1]){//i - 1番目を食べる -(3)
				f = 1;
				g.push_back(i);
			}
		}else{//次は、f=0
			if(dp[i + 1][1] = dp[i][0] + v[i]){//i番目を食べる　-(2)
				f = 0;
			}
		}
	}
	reverse(g.begin(), g.end());

	printf("%d\n", ans);
	rep(i, g.size()){
		printf("%d ", g[i]);
	}
	printf("\n");
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

//dp[i][j] := i番目のマットまでで考えて、
//j=1ならBのマットは条件を満たし、j=2ならBCのマットは条件を満たし、
// j=3ならすべてのマットの条件を満たす
int dp[50][4];
int main(void){
	vector<int> s(3);
	int n;
	rep(i, 3) cin >> s[i];
	cin >> n;
	sort(s.begin(), s.end());

	vector<int> e(n);
	rep(i, n) cin >> e[i];
	sort(e.begin(), e.end());

	dp[0][0] = 1;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= 3; ++j){
			if(j < 3 && s[j] <= e[i]){//j個目に条件を満たすもととして選択可
				dp[i + 1][j + 1] += dp[i][j];//選択する
				dp[i + 1][j] += dp[i][j];//選択しない
			}else{//選択しても条件は満たさない
				dp[i + 1][j] += 2 * dp[i][j];//選択するしないの2通り
			}
		}
	}

	printf("%lld\n", dp[n][3]);
	return 0;
}
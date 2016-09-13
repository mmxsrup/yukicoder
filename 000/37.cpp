#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

//dp[i][j] := i番目のアトラクションまで見て、待ち時間の総和がjの時の満足度の最大値
int dp[20][10010];
int c[20], v[20];
int main(void){
	int t, n; cin >> t >> n;
	rep(i, n)cin >> c[i];
	rep(i, n)cin >> v[i];

	rep(i, 20)rep(j, 10010)dp[i][j] = -1;
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= t; ++j){
			int sum = 0;
			dp[i + 1][j] = dp[i][j];//i番目のアトラクションに乗らないとき
			for (int k = v[i], cnt = 1; k >= 0; k /= 2, cnt++){
				if(k == 0) break;
				sum += k;//i番目のアトラクションをcnt回のって得られる満足度の合計
				if(j - c[i] * cnt >= 0){
					if(dp[i][j - c[i] * cnt] != -1){
						dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - c[i] * cnt] + sum);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= t; ++i){
		ans = max(ans, dp[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}
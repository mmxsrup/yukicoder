#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int n;
int d[20];
//dp[mask][lim] := 集合maskのモンスターと戦った時に最大体力が lim * 100 の時に、
//残りの体力の最大値
int dp[(1 << 18)][18];
int main(void){
	cin >> n;
	rep(i, n) cin >> d[i];

	rep(i, (1 << 18))rep(j, 18) dp[i][j] = 0;
	dp[0][1] = 100;
	rep(mask, (1 << n)) for (int lim = 1; lim <= 15; ++lim){//最大体力 / 100
		rep(i, n){
			if(dp[mask][lim] == 0) continue;
			//配るdp
			if((mask & (1 << i)) == 0){//ibit目のモンスターとまだ戦っていない
				if(d[i] >= 0){//よいもんすたー	
					int t = min(lim * 100, dp[mask][lim] + d[i]);//最大体力は超えない
					dp[mask | (1 << i)][lim] = max(dp[mask | (1 << i)][lim], t);
				}else{//悪いもんすたー
					int r = dp[mask][lim] + d[i];//残り体力
					if(r > 0){//体力残る
						dp[mask | (1 << i)][lim + 1] = max(dp[mask | (1 << i)][lim + 1], r);
					}else{//シニマシタ
						dp[mask | (1 << i)][lim + 1] = max(dp[mask | (1 << i)][lim + 1], 0);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= 16; ++i){
		ans = max(ans, dp[(1 << n) - 1][i]);
	}
	printf("%d\n", ans);
	return 0;
}
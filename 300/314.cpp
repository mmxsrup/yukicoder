#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int mod = 1e9 + 7;
//dp[i][j] := i番目まで考えて、j回連続ケン
ll dp[1000010][3];
int main(void){
	int n; cin >> n;
	rep(i, n)rep(j, 3)dp[i][j] = 0;
	dp[1][1] = 1;//ケン
	for (int i = 1; i < n; ++i){
		for (int j = 0; j < 3; ++j){
			if(j == 0){//*パー
				(dp[i + 1][1] += dp[i][0]) %= mod;//ケン
			}else if(j == 1){//*パー　ケン
				(dp[i + 1][0] += dp[i][1]) %= mod;//パー
				(dp[i + 1][2] += dp[i][1]) %= mod;//ケン
			}else if(j == 2){//*パー ケン　ケン
				(dp[i + 1][0] += dp[i][2]) %= mod;//パー
			}
		}
	}

	ll ans = 0;
	rep(i, 3){
		(ans += dp[n][i]) % mod;
	}
	printf("%lld\n", ans % mod);
	return 0;
}
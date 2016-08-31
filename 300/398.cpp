#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

//dp[i][j][k][l] := i番目まの審査員まで考えて(0origin)、
//最小値がj、最大値がkで合計がlの時の場合の数。
int dp[7][110][110][610];
int main(void){
	double x; cin >> x;
	
	rep(i, 6)rep(j, 101)rep(k, 101)rep(l, 601){
		dp[i][j][k][l] = 0;//場合の数0で初期化
	}
	rep(i, 101){
		dp[0][i][i][i] = 1;//0番目の審査員まで考えた時。
	}

	rep(i, 5)rep(j, 101)rep(k, 101)rep(l, 601){
		if(dp[i][j][k][l] == 0) continue;
		rep(now, 101){
			//配るdp
			if(now < j){
				dp[i + 1][now][k][l + now] += dp[i][j][k][l];
			}else if(k < now){
				dp[i + 1][j][now][l + now] += dp[i][j][k][l];
			}else{
				dp[i + 1][j][k][l + now]   += dp[i][j][k][l];
			}
		}
	}

	ll ans = 0;
	rep(j, 101)rep(k, 101)rep(l, 601){
		double sum = l - j - k;
		if(sum == 4.0 * x){//(l - j - k) = 4 * x
			ans += dp[5][j][k][l];
		}
	}
	cout << ans << endl;
	return 0;
}
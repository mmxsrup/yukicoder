#include <iostream>
#include <cstdio>
#include <cmath>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

//dp[i][j] := i回回目の試合にj番目のひとが勝つ確率

double dp[12][1200];
int m;
double s[1200];
//memo[i][j] := iとjが戦い、i番目の人が勝つ確率
double memo[1200][1200];
int main(void){
	cin >> m;
	rep(i, pow(2, m)) cin >> s[i];
	rep(i, pow(2, m))rep(j, pow(2, m)){
		memo[i][j] = pow(s[i], 2.0) / (pow(s[i], 2.0) + pow(s[j], 2.0));
	}

	//確率dp　(可能性のある対戦相手を探すのが難しい)
	rep(i, 12)rep(j, 1200) dp[i][j] = 0.0;
	rep(i, 1200)dp[0][i] = 1.0;

	int mask = 0xFFFFFF;
	for (int i = 0; i < m; ++i){//何試合目
		mask -= 1 << i;
		for (int x = 0; x < (1 << m); ++x){//戦う人の番号(勝率を求める側)
			for (int y = 0; y < (1 << m); ++y){//i試合目に戦う可能性のある相手を探す
				if(x == y)continue;
				if(((x ^ y) & (1 << i)) != 0 && (x & mask) == (y & mask)){//ここが難しい
					dp[i + 1][x] += dp[i][x] * dp[i][y] * memo[x][y];
				}
			}
		}
	}
	printf("%.9f\n", dp[m][0]);
	return 0;
}
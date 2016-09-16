#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
int n, m;

//dp[i][s] := i番目の箱まで考えて、集合sをすべてを入れるのに使う箱の最小数
int dp[12][(1 << 12)];
//sum[s] := 集合sの荷物の合計値
int sum[(1 << 12)];

int main(void){
	cin >> n;
	vector<int> A(n);
	rep(i, n) cin >> A[i];
	sort(A.begin(), A.end());
	cin >> m;
	vector<int> B(m);
	rep(i, m) cin >> B[i];
	//箱は大きいものから使ったほうがいい
	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());

	//選んだ荷物の組み合わせによる荷物の合計を出しておく。
	for (int mask = 0; mask < (1 << n); ++mask){
		int tsum = 0;
		for (int p = 0; p < n; ++p){
			if(mask & (1 << p)){
				tsum += A[p];
			}
		}
		sum[mask] = tsum;
	}

	//dp
	rep(i, 12)rep(j, (1 << 12)) dp[i][j] = INF;
	dp[0][0] = 0;
	for (int i = 0; i < m; ++i){//i番目の箱を考える
		for (int mask1 = 0; mask1 < (1 << n); ++mask1){//i-1番目までの箱に入っている荷物の集合
			if(dp[i][mask1] == INF)continue;//mask1の集合がでi-1番目までの箱を使い入れられていない
			for (int mask2 = 0; mask2 < (1 << n); ++mask2){//mask2集合はi番目の箱にいれようとする荷物
				//同じ位置のbitが立っていない, mask2の集合の荷物がi番目の箱に入る
				if((mask1 & mask2) == 0 && sum[mask2] <= B[i]){
					dp[i + 1][mask1 | mask2] = min(dp[i + 1][mask1 | mask2], dp[i][mask1] + 1);
				}
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= m; ++i){
		ans = min(ans, dp[i][(1 << n) - 1]);
	}
	if(ans != INF){
		printf("%d\n", ans);
	}else{
		printf("-1\n");
	}
	return 0;
}
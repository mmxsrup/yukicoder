#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int n, m;
//dp1[i][j][k] := (0番目の頂点を選ばず、)i番目までを考えて、
//選んだ頂点がj個でi番目の頂点をk=1の時選び、k=0の時選んでいない
int dp1[3010][3010][2];
//dp1[i][j][k] := (0番目の頂点を選び、)i番目までを考えて、
//選んだ頂点がj個でi番目の頂点をk=1の時選び、k=0の時選んでいない
int dp2[3010][3010][2];
const int INF = 1e9;
int main(void){
	cin >> n >> m;
	vector<int> w(n);
	rep(i, n) cin >> w[i];

	rep(i, 3010)rep(j, 3010)rep(k, 2){
		dp1[i][j][k] = dp2[i][j][k] = -INF;
	}
	dp1[0][0][0] = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= i + 1; ++j){
			for (int k = 0; k < 2; ++k){
				if(dp1[i][j][k] == -INF)continue;
				if(k == 0){//i番目の頂点を選んでいない
					dp1[i + 1][j + 1][1] = max(dp1[i][j][k], dp1[i + 1][j + 1][1]);//i+1番目を選ぶ
					dp1[i + 1][j][0] = max(dp1[i][j][k], dp1[i + 1][j][0]);//i+1番目を選ばない
				}else{//i番目の頂点を選んでいる
					dp1[i + 1][j + 1][1] = max(dp1[i][j][k] + w[i], dp1[i + 1][j + 1][1]);//i+1番目を選ぶ
					dp1[i + 1][j][0] = max(dp1[i][j][k], dp1[i + 1][j][0]);//i+1番目を選ばない
				}
			}
		}
	}

	dp2[0][1][1] = 0;
	for (int i = 0; i < n - 1; ++i){
		for (int j = 0; j <= i + 1; ++j){
			for (int k = 0; k < 2; ++k){
				if(dp2[i][j][k] == -INF)continue;
				if(k == 0){//i番目の頂点を選んでいない
					dp2[i + 1][j][0] = max(dp2[i][j][k], dp2[i + 1][j][0]);//i+1番目を選ばない
					if(i == n - 2){//0番目の頂点を選んでいるのでw[i + 1]も考える
						dp2[i + 1][j + 1][1] = max(dp2[i][j][k] + w[i + 1], dp2[i + 1][j + 1][1]);//i+1番目を選ぶ
					}else{
						dp2[i + 1][j + 1][1] = max(dp2[i][j][k], dp2[i + 1][j + 1][1]);//i+1番目を選ぶ
					}
				}else{//i番目の頂点を選んでいる
					dp2[i + 1][j][0] = max(dp2[i][j][k], dp2[i + 1][j][0]);//i+1番目を選ばない
					if(i == n - 2){//0番目の頂点を選んでいるのでw[i + 1]も考える
						dp2[i + 1][j + 1][1] = max(dp2[i][j][k] + w[i] + w[i + 1], dp2[i + 1][j + 1][1]);//i+1番目を選ぶ
					}else{
						dp2[i + 1][j + 1][1] = max(dp2[i][j][k] + w[i], dp2[i + 1][j + 1][1]);//i+1番目を選ぶ
					}
				}
			}
		}
	}

	int ans = -INF;
	rep(i, n){
		rep(j, 2){
			ans = max(ans, dp1[n - 1][m][j]);
			ans = max(ans, dp2[n - 1][m][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
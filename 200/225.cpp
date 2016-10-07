#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

//SをTに変えるときの最小コストを求める
//dp[i][j] := 文字列Sのi番目までで、文字列Tのj番目までを作ることを考えた時の、
//操作回数の最小値
int dp[1010][1010];

int main(void){
	int n, m; cin >> n >> m;
	string S, T; cin >> S >> T;
	rep(i, 1010)rep(j, 1010)dp[i][j] = INF;

	//dp[i][0] := Sのi文字目まで考えた時に、Tの0文字まで一致するとき、i文字分削除する。
	//dp[0][i] := Sの0文字目まで考えた時に、Tのi文字目まで一致するとき、Sの0文字目の後ろにT[0]からT[i - 1]を挿入
	rep(i, 1010) dp[i][0] = dp[0][i] = i;

	//dp[i][j] = dp[i - 1][j - 1] (+1) := Sのi文字目をTのj文字目に変える
	//dp[i][j] = dp[i - 1][j] + 1 := Sのi文字目を削除
	//dp[i][j] = dp[i][j - 1] + 1 := S[i]とS[i + 1]の間にT[j]を挿入
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			if(S[i - 1] == T[j - 1]){//i文字目とj文字目は一致
				dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j] + 1, dp[i][j - 1] + 1});
			}else{
				dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});				
			}
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int mod = 1e9 + 7;

//スターリング数 S(n, k) 区別できるn個のものを区別できないkグループに分類する方法の場合の数
//S[i][j] := i組の夫婦が同じグループに属し、合計jグループ作る場合の数
ll S[600][600];
//com[i][j] := iCj
ll com[600][600];

//x^k mod
ll powmod(ll x, ll k, ll m){
	if(k == 0) return 1;
	if(k % 2 == 0) return powmod(x * x % m, k / 2, m);
	else return x * powmod(x, k - 1, m) % m;
}

int main(void){
	int n; cin >> n;

	S[0][0] = 1;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= i; ++j){
			//スターリング数の漸化式
			S[i][j] = (S[i - 1][j - 1] + j * S[i - 1][j]) % mod;
		}
	}

	//combination
	com[0][0] = 1;
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= i; ++j){
			//パスカルの３角形
			if(j == 0) com[i][j] = com[i - 1][j] % mod;
			else com[i][j] = (com[i - 1][j] + com[i - 1][j - 1]) % mod;
		}
	}

	ll sum = 0;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= i; ++j){
			//夫婦が同じグループに入るi組の選び方と、残りのn-	i組の夫婦の入れ方をかける
			sum += (com[n][i] * S[i][j]) % mod * powmod(j * (j - 1), n - i, mod) % mod;
			sum %= mod;
		}	
	}

	printf("%lld\n", sum % mod);
	return 0;
}
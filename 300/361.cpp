#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int dp[510];

int grundy(int L, int D){
	if(dp[L] != -1)return dp[L];

	set<int> s;
	for (int i = 1; i <= L; ++i){
		for (int j = i + 1; j <= L; ++j){
			int k = L - (i + j);
			if(k - i <= D && i < j && j < k){
				s.insert(grundy(i, D) ^ grundy(j, D) ^ grundy(k, D));
			}

		}
	}

	int res = 0;
	while(s.count(res)) res++;
	return dp[L] = res;
}

int main(void){
	rep(i, 510) dp[i] = -1;
	int l, d; cin >> l >> d;
	if(grundy(l, d) == 0){
		printf("matsu\n");
	}else{
		printf("kado\n");
	}
	return 0;
}
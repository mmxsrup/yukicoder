#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

bool isprime[10010];
//エラトテネス
void eratos(int m){
    for (int i = 0; i <= m; ++i) isprime[i] = true;
    isprime[0] = isprime[1] = false;
    //iを残してiの倍数を消していく
    for (int i = 2; i <= m; ++i){
        if(isprime[i]){
            for (int j = 2 * i; j <= m; j += i){
                isprime[j] = false;
            }
        }
    }
}

int dp[10010];
int grundy(int x){
	if(dp[x] != -1) return dp[x];
	if(x == 2 || x == 3) return dp[x] = 0;//負け

	set<int> s;
	for (int i = 2; i <= x; ++i){
		if(isprime[i] && x - i >= 2){
			s.insert(grundy(x - i));
		}
	}

	int res = 0;
	while(s.count(res)){
		res++;
	}
	return dp[x] = res;
}

int main(void){
	int n; cin >> n;
	eratos(n);
	rep(i, 10010)dp[i] = -1;

	if(grundy(n) == 0) printf("Lose\n");
	else printf("Win\n");
	return 0;
}
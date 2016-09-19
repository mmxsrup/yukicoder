#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int n, k;
int x[1010], y[1010];
int goal[110];//goal[i] := i番目から出発すると、何番目にたどり着くか
int t[110];//time[i] := i番目から初めて、i番目の到達する最小の数

ll lcm(ll a, ll b){
	return a / __gcd(a, b) * b;
}

int main(void){
	cin >> n >> k;
	rep(i, k) cin >> x[i] >> y[i];

	for (int i = 1; i <= n; ++i){
		goal[i] = i;
	}

	for (int i = k - 1; i >= 0; --i){
		swap(goal[x[i]], goal[y[i]]);
	}
	for (int s = 1; s <= n; ++s){
		int now = s, ans = 0;
		while(1){
			now = goal[now];
			ans++;
			if(now == s){
				t[s] = ans;
				break;
			}
		}
	}

	//最小公倍数を求める
	ll ans = t[1];
	for (int i = 2; i <= n; ++i){
		ans = lcm(ans, t[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
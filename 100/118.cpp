#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int n, a[100010];
const int mod = 1e9 + 7;

ll conbination(int x){
	ll ret = x * (x - 1) * (x - 2) / 6;
	return ret;
}

int main(void){
	cin >> n;
	rep(i, n) cin >> a[i];

	ll cnt[110];
	rep(i, 110) cnt[i] = 0;
	rep(i, n){
		cnt[a[i]]++;
	}

	ll ans = 0;
	for (int i = 1; i <= 100; ++i){
		for (int j = i + 1; j <= 100; ++j){
			for (int k = j + 1; k <= 100; ++k){
				if(cnt[i] != 0 && cnt[j] != 0 && cnt[k] != 0){//すべての長さの竹があるとき
					// (ans += conbination(3) * cnt[i] * cnt[j] * cnt[k]) %= mod;
					(ans += 1 * cnt[i] * cnt[j] * cnt[k]) %= mod;
				}
			}
		}
	}

	printf("%lld\n", ans);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
const ll INF = 1e18;

ll b;
vector<ll> c;
int n;

ll search(ll m){
	ll cnt = 0;
	rep(i, n){
		cnt += abs(m - c[i]);
	}
	return cnt;
}

int main(void){
	cin >> b >> n;
	ll sum = b;
	rep(i, n){
		ll t; cin >> t;
		c.push_back(t);
		sum += t;
	}

	if(n == 1){
		printf("0\n");
		return 0;
	}

	sort(c.begin(), c.end());
	//下凸関数を三分探索
	ll l = c[0];
	ll r = sum / n + 1;
	while(r - l > 3){
		ll m1 = (l * 2 + r) / 3;
		ll m2 = (l + r * 2) / 3;

		if(search(m1) > search(m2)){//左側が高い
			l = m1;
		}else{//右側が高い
			r = m2;
		}
	}

	ll ans = INF;
	for (int i = l; i < r; ++i){
		ans = min(ans, search(i));
	}
	printf("%lld\n", ans);
	return 0;
}